#!/bin/sh
# Compile one source with MWCCPS2 and verify its registered matches against retail.
# usage: ./try.sh src/myfile.c ["-O3 -sdatathreshold 0"]
set -eu
cd "$(dirname "$0")"
. private/build.env
SRC="$1"; shift
FLAGS="${*:--O3 -sdatathreshold 0}"
STEM=$(basename "$SRC" .c)
mkdir -p build/try
# Drop any stale object first, so a failed compile can never leave the previous
# run's .o behind for a wrapper that ignores the compiler's exit status.
rm -f "build/try/$STEM.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" "$SRC" -c -lang c $FLAGS -o "build/try/$STEM.o"
"$PYTHON" tools/verify_object.py "build/try/$STEM.o" private/SLUS_204.86.rom --source "$SRC"
echo "ALL MATCHED"
