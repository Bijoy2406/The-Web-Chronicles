<div align="center">

# 🕸️ The Web Chronicles

### *"With Great Power, Comes Great Responsibility"*

A **Spider-Man** inspired 2D action game built with C++ and the iGraphics library.  
Battle through six action-packed levels, face iconic villains, and swing your way to victory.

[![Language](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Graphics](https://img.shields.io/badge/Graphics-OpenGL%20%2F%20GLUT-green?style=for-the-badge&logo=opengl&logoColor=white)](https://www.opengl.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-purple?style=for-the-badge&logo=visualstudio&logoColor=white)](https://visualstudio.microsoft.com/)

---

▶️ **[Watch the Gameplay Demo](https://drive.google.com/file/d/1ejSwHsgYRFUjzSDvxeY05oJSMSG1NY-i/view?usp=sharing)**

</div>

---

## 📖 About

**The Web Chronicles** is a 2D side-scrolling action game developed using the **iGraphics** library (an OpenGL/GLUT wrapper). Players take on the role of different Spider-Man characters, traversing through six increasingly challenging levels filled with enemies, bosses, and collectibles. The game features sprite-based animations, a persistent high-score system, and multiple combat mechanics.

---

## ✨ Features

| Feature | Description |
|---|---|
| 🎮 **6 Unique Levels** | Progress through increasingly difficult stages, each with distinct environments and enemies |
| 🦸 **3 Playable Characters** | Play as Peter Parker, Miles Morales, or Miguel O'Hara (Spider-Man 2099) |
| 👊 **Combat System** | Punch, kick, block, and unleash devastating ultimate attacks |
| 🏆 **High Score Leaderboard** | Persistent top-5 leaderboard saved to disk — compete for the highest score |
| 🔮 **Collectible Orbs** | Gather Health, Dimensional, and Ultimate orbs to power up your hero |
| 🕷️ **Web Shooting** | Fire webs to deal damage from a distance |
| 💀 **Boss Battles** | Face off against Rhino, Kraven the Hunter, and Mysterio |
| 🎬 **Animated Sequences** | Sprite-based character and death animations for an immersive feel |

---

## 🎯 Gameplay

### Levels Overview

| Level | Type | Objective |
|:---:|---|---|
| 1 | Street Brawl | Defeat thugs and fill the Dimensional Bar to progress |
| 2 | Boss Fight — **Rhino** | Deplete Rhino's health bar to survive |
| 3 | Street Brawl | Battle waves of enemies in a new environment |
| 4 | Boss Fight — **Kraven** | Outsmart and defeat Kraven the Hunter |
| 5 | Street Brawl | Final gauntlet of enemies |
| 6 | Final Boss — **Mysterio** | Defeat Mysterio to complete the game |

### Characters

| Character | Description |
|---|---|
| 🔴 **Peter Parker** | The classic Spider-Man — balanced stats and web-slinging abilities |
| ⚫ **Miles Morales** | The next-gen Spider-Man with a unique fighting style |
| 🔵 **Miguel O'Hara** | Spider-Man 2099 — futuristic combat from another dimension |

---

## 🎮 Controls

| Key | Action |
|:---:|---|
| `A` | Move Left |
| `D` | Move Right |
| `Space` | Jump |
| `1` | Punch |
| `2` | Kick |
| `3` | Ultimate Attack *(requires full Ultimate Bar)* |
| `4` | Block |
| `X` | Fire enemy bullets |
| `Enter` | Confirm / Start Game |
| `Z` | Return to Menu |
| `Insert` | Select menu button |
| `↑` / `↓` | Navigate menu buttons |

---

## 🏗️ Project Structure

```
The-Web-Chronicles/
├── Main/
│   ├── iMain.cpp            # Main game loop, rendering, input handling
│   ├── iGraphics.h          # OpenGL/GLUT graphics wrapper library
│   ├── score.h              # High score system (save/load/sort)
│   ├── gover.h              # Game over / death animation sequence
│   ├── variables1-5.h       # Game state variables for each level
│   ├── methods1-5.h         # Game logic & mechanics for each level
│   ├── stb_image.h          # PNG/image loading library
│   ├── bitmap_loader.h      # BMP image loader
│   ├── GLUT.H / GLUT32.*    # GLUT library binaries
│   ├── highScore.bin        # Persistent high score data
│   ├── Buttons/             # Menu button sprites
│   ├── Title/               # Title screen assets
│   ├── p1-p4/               # Player sprite sheets
│   ├── punch/, kick/, jump/ # Combat animation sprites
│   ├── die/                 # Death animation frames
│   ├── fire/                # Fire/projectile sprites
│   ├── orb/, redcoin/       # Collectible sprites
│   ├── web/                 # Web projectile sprites
│   └── ...                  # Background and UI assets
├── Main.sln                 # Visual Studio Solution file
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- **Windows OS**
- **Microsoft Visual Studio** (2012 or later recommended)
- No additional dependencies needed — GLUT and OpenGL libraries are bundled in the project

### Installation & Running

1. **Clone the repository**
   ```bash
   git clone https://github.com/XGNoir95/The-Web-Chronicles.git
   ```

2. **Open the solution**
   - Double-click `Main.sln` to open in Visual Studio

3. **Build & Run**
   - Set the build configuration to **Debug** (x86)
   - Press `F5` or click **Local Windows Debugger** to build and run

> [!NOTE]
> Make sure the working directory is set to the `Main/` folder so that all sprite and asset paths resolve correctly.

---

## 🌐 Playing in the Browser

The Windows/Visual Studio build above is untouched and still works exactly as
before. Alongside it, this repo also builds to WebAssembly so the game runs
directly in a desktop browser tab — no install, no plugin.

### 1. Install Emscripten (one-time)

The Emscripten SDK is *not* committed to this repo. Clone it as a sibling
directory (one level above this repo) and activate the latest release:

```bash
git clone https://github.com/emscripten-core/emsdk.git ../emsdk
cd ../emsdk
./emsdk install latest
./emsdk activate latest
cd ../The-Web-Chronicles
```

> **Windows note:** if `python` on your PATH is the Microsoft Store stub
> ("Python was not found..."), `emsdk_env.sh` in this repo works around that
> by explicitly prepending a real Python install to PATH before adding
> Emscripten's own tools. Edit the `REAL_PYTHON_DIR` line in `emsdk_env.sh` if
> your real Python lives somewhere else.

### 2. Activate the Emscripten environment

Every new shell needs this once, before building:

```bash
source emsdk_env.sh
```

This puts `emcc`/`em++` and a working Node.js on `PATH` for that shell. Verify with:

```bash
emcc --version
```

### 3. Build the web version

```bash
./build-web.sh
```

This compiles `Main/iMain.cpp` (which pulls in every other `.h` file
unchanged) straight to WebAssembly, using Emscripten's `LEGACY_GL_EMULATION`
to keep the game's original immediate-mode OpenGL (`glBegin`/`glVertex`/
`glTexCoord`/etc.) working, and preloads every asset under `Main/` into the
compiled app's virtual filesystem so all the existing `iLoadImage(...)` calls
resolve unchanged.

**Output:** `web/dist/` — `index.html`, `game.js`, `game.wasm`, `game.data`.
This directory is a complete, self-contained static site.

### 4. Run it locally

WASM needs to be served over HTTP — opening `index.html` directly with
`file://` will not work. From `web/dist/`, run any static file server, e.g.:

```bash
cd web/dist
npx http-server -p 8080
# or: python -m http.server 8080
```

Then open **http://localhost:8080/** in Chrome, Firefox, or Edge.

### 5. Deploy to Vercel

The repo includes `vercel.json`, which rewrites `/game` and `/game/` to the
built site and sets the correct MIME/cache headers for `.wasm`/`.data`.

```bash
vercel deploy
```

No serverless functions are needed — it's a static deployment.

### 6. Deploy to Netlify

The repo includes `netlify.toml` (`publish = "web/dist"`, plus the same
`/game` redirect and MIME/cache headers).

```bash
netlify deploy --prod
```

### Controls (same as the Windows build)

| Key | Action |
|:---:|---|
| `A` / `D` | Move |
| `Space` | Jump |
| `1` / `2` / `3` / `4` | Punch / Kick / Ultimate / Block |
| `X` | Fire |
| `Enter` | Start / Confirm |
| `Z` | Menu |
| `Insert` | Select |
| `↑` / `↓` | Navigate menu |
| `Fullscreen` button on the page | Toggle fullscreen (Esc to exit) |

### Known limitations

- **No audio.** The original engine (`iGraphics.h`) has no sound API at all —
  there is nothing to port. This is unchanged from the Windows build.
- **Desktop only.** Keyboard controls are the only input method; touch/mobile
  is not supported (a documented, intentional scope limit, not a bug).
- **~85 MB download on first load.** Nearly all of that is the game's own
  PNG/JPG/BMP sprite sheets and backgrounds, preloaded up front so gameplay
  never stalls on an asset fetch. It's cached by the browser after first load.
  Compressing/re-encoding those source assets would shrink this further but
  was out of scope for the port itself.
- **High scores are per-browser.** They persist across refreshes via
  IndexedDB (`FS.mount(IDBFS, ...)` at `/persist`), but don't sync between
  different browsers/devices — there's no backend.
- Background art is stretched to fill the full 1600×700 canvas exactly like
  the original Windows build does (`iShowImage` always stretches to the given
  width/height); this is original behavior, not a web-porting artifact.

---

## 🛠️ Built With

- **C++** — Core game logic
- **iGraphics** — 2D rendering framework (OpenGL/GLUT wrapper by S. M. Shahriar Nirjon)
- **stb_image** — Lightweight image loading
- **OpenGL / GLUT** — Low-level graphics rendering
- **Win32 API** — Timer management for animations

---

## 📝 License

This project is for educational purposes. All Spider-Man characters and related names are trademarks of Marvel Entertainment.

---

<div align="center">

*Developed with ❤️ and web fluid*

</div>
