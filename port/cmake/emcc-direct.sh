#!/bin/sh
# C_COMPILER_LAUNCHER for the game TUs on Emscripten: run the emsdk clang
# directly (what emcc runs for each TU) and skip emcc's per-file Python
# start-up.  The game TUs are freestanding (-nostdlibinc), so emcc's sysroot
# and settings are not needed; port/tools/probe_host_build.py does the same.
# emsdk keeps clang at upstream/bin next to upstream/emscripten; other
# installs (Homebrew) are found through emscripten's LLVM_ROOT, looked up once.
emcc="$1"; shift
clang="$(dirname "$emcc")/../bin/clang"
if [ ! -x "$clang" ]; then
    cache="${TMPDIR:-/tmp}/mvc2-emcc-llvm-root.$(id -u)"
    [ -s "$cache" ] || "$(dirname "$emcc")/em-config" LLVM_ROOT > "$cache"
    clang="$(cat "$cache")/clang"
fi
exec "$clang" --target=wasm32-unknown-emscripten "$@"
