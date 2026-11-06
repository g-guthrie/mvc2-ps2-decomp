#!/bin/bash
# Patch Ghidra's SH-4 language so every float instruction decodes as single precision
# with 32-bit moves (FPSCR.PR = 0, FPSCR.SZ = 0), which is how this game runs its FPU,
# then recompile the language. Usage: tools/ghidra/single_precision.sh GHIDRA_DIR
set -e
L="$1/Ghidra/Processors/SuperH4/data/languages"
cp -n "$L/SuperH4.sinc" "$L/SuperH4.sinc.orig"
sed -e 's/!( \$(FPSCR_PR) == 0 )/(0:1 == 1:1)/g' -e 's/!( \$(FPSCR_SZ) == 0 )/(0:1 == 1:1)/g' "$L/SuperH4.sinc.orig" > "$L/SuperH4.sinc"
"$1/support/sleigh" -a "$L" > /dev/null
echo "patched: $(grep -c '(0:1 == 1:1)' "$L/SuperH4.sinc") float mode checks forced to single precision"
