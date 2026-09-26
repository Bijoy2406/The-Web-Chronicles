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
