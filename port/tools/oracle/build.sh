#!/bin/sh
# Build mvc2_oracle: the Play! emulator core (HLE BIOS, no PS2 BIOS needed),
# pinned, with play.patch (the breakpoint prolog becomes a per-frame hook),
# and the headless driver mvc2_oracle.cpp.  About 2 minutes, ~400 MB.
#   build.sh [WORKDIR]   (default /tmp/oracle_src) -> WORKDIR/build/mvc2_oracle
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
W=${1:-/tmp/oracle_src}
PLAY_COMMIT=1f27232772e484bfb79364b751b84f41f4c87481
mkdir -p "$W"
if [ ! -d "$W/play" ]; then
    git clone https://github.com/jpd002/Play-.git "$W/play"
    (cd "$W/play" && git checkout -q $PLAY_COMMIT &&
     git submodule update --init --depth 1 deps/Framework deps/CodeGen deps/Nuanceur deps/libchdr deps/Dependencies &&
     cd deps/Dependencies && git submodule update --init --depth 1 zstd xxHash ghc_filesystem)
    (cd "$W/play" && git apply "$HERE/play.patch")
fi
cmake -S "$HERE" -B "$W/build" -G Ninja -DCMAKE_BUILD_TYPE=Release -DPLAY_DIR="$W/play"
ninja -C "$W/build" mvc2_oracle
