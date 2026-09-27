//
//  Original Author: S. M. Shahriar Nirjon
//
//  Last Modified by: Mohammad Saifur Rahman
//  last modified: December 20, 2015
//
//  Version: 2.0.2012.2015
//


# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//
// ---- Platform split: Windows/Visual Studio build vs. Emscripten/browser build ----
// The original engine used Win32 SetTimer()/glaux for its animation clock and BMP
// loading. Neither exists in a browser. The Windows path below is untouched; the
// __EMSCRIPTEN__ path re-implements iSetTimer/iPauseTimer/iResumeTimer on top of
// GLUT's own glutTimerFunc (which Emscripten's GLUT emulation backs with the
// browser's setTimeout), and iInitialize()/iStart()/glutMainLoop() below need NO
// changes at all: Emscripten's glutMainLoop() already hands control back to the
// browser's event/animation-frame loop internally. Gameplay code (methods1-5.h
// etc.) is completely unaware of any of this.
//
#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
	#include <GL/glut.h>
	#include <GL/gl.h>
	// GLUT_BITMAP_TIMES_ROMAN_24 / GLUT_BITMAP_8_BY_13 (used as iText()'s 4th
	// argument at gameplay call sites) expand to "&glutBitmapTimesRoman24" etc,
	// per the bundled glut.h. Emscripten's GLUT emulation never defines those
	// variables (it has no bitmap-font support at all - see iText() below for
	// the actual replacement), so provide dummy storage purely so the existing
	// call sites still link; iText()'s web implementation ignores the value.
	void* glutBitmapTimesRoman24;
	void* glutBitmap8By13;
	// Emscripten's LEGACY_GL_EMULATION immediate-mode shim only implements
	// GL_POINTS/LINES/LINE_LOOP/LINE_STRIP/TRIANGLES/TRIANGLE_STRIP/
	// TRIANGLE_FAN and (specially cased) GL_QUADS - GL_POLYGON hard-aborts the
	// whole WASM runtime ("unsupported immediate mode 9"), taking the whole
	// game down with it. GL_TRIANGLE_FAN produces an identical filled shape
	// for the convex polygons/circles/ellipses this engine draws with
	// GL_POLYGON (iFilledPolygon/iFilledCircle/iFilledEllipse), so it's a safe
	// drop-in substitute for the web build only.
	#define I_GL_POLYGON_MODE GL_TRIANGLE_FAN
#elif defined(__linux__)
	// Native Linux/Ubuntu build: system FreeGLUT 3.4 + Mesa/OpenGL, the exact
	// same GLUT C API the Windows build uses - only the include paths and the
	// two library names differ. No <windows.h>, no bundled glut.h/glaux.h, no
	// #pragma comment(lib, ...). The real glutBitmapCharacter()/GLUT_BITMAP_*
	// raster fonts DO exist here, so iText() keeps its original implementation
	// (the #else branch further down) and the game text renders identically to
	// Windows. Fixed-function GL_POLYGON is also fully supported, so polygons,
	// circles and ellipses draw with the original GL_POLYGON mode.
	#include <GL/freeglut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
	#define I_GL_POLYGON_MODE GL_POLYGON
#else
	#define I_GL_POLYGON_MODE GL_POLYGON
	#pragma comment(lib, "glut32.lib")
	#pragma comment(lib, "glaux.lib")
	//#pragma comment(lib, "legacy_stdio_definitions.lib")
	#include "glut.h"
	#include <windows.h>
	#include "glaux.h"
#endif

// argc/argv handed to glutInit(). main() fills these in before iInitialize()
// runs; on Linux FreeGLUT *requires* a glutInit() call (the Windows build
// never needed one because Win32 GLUT tolerated its absence), and a
// non-Windows GLUT also legitimately uses argv[0] for the default window
// title. Declared here so the engine layer stays self-contained.
int iGraphicsArgc = 0;
char** iGraphicsArgv = 0;

#ifdef __linux__
//
// ---- Linux asset path resolution ------------------------------------
//
// Windows' filesystem is case-INsensitive, so a reference like
// iLoadImage("buttons\\howtoplay.png") happily opens Main/Buttons/howtoplay.png
// even though the directory on disk is capitalized. Linux filesystems are
// case-sensitive, so that same reference fails. Rather than editing the
// asset references themselves (or renaming any asset, which would break the
// Windows and web builds that resolve the original names), the platform
// layer transparently retries a failed open with a case-insensitive scan of
// the containing directory and uses the on-disk name it finds.
//
// This is a pure fallback: the exact path is always tried first, so if a
// future asset is added with exactly the referenced name it is used as-is.
// Only the directory *entry* names are matched case-insensitively; the
// resolved path is then opened normally by stb_image.
//
// Windows keeps its own (already case-insensitive) behavior untouched, and
// the Emscripten build keeps the plain backslash->slash normalization only.
//
# include <strings.h>
# include <dirent.h>
# include <unistd.h>

