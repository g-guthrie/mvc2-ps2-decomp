#!/bin/sh
# Compile one source with Sony EE GCC 2.9-991111 and verify its registered matches.
# usage: ./trysony29.sh src/f.c [0|8] [O0|O1|O2|O3] ["extra cc1 flags"]
#   This is the compiler whose prologue saves s0/s1/ra with `sd` at 16-byte
#   spacing (0/16/32). Functions with that save shape are its candidates;
#   Metrowerks uses `sq` and SN 2.95.3 mixes `sq`/`sd`.
set -eu
cd "$(dirname "$0")"
. private/build.env
. private/sony29.env
SRC="$1"; G="${2:-0}"; OPT="${3:-O2}"; EXTRA="${4:-}"
STEM=$(basename "$SRC" .c)
mkdir -p build/try
rm -f "build/try/$STEM.o"
"$WIBO" "$SNCPP" -P "$SRC" "build/try/$STEM.i"
"$WIBO" "$EE29CC1" "build/try/$STEM.i" -$OPT -G"$G" -ffunction-sections $EXTRA \
    -quiet -o "build/try/$STEM.s"
"$WIBO" "$SNAS" -G"$G" -o "build/try/$STEM.o" "build/try/$STEM.s"
"$PYTHON" tools/verify_object.py "build/try/$STEM.o" private/SLUS_204.86.rom --source "$SRC"
