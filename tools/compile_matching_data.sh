#!/bin/sh
# Compile and private-verify each source-owned initialized-data unit.
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"

PYTHON=${PYTHON:-python3}
BUILD=${BUILD:-build/matching}
TARGET=${TARGET:-private/SLUS_204.86.rom}
mkdir -p "$BUILD/data"

"$PYTHON" tools/generate_data_symbol_addrs.py \
    src/data/mvc2_dispatch_00445A20.c config/data_symbol_addrs.txt

for source in src/data/data_zero_*.c; do
    name=$(basename "$source" .c)
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" "$source" \
        -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/data/$name.o"
    "$PYTHON" tools/verify_data_object.py "$BUILD/data/$name.o" "$TARGET" \
        --name "$name"
done

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/data/mvc2_dispatch_00445A20.c -c -lang c -O3 -sdatathreshold 0 \
    -i src/data -o "$BUILD/data/mvc2_dispatch_00445A20.o"
"$PYTHON" tools/verify_data_object.py \
    "$BUILD/data/mvc2_dispatch_00445A20.o" "$TARGET" \
    --name gMvc2Dispatch_00445A20