// Case-insensitively resolve a single path *component* `name` inside the
// already-resolved directory `dirPath`, writing "dirPath/<actual on-disk
// name>" into `out`. Returns 1 on success, 0 if no entry matches.
static int iLinuxResolveInDir(const char* dirPath, const char* name, char* out, int outSize)
{
	// opendir("") fails with ENOENT on Linux/glibc, but "" is what the very
	// first component of a relative path (e.g. "buttons/howtoplay.png") has as
	// its containing directory - the current working directory. Map it to "."
	// so relative asset paths resolve just like absolute ones.
	DIR* d = opendir((dirPath != 0 && dirPath[0] != '\0') ? dirPath : ".");
	if (d == 0)
		return 0;

	int found = 0;
	struct dirent* ent;
	while ((ent = readdir(d)) != 0)
	{
		if (strcasecmp(ent->d_name, name) == 0)
		{
			int n;
			if (dirPath == 0 || dirPath[0] == '\0')
				n = snprintf(out, outSize, "%s", ent->d_name);   // no leading "./"
			else
				n = snprintf(out, outSize, "%s/%s", dirPath, ent->d_name);
			if (n >= 0 && n < outSize)
				found = 1;
			break;
		}
	}
	closedir(d);
	return found;
}

// Returns 1 and fills `out` with an existing path equivalent to `path` but
// with any component cased differently, or returns 0 if none could be found.
// Handles both the directory part ("buttons\howtoplay.png" -> "Buttons/...")
// and the final filename, resolving component by component so that a
// case-mismatched directory doesn't defeat a correctly-cased filename.
static int iLinuxResolveCaseInsensitive(const char* path, char* out, int outSize)
{
	if (access(path, F_OK) == 0)
	{
		// Exact name already works - never override a correct reference.
		int n = snprintf(out, outSize, "%s", path);
		return (n >= 0 && n < outSize);
	}

	// Copy so the in-place '/' splitting below never writes into the caller's
	// (string-literal) argument.
	char work[512];
	int n = snprintf(work, sizeof(work), "%s", path);
	if (n < 0 || n >= (int)sizeof(work))
		return 0;

	char built[512];
	int builtLen = snprintf(built, sizeof(built), "%s", "");
	if (builtLen < 0)
		return 0;

	char* cursor = work;
	while (cursor != 0 && *cursor != '\0')
	{
		char* slash = strchr(cursor, '/');
		if (slash != 0)
			*slash = '\0';

		if (*cursor == '\0')
		{
			// empty component (leading '/'), just re-append the separator
			if (builtLen + 1 < (int)sizeof(built))
				built[builtLen++] = '/', built[builtLen] = '\0';
		}
		else
		{
			char candidate[512];
			if (!iLinuxResolveInDir(built, cursor, candidate, sizeof(candidate)))
				return 0;               // a component matched nothing at all
			builtLen = snprintf(built, sizeof(built), "%s", candidate);
			if (builtLen < 0 || builtLen >= (int)sizeof(built))
				return 0;
			if (slash != 0)
			{
				if (builtLen + 1 < (int)sizeof(built))
					built[builtLen++] = '/', built[builtLen] = '\0';
			}
		}

		cursor = (slash != 0) ? slash + 1 : 0;
	}

	int m = snprintf(out, outSize, "%s", built);
	return (m >= 0 && m < outSize);
}
#endif // __linux__


#include <time.h>
#include <math.h>

# define STB_IMAGE_IMPLEMENTATION
# include "stb_image.h"

int iScreenHeight, iScreenWidth;
int iMouseX, iMouseY;
int ifft = 0;
void (*iAnimFunction[10])(void)=
{	0};
int iAnimCount = 0;
int iAnimDelays[10];
int iAnimPause[10];

void iDraw();
void iKeyboard(unsigned char);
void iSpecialKeyboard(unsigned char);
void iMouseMove(int, int);
void iPassiveMouse(int, int);
void iMouse(int button, int state, int x, int y);

#ifdef __EMSCRIPTEN__
	//
	// Browser build: the game advances much of its state once per iDraw() call
	// (standCounter/rhinoStandCounter/... action durations such as "punch ends
	// after 200 frames"), and those counts were tuned against the original
	// Windows build's uncapped GLUT idle loop, which ran iDraw() several hundred
	// times a second. The browser only presents a frame per requestAnimationFrame
	// (~60 Hz), so displayFF() below runs extra logic-only iDraw() passes to keep
	// the original update rate. During those passes this flag turns every
	// drawing primitive into a no-op; nothing else in iDraw() is affected.
	//
	int iEmSkipRender = 0;
	#define I_EM_SKIP_IF_LOGIC_ONLY() do { if (iEmSkipRender) return; } while (0)
#else
	#define I_EM_SKIP_IF_LOGIC_ONLY() do { } while (0)
#endif

#ifdef __EMSCRIPTEN__
	//
	// Browser build: there is no Win32 SetTimer()/KillTimer multi-callback timer
	// queue. Emscripten's GLUT emulation does implement the standard GLUT
	// glutTimerFunc(msec, callback, value) API (backed by the browser's own
	// setTimeout under the hood), so each animation slot is re-armed as a
	// self-rescheduling glutTimerFunc callback. This reproduces each timer's
	// original independent cadence (e.g. iSetTimer(120, stan) still fires every
	// ~120ms) without needing a direct SetTimer/KillTimer equivalent.
	//
	void iEmTimerTick(int slot)
	{
		if (!iAnimPause[slot] && iAnimFunction[slot])
			iAnimFunction[slot]();
		// Re-arm regardless of pause state so a later iResumeTimer() keeps working.
		glutTimerFunc(iAnimDelays[slot], iEmTimerTick, slot);
	}
