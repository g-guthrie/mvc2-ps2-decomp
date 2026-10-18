#!/bin/sh
# Same as try.sh but with the 3.0 compiler (MWCCPS2_30).
set -eu
cd "$(dirname "$0")"
. private/build.env
SRC="$1"; shift
FLAGS="${*:--O3 -sdatathreshold 0}"
STEM=$(basename "$SRC" .c)
mkdir -p build/try
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" "$SRC" -c -lang c $FLAGS -o "build/try/$STEM.o"
"$PYTHON" tools/verify_object.py "build/try/$STEM.o" private/SLUS_204.86.rom --source "$SRC"
echo "ALL MATCHED"
