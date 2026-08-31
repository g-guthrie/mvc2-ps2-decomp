#!/bin/sh
set -eu

if [ "$#" -ne 2 ]; then
    echo "usage: $0 GAME.bin GAME.cue" >&2
    exit 2
fi

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
BIN=$1
CUE=$2
PYTHON=${PYTHON:-python3}
PRIVATE="$ROOT/private"
DISC="$PRIVATE/disc/mvc2-ps2"

command -v bchunk >/dev/null || { echo "bchunk is required" >&2; exit 2; }
command -v 7z >/dev/null || { echo "7z is required" >&2; exit 2; }
test -f "$BIN" || { echo "BIN not found: $BIN" >&2; exit 2; }
test -f "$CUE" || { echo "CUE not found: $CUE" >&2; exit 2; }

mkdir -p "$PRIVATE/disc" "$PRIVATE/extracted"
bchunk "$BIN" "$CUE" "$DISC"
7z x -y "-o$PRIVATE/extracted" "${DISC}01.iso"
"$PYTHON" "$ROOT/tools/extract_elf.py" \
    "$PRIVATE/extracted/SLUS_204.86" \
    "$PRIVATE/SLUS_204.86.rom"
