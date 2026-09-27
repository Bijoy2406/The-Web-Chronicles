#!/usr/bin/env bash
# Builds the browser/WebAssembly version of The Web Chronicles.
#
# Prerequisites: Emscripten SDK installed one directory above this repo, at
# H:\game\emsdk (see README.md "Playing in the Browser" section for the
# one-time install steps). This script does not install emsdk itself — run
# it once first if H:\game\emsdk doesn't exist yet:
#   git clone https://github.com/emscripten-core/emsdk.git ../emsdk
#   cd ../emsdk && ./emsdk install latest && ./emsdk activate latest
#
# Usage (from repo root, in Git Bash / any POSIX shell):
#   ./build-web.sh
#
# Output: web/dist/ (index.html, game.js, game.wasm, game.data) — a
# self-contained static site, ready to serve locally (see PHASE 23 in
# README) or deploy to Vercel/Netlify as-is.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$REPO_ROOT"

source ./emsdk_env.sh

mkdir -p web/dist

echo "==> Compiling Main/iMain.cpp -> web/dist/game.{js,wasm,data}"
cd Main
em++ iMain.cpp -o ../web/dist/game.js \
  -s LEGACY_GL_EMULATION=1 -lglut -lGL \
  -s ALLOW_MEMORY_GROWTH=1 -s EXIT_RUNTIME=0 \
  -lidbfs.js \
  -O2 -Wno-writable-strings -w \
  --preload-file . \
  --exclude-file "*.cpp" --exclude-file "*.h" --exclude-file "*.H" \
  --exclude-file "*.vcxproj*" --exclude-file "Debug" --exclude-file "*.obj" \
  --exclude-file "*.pdb" --exclude-file "*.idb" --exclude-file "*.log" \
  --exclude-file "*.lib" --exclude-file "*.dll" --exclude-file "highScore.bin" \
  --exclude-file "highScore.txt"
cd ..

# index.html is hand-written (web/dist/index.html) and not regenerated here;
# it's already in place alongside the freshly built game.js/.wasm/.data.

echo "==> Done. Web build output: web/dist/"
ls -la web/dist