#elif defined(__linux__)
	//
	// Native Linux build: identical mechanism to the browser one above, because
	// there is no Win32 message pump here either. FreeGLUT implements the
	// standard glutTimerFunc(msec, callback, value), so each animation slot is a
	// self-rescheduling timer callback that preserves the original independent
	// per-timer cadence (iSetTimer(120, stan) still fires every ~120ms). Keeping
	// the callbacks on the GLUT main loop - rather than spawning threads or
	// restructuring into a new game loop - means the original gameplay timing
	// and the original iDraw()-driven update model stay exactly as they were.
	//
	void iLinuxTimerTick(int slot)
	{
		if (!iAnimPause[slot] && iAnimFunction[slot])
			iAnimFunction[slot]();
		// Re-arm regardless of pause state so a later iResumeTimer() keeps working.
		glutTimerFunc(iAnimDelays[slot], iLinuxTimerTick, slot);
	}
#else
	static void __stdcall iA0(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[0])
			iAnimFunction[0]();
	}
	static void __stdcall iA1(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[1])
			iAnimFunction[1]();
	}
	static void __stdcall iA2(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[2])
			iAnimFunction[2]();
	}
	static void __stdcall iA3(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[3])
			iAnimFunction[3]();
	}
	static void __stdcall iA4(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[4])
			iAnimFunction[4]();
	}
	static void __stdcall iA5(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[5])
			iAnimFunction[5]();
	}
	static void __stdcall iA6(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[6])
			iAnimFunction[6]();
	}
	static void __stdcall iA7(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[7])
			iAnimFunction[7]();
	}
	static void __stdcall iA8(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[8])
			iAnimFunction[8]();
	}
	static void __stdcall iA9(HWND, unsigned int, unsigned int, unsigned long)
	{
		if (!iAnimPause[9])
			iAnimFunction[9]();
	}
#endif

int iSetTimer(int msec, void (*f)(void))
{
	int i = iAnimCount;

	if (iAnimCount >= 10)
	{
		printf("Error: Maximum number of already timer used.\n");
		return -1;
	}

	iAnimFunction[i] = f;
	iAnimDelays[i] = msec;
	iAnimPause[i] = 0;

#ifdef __EMSCRIPTEN__
	glutTimerFunc(msec, iEmTimerTick, i);
#elif defined(__linux__)
	glutTimerFunc(msec, iLinuxTimerTick, i);
#else
	if (iAnimCount == 0)
		SetTimer(0, 0, msec, iA0);
	if (iAnimCount == 1)
		SetTimer(0, 0, msec, iA1);
	if (iAnimCount == 2)
		SetTimer(0, 0, msec, iA2);
	if (iAnimCount == 3)
		SetTimer(0, 0, msec, iA3);
	if (iAnimCount == 4)
		SetTimer(0, 0, msec, iA4);

	if (iAnimCount == 5)
		SetTimer(0, 0, msec, iA5);
	if (iAnimCount == 6)
		SetTimer(0, 0, msec, iA6);
	if (iAnimCount == 7)
		SetTimer(0, 0, msec, iA7);
	if (iAnimCount == 8)
		SetTimer(0, 0, msec, iA8);
	if (iAnimCount == 9)
		SetTimer(0, 0, msec, iA9);
#endif
	iAnimCount++;

	return iAnimCount - 1;
}

void iPauseTimer(int index)
{
	if (index >= 0 && index < iAnimCount)
	{
		iAnimPause[index] = 1;
	}
}

void iResumeTimer(int index)
{
	if (index >= 0 && index < iAnimCount)
	{
		iAnimPause[index] = 0;
	}
}

//
// Puts a BMP image on screen
//
// parameters:
//  x - x coordinate
//  y - y coordinate
//  filename - name of the BMP file
//  ignoreColor - A specified color that should not be rendered. If you have an
//                image strip that should be rendered on top of another back
//                ground image, then the background of the image strip should
//                not get rendered. Use the background color of the image strip
//                in ignoreColor parameter. Then the strip's background does
//                not get rendered.
//
//                To disable this feature, put -1 in this parameter
//
#if defined(_WIN32) || (!defined(__EMSCRIPTEN__) && !defined(__linux__))
// glaux-based BMP loader: relies on Win32 AUX_RGBImageRec/auxDIBImageLoad,
// which has no browser or Linux equivalent (glaux is a Windows-only auxiliary
// library and is not part of the FreeGLUT/GLU packages on Ubuntu). Not called
// anywhere in the actual game (only in unused demo .cpp files that aren't part
// of the build), so it is simply left out of the web and Linux builds rather
// than ported. The real image pipeline used by the game is iLoadImage()/
// iShowImage() below, which is stb_image based and already portable.
void iShowBMP2(int x, int y, char filename[], int ignoreColor)
{
	AUX_RGBImageRec *TextureImage;
	TextureImage = auxDIBImageLoad(filename);

	int i, j;
	int width = TextureImage->sizeX;
	int height = TextureImage->sizeY;
	int nPixels = width * height;
	int *rgPixels = new int[nPixels];



	for (i = 0, j = 0; i < nPixels; i++, j += 3)
	{
		int rgb = 0;
		for (int k = 2; k >= 0; k--)
		{
			rgb = ((rgb << 8) | TextureImage->data[j + k]);
		}

		rgPixels[i] = (rgb == ignoreColor) ? 0 : 255;
		rgPixels[i] = ((rgPixels[i] << 24) | rgb);
	}

	glRasterPos2f(x, y);
	glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, rgPixels);

	delete[] rgPixels;
	free(TextureImage->data);
	free(TextureImage);
}

