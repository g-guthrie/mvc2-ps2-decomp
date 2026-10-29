#!/bin/sh
# C_COMPILER_LAUNCHER for the game TUs on Emscripten: run the emsdk clang
# directly (what emcc runs for each TU) and skip emcc's per-file Python
# start-up.  The game TUs are freestanding (-nostdlibinc), so emcc's sysroot
# and settings are not needed; port/tools/probe_host_build.py does the same.
emcc="$1"; shift
exec "$(dirname "$emcc")/../bin/clang" --target=wasm32-unknown-emscripten "$@"
