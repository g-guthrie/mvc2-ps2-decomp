#!/bin/sh
# Build mvc2_av (the oracle with Play!'s GS renderer and SPU2 output).
# A separate Play! tree from port/tools/oracle (same pinned commit,
# ../oracle/play.patch + play_av.patch).  Needs EGL + GLES3 headers/libs
# (Mesa) and libpng.  ~5 min, ~150 MB.
#   build.sh [WORKDIR]   (default /tmp/oracle_av) -> WORKDIR/build/mvc2_av
# With an existing pinned checkout (e.g. /tmp/oracle_src/play):
#   SRC=/tmp/oracle_src/play build.sh   copies it instead of cloning.
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
W=${1:-/tmp/oracle_av}
PLAY_COMMIT=1f27232772e484bfb79364b751b84f41f4c87481
mkdir -p "$W"
if [ ! -d "$W/play" ]; then
    if [ -n "$SRC" ]; then
        cp -a "$SRC" "$W/play"
        (cd "$W/play" && git checkout -q -- Source)
    else
        git clone https://github.com/jpd002/Play-.git "$W/play"
        (cd "$W/play" && git checkout -q $PLAY_COMMIT &&
         git submodule update --init --depth 1 deps/Framework deps/CodeGen deps/Nuanceur deps/libchdr deps/Dependencies &&
         cd deps/Dependencies && git submodule update --init --depth 1 zstd xxHash ghc_filesystem)
    fi
    (cd "$W/play" && git apply "$HERE/../oracle/play.patch" && git apply "$HERE/play_av.patch")
fi
cmake -S "$HERE" -B "$W/build" -G Ninja -DCMAKE_BUILD_TYPE=Release -DPLAY_DIR="$W/play"
ninja -C "$W/build" mvc2_av
