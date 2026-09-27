#!/usr/bin/env bash
# Sourceable helper: puts a working Emscripten (emcc/em++/emcmake) + Node.js
# toolchain on PATH for this shell. The bundled emsdk lives one directory up
# (H:\game\emsdk), outside this repo, and is NOT committed to git.
#
# Usage (from repo root, in Git Bash):
#   source emsdk_env.sh
#   emcc --version
#
# Why this exists instead of just `source ../emsdk/emsdk_env.sh`:
# on this machine the `python` shim on PATH is the Microsoft Store stub
# (prints "Python was not found..." and exits), so emcc.exe's internal
# `python emcc.py ...` relaunch fails unless a real python is placed
# ahead of it on PATH explicitly.
EMSDK_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../emsdk" && pwd)"
REAL_PYTHON_DIR="/c/Users/USERAS/AppData/Local/Python/bin"

export PATH="$REAL_PYTHON_DIR:$EMSDK_ROOT:$EMSDK_ROOT/upstream/emscripten:$EMSDK_ROOT/node/24.19.0_64bit/bin:$PATH"
export EMSDK="$EMSDK_ROOT"
export EMSDK_NODE="$EMSDK_ROOT/node/24.19.0_64bit/bin/node.exe"

echo "emsdk env ready: $(emcc --version 2>&1 | head -1)"
