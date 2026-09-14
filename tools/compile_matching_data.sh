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
    src/data/mvc2_mode_handler_table_004490C0.c \
    src/data/mvc2_event_dispatch_0043CBB0.c \
    src/data/mvc2_mode_select_dispatch_0043CCE0.c \
    src/data/mvc2_stage_handler_table_00448D00.c \
    src/data/mvc2_allocator_bins_0043B708.c \
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
compile_table src/data/mvc2_mode_handler_table_004490C0.c gMvc2ModeHandlerTable_004490C0
compile_table src/data/mvc2_event_dispatch_0043CBB0.c gMvc2EventDispatch_0043CBB0
compile_table src/data/mvc2_mode_select_dispatch_0043CCE0.c gMvc2ModeSelectDispatch_0043CCE0
compile_table src/data/mvc2_stage_handler_table_00448D00.c gMvc2StageHandlerTable_00448D00
compile_table src/data/mvc2_allocator_bins_0043B708.c gMvc2AllocatorBins_0043B708
compile_table src/data/jtbl_004BA560.c jtbl_004BA560
compile_table src/data/jtbl_004BA6D0.c jtbl_004BA6D0
compile_table src/data/jtbl_004BA6F0.c jtbl_004BA6F0
compile_table src/data/jtbl_004AABC0.c jtbl_004AABC0
compile_table src/data/jtbl_004AADD0.c jtbl_004AADD0
compile_table src/data/jtbl_004AB000.c jtbl_004AB000
compile_table src/data/jtbl_004AB130.c jtbl_004AB130
compile_table src/data/jtbl_004A6CD0.c jtbl_004A6CD0
compile_table src/data/jtbl_004A6D20.c jtbl_004A6D20
compile_table src/data/jtbl_004A6D30.c jtbl_004A6D30
compile_table src/data/jtbl_004A6D40.c jtbl_004A6D40
compile_table src/data/jtbl_004BAC00.c jtbl_004BAC00
compile_table src/data/jtbl_004BAC20.c jtbl_004BAC20
compile_table src/data/resource_handlers.c D_00444520
compile_table src/data/geometry_handlers.c D_00476C10
compile_table src/data/jtbl_004C2518.c jtbl_004C2518
compile_table src/data/jtbl_004C2520.c jtbl_004C2520
compile_table src/data/jtbl_004C0120.c jtbl_004C0120
compile_table src/data/jtbl_004C0138.c jtbl_004C0138
compile_table src/data/jtbl_004C0140.c jtbl_004C0140
compile_table src/data/jtbl_004C0148.c jtbl_004C0148
compile_table src/data/jtbl_004C0150.c jtbl_004C0150
compile_table src/data/jtbl_004C0158.c jtbl_004C0158
compile_table src/data/jtbl_004C0160.c jtbl_004C0160
compile_table src/data/jtbl_004C0168.c jtbl_004C0168
compile_table src/data/jtbl_004C0170.c jtbl_004C0170
compile_table src/data/jtbl_004C0178.c jtbl_004C0178
compile_table src/data/jtbl_004C0180.c jtbl_004C0180
compile_table src/data/jtbl_004C0188.c jtbl_004C0188
compile_table src/data/jtbl_004C0190.c jtbl_004C0190