void iShowBMP(int x, int y, char filename[])
{
	iShowBMP2(x, y, filename, -1 /* ignoreColor */);
}
#endif

unsigned int iLoadImage(char filename[])
{
	int width = 0, height = 0, bpp = 0;

	unsigned int texture;

#if defined(__EMSCRIPTEN__) || defined(__linux__)
	// Web *and* Linux builds: asset paths throughout methods1-5.h/gover.h are
	// written with backslashes (e.g. "bgren2\\tile000.png"), which is how
	// Windows resolves a relative subfolder path but is NOT a path separator
	// on Linux or on the browser's virtual filesystem (MEMFS is case-sensitive
	// and slash-only; a backslash is just an ordinary filename character
	// there). Normalize here, at the single load choke point, instead of
	// touching the ~500 call sites across the gameplay headers.
	char normalized[512];
	int k;
	for (k = 0; filename[k] != '\0' && k < 510; k++)
		normalized[k] = (filename[k] == '\\') ? '/' : filename[k];
	normalized[k] = '\0';
	unsigned char* data = stbi_load(normalized, &width, &height, &bpp, 4);
#ifdef __linux__
	// Windows resolves some of these references case-insensitively (e.g.
	// "buttons\howtoplay.png" -> the on-disk "Buttons/"); a case-sensitive
	// Linux filesystem does not. Retry through the case-insensitive resolver
	// (see iLinuxResolveCaseInsensitive above) before giving up. Purely a
	// fallback: the exact path is always attempted first.
	if (data == 0)
	{
		char resolved[512];
		if (iLinuxResolveCaseInsensitive(normalized, resolved, sizeof(resolved)))
			data = stbi_load(resolved, &width, &height, &bpp, 4);
	}
#endif
#else
	BYTE* data(0);
	data = stbi_load(filename, &width, &height, &bpp, 4);
#endif

	//glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			width, height,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			data);
	}
	else
	{
		// A missing asset would otherwise upload a garbage-sized texture from
		// the (now zero-initialized) width/height and silently draw a black
		// rectangle, which is very hard to diagnose. Report it and still hand
		// back a valid texture id so the rest of the frame keeps rendering.
		printf("iLoadImage: FAILED to load '%s' (check the working directory and the filename's case)\n",
#if defined(__EMSCRIPTEN__) || defined(__linux__)
			normalized
#else
			filename
#endif
		);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	}

	stbi_image_free(data);

	return texture;
}

void iShowImage(int x, int y, int width, int height, unsigned int texture)
{
	I_EM_SKIP_IF_LOGIC_ONLY();

	//unsigned int texture;


	//int width, height, bpp;
	/*
	BYTE* data(0);
	data = stbi_load(filename, &width, &height, &bpp, 4);


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
			     GL_RGBA,
				 width, height,
				 0,
				 GL_RGBA,
				 GL_UNSIGNED_BYTE,
				 data);

	stbi_image_free(data);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	*/

	//width = 100;
	//height = 100;
	glEnable(GL_TEXTURE_2D);



	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

#ifdef __EMSCRIPTEN__
	// Nearly every asset in this game (backgrounds, sprite sheets, title art)
	// has non-power-of-two pixel dimensions (e.g. spidermanTitle.png is
	// 2615x1080). WebGL1 requires GL_CLAMP_TO_EDGE wrap (and no mipmaps, which
	// this already doesn't use) for NPOT textures; GL_REPEAT on an NPOT texture
	// makes it "incomplete" per spec, and every sample from it silently comes
	// back (0,0,0,0) - full transparent black - which is exactly what made the
	// entire game render as a black screen before this fix. iShowImage always
	// draws a single (0,0)-(1,1) textured quad anyway (see below), so nothing
	// ever actually needed wrapping/repeating in the first place.
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
#else
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
#endif

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

#ifdef __EMSCRIPTEN__
	// Emscripten's LEGACY_GL_EMULATION glTexEnvf() is a no-op stub (it just
	// warns "TODO" and does nothing - see libglemu.js), so the GL_REPLACE call
	// just above never actually takes effect there; the fixed-function shader
	// stays in its default GL_MODULATE mode (texture color x current vertex
	// color) for the whole web build. iText()/iSetColor() calls elsewhere
	// (e.g. iSetColor(0,0,0) before drawing black score text) leave the GL
	// color state black, and since nothing here ever resets it, the NEXT
	// iShowImage() call - e.g. drawing the player sprite - got its texture
	// modulated by black, i.e. rendered fully invisible against the black
	// iClear() background. This is why player/enemy sprites never appeared
	// even though everything upstream (texture load, draw call, coordinates)
	// was working correctly. Forcing white here every time makes GL_MODULATE
	// behave identically to the GL_REPLACE the original Windows build actually
	// gets, without touching any of the hundreds of iSetColor()/iShowImage()
	// call sites in the gameplay code.
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
#endif

	//glPushMatrix();
	//glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

		glTexCoord2f(0, 1);
		glVertex2f(x, y);

		glTexCoord2f(1, 1);
		glVertex2f(x + width, y);

		glTexCoord2f(1, 0);
		glVertex2f(x + width, y+height);

		glTexCoord2f(0, 0);
		glVertex2f(x, y + height);

	glEnd();
	//glPopMatrix();

	glDisable(GL_TEXTURE_2D);

}



