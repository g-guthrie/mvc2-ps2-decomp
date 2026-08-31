#!/bin/sh

set -eu

PYTHON=${PYTHON:-python3}
BUILD=${BUILD:-build/hybrid}

"$PYTHON" tools/pack_retail_elf.py \
    "$BUILD/SLUS_204.86.hybrid.rom" \
    "$BUILD/SLUS_204.86.reconstructed.elf"
