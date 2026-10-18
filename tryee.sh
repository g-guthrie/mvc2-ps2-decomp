#!/bin/sh
# Compile one source with EE GCC 2.96 and verify its registered matches.
# usage: ./tryee.sh src/f.c [gnu|sn] [0|8] [O0|O1|O2|O3]
#   arg2 assembler  (default gnu; retail usually needs sn)
#   arg3 small-data threshold (default 0; use 8 for $gp globals)
#   arg4 optimisation level   (default O2)
#   arg5 extra cc1 flags      (default none; e.g. "-fschedule-insns2")
set -eu
cd "$(dirname "$0")"
. private/build.env
SRC="$1"; AS_KIND="${2:-gnu}"; G="${3:-0}"; OPT="${4:-O2}"; EXTRA="${5:-}"
STEM=$(basename "$SRC" .c)
mkdir -p build/try
"$WIBO" "$SNCPP" -P "$SRC" "build/try/$STEM.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold "$G" --opt "$OPT" --extra-flags="$EXTRA" \
    "build/try/$STEM.i" "build/try/$STEM.s"
if [ "$AS_KIND" = sn ]; then
    "$WIBO" "$SNAS" -G"$G" -o "build/try/$STEM.o" "build/try/$STEM.s"
else
    "${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G"$G" -o "build/try/$STEM.o" "build/try/$STEM.s"
fi
"$PYTHON" tools/verify_object.py "build/try/$STEM.o" private/SLUS_204.86.rom --source "$SRC"
echo "ALL MATCHED"
