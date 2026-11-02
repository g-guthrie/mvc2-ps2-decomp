#!/bin/sh
# Build the arcade oracle: the Flycast emulator core (open source, GPLv2),
# pinned to v2.5, with flycast.patch (guest-PC hooks in the SH-4 dynarec and
# interpreter, a JVS input override, no audio throttle, symbols kept, the
# null renderer, the --naomi-oracle entry) and the driver naomi_oracle.cpp.
# Needs: cmake, ninja, g++, libsdl2-dev, libcurl4-openssl-dev, zlib.
# About 12 minutes on 4 cores, ~250 MB (sources 220 MB, build 85 MB).
#   build.sh [WORKDIR]   (default /tmp/naomi_oracle_src) -> WORKDIR/build/flycast
# No ROM or BIOS is involved in the build; the user's own mvsc2.zip and
# naomi.zip (MAME sets) are given at run time (run_pair.sh).
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
W=${1:-/tmp/naomi_oracle_src}
FLYCAST_TAG=v2.5
FLYCAST_COMMIT=5f4eefab5852d1c832ad8ffdf514fef8c217f1ac
mkdir -p "$W"
if [ ! -d "$W/flycast" ]; then
    git clone -q --depth 1 --branch $FLYCAST_TAG https://github.com/flyinghead/flycast.git "$W/flycast"
    (cd "$W/flycast" && test "$(git rev-parse HEAD)" = $FLYCAST_COMMIT &&
     git submodule update --init --depth 1 core/deps/libchdr core/deps/asio core/deps/rcheevos &&
     git apply "$HERE/flycast.patch")
fi
mkdir -p "$W/flycast/core/oracle"
for f in naomi_oracle.cpp naomi_dump.h oracle_hook.h oracle_hook.cpp; do
    ln -sf "$HERE/$f" "$W/flycast/core/oracle/$f"
done
cmake -S "$W/flycast" -B "$W/build" -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DUSE_VULKAN=OFF -DUSE_LUA=OFF -DUSE_BREAKPAD=OFF -DUSE_ALSA=OFF -DUSE_PULSEAUDIO=OFF \
    -DUSE_LIBAO=OFF -DUSE_OPENMP=OFF -DUSE_HOST_SDL=ON -DUSE_DX9=OFF -DUSE_DX11=OFF \
    -DENABLE_GDB_SERVER=OFF
ninja -C "$W/build" flycast
