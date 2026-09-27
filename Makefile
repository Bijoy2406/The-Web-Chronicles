# =============================================================================
# The Web Chronicles - native Linux/Ubuntu build
#
#   make            build the game  -> Main/TheWebChronicles
#   make run        build (if needed) and play it
#   make clean      remove build artifacts
#
# Requires: g++ (GCC), FreeGLUT (freeglut3-dev / libglut-dev) and OpenGL
#           (libgl1-mesa-dev / libglu1-mesa-dev):
#           sudo apt install build-essential freeglut3-dev libglu1-mesa-dev
#
# This is the THIRD build target of the project, alongside the original
# Visual Studio / Win32 project (Main.sln + Main/Main.vcxproj) and the
# Emscripten / WebAssembly build (build-web.sh -> web/dist/). All three
# compile the exact same Main/iMain.cpp; the platform differences live
# behind #ifdef __EMSCRIPTEN__ / _WIN32 / __linux__ in Main/iGraphics.h,
# Main/iMain.cpp and Main/score.h.
#
# The Windows project files are NOT touched by this Makefile, and this
# Makefile is NOT used by the Emscripten build.
# =============================================================================

CXX      ?= g++
# -std=c++11 is enough for the game code; the engine headers themselves are
# plain C++ with no C++14+ requirements. -Wall is deliberately light: the
# original source has many pre-existing -Wwrite-strings and
# -Waggressive-loop-optimizations warnings that also fire on MSVC/cl and are
# not introduced by this port, so they are silenced rather than "fixed" (the
# instruction is not to rewrite the game).
CXXFLAGS ?= -std=c++11 -O2 -w
LDLIBS   := -lglut -lGL -lGLU

# Source and the asset tree. The game loads every asset ("Title/...", "r/...",
# "orb/...", ...) with paths relative to the CURRENT WORKING DIRECTORY, so the
# executable must be started from Main/ (see `make run`, and the
# "cwd" of .vscode/launch.json). The binary is intentionally placed inside
# Main/ as well, so "./TheWebChronicles" from Main/ does the right thing.
SRCDIR   := Main
TARGET   := $(SRCDIR)/TheWebChronicles
SOURCES  := $(SRCDIR)/iMain.cpp

.PHONY: all run clean assets-check

all: $(TARGET)

$(TARGET): $(SOURCES) $(wildcard $(SRCDIR)/*.h)
	@echo "==> Compiling $(SOURCES) for Linux (GCC/G++ + FreeGLUT + OpenGL)"
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) $(SOURCES) -o $@ $(LDLIBS)
	@echo "==> Built $@"
	@echo "    Run it with:  cd $(SRCDIR) && ./TheWebChronicles"

run: $(TARGET)
	cd $(SRCDIR) && ./TheWebChronicles

# Optional helper: report any referenced asset that cannot be found, which is
# the first thing to check if sprites or backgrounds come up missing.
assets-check:
	@python3 -c "import re,os,glob; \
refs=set(); \
[f for f in glob.glob('Main/*.h')+glob.glob('Main/*.cpp') for m in re.findall(r'iLoadImage\(\"([^\"]*)\"\)', open(f, errors='replace').read()) for _ in [refs.add(m)]]; \
missing=[m for m in sorted(refs) if not os.path.exists(m.replace(chr(92)+chr(92), '/'))]; \
print(str(len(refs))+' asset references, '+str(len(missing))+' not found:'); \
[print('   ', m) for m in missing]"

clean:
	rm -f $(TARGET)
	rm -rf .vscode-cxx-build
	@echo "==> Cleaned."
