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
    src/data/mvc2_dispatch_00445A20.c \
    src/data/mvc2_dispatch_0043CB70.c \
    src/data/mvc2_action_dispatch_004BA540.c \
    src/data/jtbl_004ACA80.c \
    config/data_symbol_addrs.txt

for source in src/data/data_zero_*.c; do
    name=$(basename "$source" .c)
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" "$source" \
        -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/data/$name.o"
    "$PYTHON" tools/verify_data_object.py "$BUILD/data/$name.o" "$TARGET" \
        --name "$name"
done

compile_table() {
    source=$1
    name=$2
    object="$BUILD/data/$(basename "$source" .c).o"
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
        "$source" -c -lang c -O3 -sdatathreshold 0 -i src/data -o "$object"
    "$PYTHON" tools/verify_data_object.py "$object" "$TARGET" --name "$name"
}

compile_table src/data/mvc2_dispatch_00445A20.c gMvc2Dispatch_00445A20
compile_table src/data/mvc2_dispatch_0043CB70.c gMvc2Dispatch_0043CB70
compile_table src/data/mvc2_action_dispatch_004BA540.c gMvc2ActionDispatch_004BA540
compile_table src/data/jtbl_004ACA80.c jtbl_004ACA80
compile_table src/data/identity_00464EEC.c gIdentity3x3_00464EEC
