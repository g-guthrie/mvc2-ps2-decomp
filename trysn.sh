#!/bin/sh
# Compile one source with SN GCC 2.95.2 and verify its registered matches.
# usage: ./trysn.sh src/myfile.c ["-O2 -G0 -ffunction-sections"]
set -eu
cd "$(dirname "$0")"
. private/build.env
SRC="$1"; shift
FLAGS="${*:--O2 -G0 -ffunction-sections}"
STEM=$(basename "$SRC" .c)
mkdir -p build/try
# Drop any stale object first, so a failed compile can never leave the previous
# run's .o behind for a wrapper that ignores the compiler's exit status.
rm -f "build/try/$STEM.o"
"$WIBO" "$SNCPP" -P "$SRC" "build/try/$STEM.i"
"$WIBO" "$SNCC1" "build/try/$STEM.i" $FLAGS -quiet -o "build/try/$STEM.s"
"$WIBO" "$SNAS" -G0 -o "build/try/$STEM.o" "build/try/$STEM.s"
"$PYTHON" tools/verify_object.py "build/try/$STEM.o" private/SLUS_204.86.rom --source "$SRC"
echo "ALL MATCHED"