void iGetPixelColor(int cursorX, int cursorY, int rgb[])
{
	GLubyte pixel[3];
	glReadPixels(cursorX, cursorY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, (void *) pixel);

	rgb[0] = pixel[0];
	rgb[1] = pixel[1];
	rgb[2] = pixel[2];

	//printf("%d %d %d\n",pixel[0],pixel[1],pixel[2]);
}

#ifdef __EMSCRIPTEN__
	//
	// Browser build: modern Emscripten's GLUT emulation does not implement
	// glutBitmapCharacter()/the GLUT_BITMAP_* raster fonts at all (no JS-side
	// symbol exists for them, unlike glBegin/glVertex/etc which LEGACY_GL_EMULATION
	// does provide). iText() is only ever used for score/name/prompt text, never
	// gameplay pixels, so rather than changing any of the ~20 iText() call sites
	// across iMain.cpp, this replaces its *implementation* with a tiny built-in
	// 5x7 bitmap font drawn as GL_POINTS quads at the same (x, y) baseline the
	// original glRasterPos3d/glutBitmapCharacter call used. One font size only
	// (the "font" parameter is accepted for call-site compatibility but unused).
	//
	static const unsigned char iFont5x7[96][5] = {
		{0x00,0x00,0x00,0x00,0x00}, {0x00,0x00,0x5F,0x00,0x00}, {0x00,0x07,0x00,0x07,0x00}, {0x14,0x7F,0x14,0x7F,0x14},
		{0x24,0x2A,0x7F,0x2A,0x12}, {0x23,0x13,0x08,0x64,0x62}, {0x36,0x49,0x56,0x20,0x50}, {0x00,0x08,0x07,0x03,0x00},
		{0x00,0x1C,0x22,0x41,0x00}, {0x00,0x41,0x22,0x1C,0x00}, {0x2A,0x1C,0x7F,0x1C,0x2A}, {0x08,0x08,0x3E,0x08,0x08},
		{0x00,0x80,0x70,0x30,0x00}, {0x08,0x08,0x08,0x08,0x08}, {0x00,0x00,0x60,0x60,0x00}, {0x20,0x10,0x08,0x04,0x02},
		{0x3E,0x51,0x49,0x45,0x3E}, {0x00,0x42,0x7F,0x40,0x00}, {0x72,0x49,0x49,0x49,0x46}, {0x21,0x41,0x49,0x4D,0x33},
		{0x18,0x14,0x12,0x7F,0x10}, {0x27,0x45,0x45,0x45,0x39}, {0x3C,0x4A,0x49,0x49,0x30}, {0x01,0x71,0x09,0x05,0x03},
		{0x36,0x49,0x49,0x49,0x36}, {0x06,0x49,0x49,0x29,0x1E}, {0x00,0x36,0x36,0x00,0x00}, {0x00,0x56,0x36,0x00,0x00},
		{0x08,0x14,0x22,0x41,0x00}, {0x14,0x14,0x14,0x14,0x14}, {0x00,0x41,0x22,0x14,0x08}, {0x02,0x01,0x59,0x09,0x06},
		{0x3E,0x41,0x5D,0x59,0x4E}, {0x7C,0x12,0x11,0x12,0x7C}, {0x7F,0x49,0x49,0x49,0x36}, {0x3E,0x41,0x41,0x41,0x22},
		{0x7F,0x41,0x41,0x41,0x3E}, {0x7F,0x49,0x49,0x49,0x41}, {0x7F,0x09,0x09,0x09,0x01}, {0x3E,0x41,0x49,0x49,0x7A},
		{0x7F,0x08,0x08,0x08,0x7F}, {0x00,0x41,0x7F,0x41,0x00}, {0x20,0x40,0x41,0x3F,0x01}, {0x7F,0x08,0x14,0x22,0x41},
		{0x7F,0x40,0x40,0x40,0x40}, {0x7F,0x02,0x1C,0x02,0x7F}, {0x7F,0x04,0x08,0x10,0x7F}, {0x3E,0x41,0x41,0x41,0x3E},
		{0x7F,0x09,0x09,0x09,0x06}, {0x3E,0x41,0x51,0x21,0x5E}, {0x7F,0x09,0x19,0x29,0x46}, {0x26,0x49,0x49,0x49,0x32},
		{0x01,0x01,0x7F,0x01,0x01}, {0x3F,0x40,0x40,0x40,0x3F}, {0x1F,0x20,0x40,0x20,0x1F}, {0x7F,0x20,0x18,0x20,0x7F},
		{0x63,0x14,0x08,0x14,0x63}, {0x03,0x04,0x78,0x04,0x03}, {0x61,0x51,0x49,0x45,0x43}, {0x00,0x7F,0x41,0x41,0x00},
		{0x02,0x04,0x08,0x10,0x20}, {0x00,0x41,0x41,0x7F,0x00}, {0x04,0x02,0x01,0x02,0x04}, {0x40,0x40,0x40,0x40,0x40},
		{0x00,0x01,0x02,0x04,0x00}, {0x20,0x54,0x54,0x54,0x78}, {0x7F,0x48,0x44,0x44,0x38}, {0x38,0x44,0x44,0x44,0x20},
		{0x38,0x44,0x44,0x48,0x7F}, {0x38,0x54,0x54,0x54,0x18}, {0x08,0x7E,0x09,0x01,0x02}, {0x0C,0x52,0x52,0x52,0x3E},
		{0x7F,0x08,0x04,0x04,0x78}, {0x00,0x44,0x7D,0x40,0x00}, {0x20,0x40,0x44,0x3D,0x00}, {0x7F,0x10,0x28,0x44,0x00},
		{0x00,0x41,0x7F,0x40,0x00}, {0x7C,0x04,0x18,0x04,0x78}, {0x7C,0x08,0x04,0x04,0x78}, {0x38,0x44,0x44,0x44,0x38},
		{0x7C,0x14,0x14,0x14,0x08}, {0x08,0x14,0x14,0x18,0x7C}, {0x7C,0x08,0x04,0x04,0x08}, {0x48,0x54,0x54,0x54,0x24},
		{0x04,0x04,0x3F,0x44,0x24}, {0x3C,0x40,0x40,0x20,0x7C}, {0x1C,0x20,0x40,0x20,0x1C}, {0x3C,0x40,0x30,0x40,0x3C},
		{0x44,0x28,0x10,0x28,0x44}, {0x0C,0x50,0x50,0x50,0x3C}, {0x44,0x64,0x54,0x4C,0x44}, {0x00,0x08,0x36,0x41,0x00},
		{0x00,0x00,0x7F,0x00,0x00}, {0x00,0x41,0x36,0x08,0x00}, {0x08,0x04,0x08,0x10,0x08}, {0x00,0x00,0x00,0x00,0x00}
	};

	void iEmDrawGlyph(double x, double y, unsigned char c)
	{
		if (c < 32 || c > 127) c = 32;
		const unsigned char *col = iFont5x7[c - 32];
		glBegin(GL_QUADS);
		for (int cx = 0; cx < 5; cx++)
		{
			for (int cy = 0; cy < 7; cy++)
			{
				if (col[cx] & (1 << cy))
				{
					double px = x + cx * 2;
					double py = y + (6 - cy) * 2;
					glVertex2f(px, py);
					glVertex2f(px + 2, py);
					glVertex2f(px + 2, py + 2);
					glVertex2f(px, py + 2);
				}
			}
		}
		glEnd();
	}

	void iText(GLdouble x, GLdouble y, char *str, void* font = 0)
	{
		I_EM_SKIP_IF_LOGIC_ONLY();
		int i;
		double cursor = x;
		for (i = 0; str[i]; i++)
		{
			iEmDrawGlyph(cursor, y, (unsigned char)str[i]);
			cursor += 12;
		}
	}
#else
void iText(GLdouble x, GLdouble y, char *str, void* font = GLUT_BITMAP_8_BY_13)
{
	glRasterPos3d(x, y, 0);
	int i;
	for (i = 0; str[i]; i++)
	{
		glutBitmapCharacter(font, str[i]); //,GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_24
	}
}
#endif

void iPoint(double x, double y, int size = 0)
{
	I_EM_SKIP_IF_LOGIC_ONLY();
	int i, j;
	glBegin (GL_POINTS);
	glVertex2f(x, y);
	for (i = x - size; i < x + size; i++)
	{
		for (j = y - size; j < y + size; j++)
		{
			glVertex2f(i, j);
		}
	}
	glEnd();
}

void iLine(double x1, double y1, double x2, double y2)
{
	I_EM_SKIP_IF_LOGIC_ONLY();
	glBegin (GL_LINE_STRIP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void iFilledPolygon(double x[], double y[], int n)
{
	I_EM_SKIP_IF_LOGIC_ONLY();
	int i;
	if (n < 3)
		return;
	glBegin (I_GL_POLYGON_MODE);
	for (i = 0; i < n; i++)
	{
		glVertex2f(x[i], y[i]);
	}
	glEnd();
}

void iPolygon(double x[], double y[], int n)
{
	int i;
	if (n < 3)
		return;
	glBegin (GL_LINE_STRIP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(x[i], y[i]);
	}
	glVertex2f(x[0], y[0]);
	glEnd();
}

void iRectangle(double left, double bottom, double dx, double dy)
{
	double x1, y1, x2, y2;

	x1 = left;
	y1 = bottom;
	x2 = x1 + dx;
	y2 = y1 + dy;

	iLine(x1, y1, x2, y1);
	iLine(x2, y1, x2, y2);
	iLine(x2, y2, x1, y2);
	iLine(x1, y2, x1, y1);
}

void iFilledRectangle(double left, double bottom, double dx, double dy)
{
	double xx[4], yy[4];
	double x1, y1, x2, y2;

	x1 = left;
	y1 = bottom;
	x2 = x1 + dx;
	y2 = y1 + dy;

	xx[0] = x1;
	yy[0] = y1;
	xx[1] = x2;
	yy[1] = y1;
	xx[2] = x2;
	yy[2] = y2;
	xx[3] = x1;
	yy[3] = y2;

	iFilledPolygon(xx, yy, 4);
}

void iFilledCircle(double x, double y, double r, int slices = 30)
{
	I_EM_SKIP_IF_LOGIC_ONLY();
	double t, PI = acos(-1.0), dt, x1, y1, xp, yp;
	dt = 2 * PI / slices;
	xp = x + r;
	yp = y;
	glBegin (I_GL_POLYGON_MODE);
	for (t = 0; t <= 2 * PI; t += dt)
	{
		x1 = x + r * cos(t);
		y1 = y + r * sin(t);

		glVertex2f(xp, yp);
		xp = x1;
		yp = y1;
	}
	glEnd();
}

void iCircle(double x, double y, double r, int slices = 30)
{
	double t, PI = acos(-1.0), dt, x1, y1, xp, yp;
	dt = 2 * PI / slices;
	xp = x + r;
	yp = y;
	for (t = 0; t <= 2 * PI; t += dt)
	{
		x1 = x + r * cos(t);
		y1 = y + r * sin(t);
		iLine(xp, yp, x1, y1);
		xp = x1;
		yp = y1;
	}
}

void iEllipse(double x, double y, double a, double b, int slices = 40)
{
	double t, PI = acos(-1.0), dt, x1, y1, xp, yp;
	dt = 2 * PI / slices;
	xp = x + a;
	yp = y;
	for (t = 0; t <= 2 * PI; t += dt)
	{
		x1 = x + a * cos(t);
		y1 = y + b * sin(t);
		iLine(xp, yp, x1, y1);
		xp = x1;
		yp = y1;
	}
}

void iFilledEllipse(double x, double y, double a, double b, int slices = 40)
{
	I_EM_SKIP_IF_LOGIC_ONLY();
	double t, PI = acos(-1.0), dt, x1, y1, xp, yp;
	dt = 2 * PI / slices;
	xp = x + a;
	yp = y;
	glBegin (I_GL_POLYGON_MODE);
	for (t = 0; t <= 2 * PI; t += dt)
	{
		x1 = x + a * cos(t);
		y1 = y + b * sin(t);
		glVertex2f(xp, yp);
		xp = x1;
		yp = y1;
	}
	glEnd();
}

//
// Rotates the co-ordinate system
// Parameters:
//  (x, y) - The pivot point for rotation
//  degree - degree of rotation
//
// After calling iRotate(), evrey subsequent rendering will
// happen in rotated fashion. To stop rotation of subsequent rendering,
// call iUnRotate(). Typical call pattern would be:
//      iRotate();
//      Render your objects, that you want rendered as rotated
//      iUnRotate();
//
void iRotate(double x, double y, double degree)
{
	// push the current matrix stack
	glPushMatrix();

	//
	// The below steps take effect in reverse order
	//

	// step 3: undo the translation
	glTranslatef(x, y, 0.0);

	// step 2: rotate the co-ordinate system across z-axis
	glRotatef(degree, 0, 0, 1.0);

	// step 1: translate the origin to (x, y)
	glTranslatef(-x, -y, 0.0);
}

void iUnRotate()
{
	glPopMatrix();
}

void iSetColor(double r, double g, double b)
{
	double mmx;
	mmx = r;
	if (g > mmx)
		mmx = g;
	if (b > mmx)
		mmx = b;
	mmx = 255;
	if (mmx > 0)
	{
		r /= mmx;
		g /= mmx;
		b /= mmx;
	}
	glColor3f(r, g, b);
}

void iDelay(int sec)
{
	int t1, t2;
	t1 = time(0);
	while (1)
	{
		t2 = time(0);
		if (t2 - t1 >= sec)
			break;
	}
}

void iDelayMS(int msec)
{
	clock_t end;
	end = clock() + msec * CLOCKS_PER_SEC / 1000;
	while (end > clock())
		;
}

void iClear()
{
	I_EM_SKIP_IF_LOGIC_ONLY();
	glClear (GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glClearColor(0, 0, 0, 0);
	glFlush();
}

// TEMP PROBE: forward decls (iGraphics.h precedes the game headers)

#ifdef __EMSCRIPTEN__
	// Logic passes per second the original Windows build ran iDraw() at.
	// Derived from the game's own tuning: the Rhino's punch lasts 350 frames
	// while its 7-frame punch animation (100 ms timer) takes 0.7 s, and
	// Spider-Man's kick lasts 200 frames against a 4-frame (0.4 s) animation;
	// both work out to ~500 frames per second.
	#define I_EM_ORIGINAL_FPS 500.0

	// Runs iDraw() at a fixed I_EM_ORIGINAL_FPS regardless of the display's
	// refresh rate: every pass but the last is logic-only (drawing skipped),
	// and the last one renders the frame that gets presented.
	void iEmRunDrawPasses(void)
	{
		static double lastMs = 0.0, pendingMs = 0.0;
		const double stepMs = 1000.0 / I_EM_ORIGINAL_FPS;
		double now = emscripten_get_now();
		if (lastMs == 0.0)
			lastMs = now - stepMs;
		pendingMs += now - lastMs;
		lastMs = now;
		// A backgrounded tab pauses requestAnimationFrame; don't replay the
		// whole gap in one burst when it comes back.
		if (pendingMs > 250.0)
			pendingMs = 250.0;

		int passes = (int)(pendingMs / stepMs);
		if (passes < 1)
			passes = 1;
		pendingMs -= passes * stepMs;
		if (pendingMs < 0.0)
			pendingMs = 0.0;

		iEmSkipRender = 1;
		for (int i = 1; i < passes; i++)
			iDraw();
		iEmSkipRender = 0;
		iDraw();
	}
#endif

void displayFF(void)
{
	static int _f=0;
#ifdef __EMSCRIPTEN__
	iEmRunDrawPasses();
#else
	iDraw();
#endif
	_f++;
	glutSwapBuffers();
}

void animFF(void)
{
	if (ifft == 0)
	{
		ifft = 1;
		iClear();
	}
	glutPostRedisplay();
}

void keyboardHandler1FF(unsigned char key, int x, int y)
{
	iKeyboard(key);
	glutPostRedisplay();
}
void keyboardHandler2FF(int key, int x, int y)
{
	iSpecialKeyboard(key);
	glutPostRedisplay();
}

void mouseMoveHandlerFF(int mx, int my)
{
	iMouseX = mx;
	iMouseY = iScreenHeight - my;
	iMouseMove(iMouseX, iMouseY);

	glFlush();
}


void passiveMouseHandlerFF(int mx, int my)
{
	iMouseX = mx;
	iMouseY = iScreenHeight - my;
	iPassiveMouse(iMouseX, iMouseY);

	glFlush();
}
void mouseHandlerFF(int button, int state, int x, int y)
{
	iMouseX = x;
	iMouseY = iScreenHeight - y;

	iMouse(button, state, iMouseX, iMouseY);

	glFlush();
}

void iInitialize(int width = 500, int height = 500, char *title = "iGraphics")
{
	iScreenHeight = height;
	iScreenWidth = width;

#if defined(__EMSCRIPTEN__) || defined(__linux__)
	// Emscripten's GLUT emulation and FreeGLUT both register ALL of their
	// event listeners / X11 resources only when glutInit() is called, and
	// FreeGLUT additionally aborts with "glutInit() called before ..." style
	// errors if it is never called at all. The original Windows game never
	// called it (Win32 GLUT tolerated that), so on both the web build and this
	// Linux build rendering worked but every keyboard and mouse control was
	// silently dead - no listener was ever attached to receive them. This is
	// the missing call. main() stores the real argc/argv into iGraphicsArgc /
	// iGraphicsArgv before iInitialize() runs; fall back to a synthetic argv
	// if a caller (e.g. one of the demo .cpp files) forgets to.
	if (iGraphicsArgc > 0 && iGraphicsArgv)
	{
		glutInit(&iGraphicsArgc, iGraphicsArgv);
	}
	else
	{
		int iDummyArgc = 1;
		static char iDummyArg0[] = "game";
		static char* iDummyArgv[] = { iDummyArg0, 0 };
		glutInit(&iDummyArgc, iDummyArgv);
	}
#endif

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(10, 10);
	glutCreateWindow(title);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
	//glOrtho(-100.0 , 100.0 , -100.0 , 100.0 , -1.0 , 1.0) ;
	//SetTimer(0, 0, 10, timer_proc);



}

void iStart()
{
	iClear();

	glutDisplayFunc(displayFF);
	glutKeyboardFunc(keyboardHandler1FF); //normal
	glutSpecialFunc(keyboardHandler2FF); //special keys
	glutMouseFunc(mouseHandlerFF);
	glutMotionFunc(mouseMoveHandlerFF);
	glutPassiveMotionFunc(passiveMouseHandlerFF);
	glutIdleFunc(animFF);

	//
	// Setup Alpha channel testing.
	// If alpha value is greater than 0, then those
	// pixels will be rendered. Otherwise, they would not be rendered
	//
	glAlphaFunc(GL_GREATER, 0.0f);
	glEnable(GL_ALPHA_TEST);
	glutMainLoop();
}
