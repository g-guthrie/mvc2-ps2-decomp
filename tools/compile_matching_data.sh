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
compile_table src/data/jtbl_004C0360.c jtbl_004C0360
compile_table src/data/jtbl_004C0368.c jtbl_004C0368
compile_table src/data/jtbl_004C0370.c jtbl_004C0370
compile_table src/data/jtbl_004C0378.c jtbl_004C0378
compile_table src/data/jtbl_004C0380.c jtbl_004C0380
compile_table src/data/jtbl_004C0388.c jtbl_004C0388
compile_table src/data/jtbl_004C0390.c jtbl_004C0390
compile_table src/data/jtbl_004C0398.c jtbl_004C0398
compile_table src/data/jtbl_004C03A0.c jtbl_004C03A0
compile_table src/data/jtbl_004C03A8.c jtbl_004C03A8
compile_table src/data/jtbl_004C03F8.c jtbl_004C03F8
compile_table src/data/jtbl_004C0400.c jtbl_004C0400
compile_table src/data/jtbl_004C0410.c jtbl_004C0410
compile_table src/data/jtbl_004C0418.c jtbl_004C0418
compile_table src/data/jtbl_004C0420.c jtbl_004C0420
compile_table src/data/jtbl_004C0428.c jtbl_004C0428
compile_table src/data/jtbl_004C0430.c jtbl_004C0430
compile_table src/data/jtbl_004C0480.c jtbl_004C0480
compile_table src/data/jtbl_004C0490.c jtbl_004C0490
compile_table src/data/jtbl_004C0498.c jtbl_004C0498
compile_table src/data/jtbl_004C04A8.c jtbl_004C04A8
compile_table src/data/jtbl_004C04B0.c jtbl_004C04B0
compile_table src/data/jtbl_004C0540.c jtbl_004C0540
compile_table src/data/jtbl_004C0548.c jtbl_004C0548
compile_table src/data/jtbl_004C0550.c jtbl_004C0550
compile_table src/data/jtbl_004C0558.c jtbl_004C0558
compile_table src/data/jtbl_004C0560.c jtbl_004C0560
compile_table src/data/jtbl_004C0568.c jtbl_004C0568
compile_table src/data/jtbl_004C0570.c jtbl_004C0570
compile_table src/data/jtbl_004C0578.c jtbl_004C0578
compile_table src/data/jtbl_004C0580.c jtbl_004C0580
compile_table src/data/jtbl_004C0588.c jtbl_004C0588
compile_table src/data/jtbl_004C0600.c jtbl_004C0600
compile_table src/data/jtbl_004C0608.c jtbl_004C0608
compile_table src/data/jtbl_004C0610.c jtbl_004C0610
compile_table src/data/jtbl_004C0618.c jtbl_004C0618
compile_table src/data/jtbl_004C0620.c jtbl_004C0620
compile_table src/data/jtbl_004C06D0.c jtbl_004C06D0
compile_table src/data/jtbl_004C06D8.c jtbl_004C06D8
compile_table src/data/jtbl_004C06E0.c jtbl_004C06E0
compile_table src/data/jtbl_004C06E8.c jtbl_004C06E8
compile_table src/data/jtbl_004C06F0.c jtbl_004C06F0
compile_table src/data/jtbl_004C06F8.c jtbl_004C06F8
compile_table src/data/jtbl_004C0700.c jtbl_004C0700
compile_table src/data/jtbl_004C0708.c jtbl_004C0708
compile_table src/data/jtbl_004C0710.c jtbl_004C0710
compile_table src/data/jtbl_004C0760.c jtbl_004C0760
compile_table src/data/jtbl_004C0768.c jtbl_004C0768
compile_table src/data/jtbl_004C0770.c jtbl_004C0770
compile_table src/data/jtbl_004C0778.c jtbl_004C0778
compile_table src/data/jtbl_004C07C8.c jtbl_004C07C8
compile_table src/data/jtbl_004C07D0.c jtbl_004C07D0
compile_table src/data/jtbl_004C07D8.c jtbl_004C07D8
compile_table src/data/jtbl_004C07E0.c jtbl_004C07E0
compile_table src/data/jtbl_004C07E8.c jtbl_004C07E8
compile_table src/data/jtbl_004C07F0.c jtbl_004C07F0
compile_table src/data/jtbl_004C07F8.c jtbl_004C07F8
compile_table src/data/jtbl_004C0800.c jtbl_004C0800
compile_table src/data/jtbl_004C0808.c jtbl_004C0808
compile_table src/data/jtbl_004C0810.c jtbl_004C0810
compile_table src/data/jtbl_004C0818.c jtbl_004C0818
compile_table src/data/jtbl_004C0820.c jtbl_004C0820
compile_table src/data/jtbl_004C0828.c jtbl_004C0828
compile_table src/data/jtbl_004C0840.c jtbl_004C0840
compile_table src/data/jtbl_004C0848.c jtbl_004C0848
compile_table src/data/jtbl_004C0850.c jtbl_004C0850
compile_table src/data/jtbl_004C08E0.c jtbl_004C08E0
compile_table src/data/jtbl_004C08E8.c jtbl_004C08E8
compile_table src/data/jtbl_004C08F0.c jtbl_004C08F0
compile_table src/data/jtbl_004C08F8.c jtbl_004C08F8
compile_table src/data/jtbl_004C0960.c jtbl_004C0960
compile_table src/data/jtbl_004C0968.c jtbl_004C0968
compile_table src/data/jtbl_004C0970.c jtbl_004C0970
compile_table src/data/jtbl_004C0980.c jtbl_004C0980
compile_table src/data/jtbl_004C0988.c jtbl_004C0988
compile_table src/data/jtbl_004C0990.c jtbl_004C0990
compile_table src/data/jtbl_004C0998.c jtbl_004C0998
compile_table src/data/jtbl_004C09A0.c jtbl_004C09A0
compile_table src/data/jtbl_004C09A8.c jtbl_004C09A8
compile_table src/data/jtbl_004C09B0.c jtbl_004C09B0
compile_table src/data/jtbl_004C0A08.c jtbl_004C0A08
compile_table src/data/jtbl_004C0A18.c jtbl_004C0A18
compile_table src/data/jtbl_004C0A20.c jtbl_004C0A20
compile_table src/data/jtbl_004C0A28.c jtbl_004C0A28
compile_table src/data/jtbl_004C0A30.c jtbl_004C0A30
compile_table src/data/jtbl_004C0A38.c jtbl_004C0A38
compile_table src/data/jtbl_004C0A40.c jtbl_004C0A40
compile_table src/data/jtbl_004C0A48.c jtbl_004C0A48
compile_table src/data/jtbl_004C0A50.c jtbl_004C0A50
compile_table src/data/jtbl_004C0A58.c jtbl_004C0A58
compile_table src/data/jtbl_004C0A60.c jtbl_004C0A60
compile_table src/data/jtbl_004C0A68.c jtbl_004C0A68
compile_table src/data/jtbl_004C0A70.c jtbl_004C0A70
compile_table src/data/jtbl_004C0AC0.c jtbl_004C0AC0
compile_table src/data/jtbl_004C0AD8.c jtbl_004C0AD8
compile_table src/data/jtbl_004C0AE8.c jtbl_004C0AE8
compile_table src/data/jtbl_004C0B38.c jtbl_004C0B38
compile_table src/data/jtbl_004C0B48.c jtbl_004C0B48
compile_table src/data/jtbl_004C0B98.c jtbl_004C0B98
compile_table src/data/jtbl_004C0BA8.c jtbl_004C0BA8
compile_table src/data/jtbl_004C0BB0.c jtbl_004C0BB0
compile_table src/data/jtbl_004C0BB8.c jtbl_004C0BB8
compile_table src/data/jtbl_004C0BC0.c jtbl_004C0BC0
compile_table src/data/jtbl_004C0BC8.c jtbl_004C0BC8
compile_table src/data/jtbl_004C0C18.c jtbl_004C0C18
compile_table src/data/jtbl_004C0C20.c jtbl_004C0C20
compile_table src/data/jtbl_004C0C30.c jtbl_004C0C30
compile_table src/data/jtbl_004C0CA0.c jtbl_004C0CA0
compile_table src/data/jtbl_004C0D08.c jtbl_004C0D08
compile_table src/data/jtbl_004C0D10.c jtbl_004C0D10
compile_table src/data/jtbl_004C0D18.c jtbl_004C0D18
compile_table src/data/jtbl_004C0D20.c jtbl_004C0D20
compile_table src/data/jtbl_004C0D70.c jtbl_004C0D70
compile_table src/data/jtbl_004C0D78.c jtbl_004C0D78
compile_table src/data/jtbl_004C0D80.c jtbl_004C0D80
compile_table src/data/jtbl_004C0D98.c jtbl_004C0D98
compile_table src/data/jtbl_004C0DE8.c jtbl_004C0DE8
compile_table src/data/jtbl_004C0DF0.c jtbl_004C0DF0
compile_table src/data/jtbl_004C0E00.c jtbl_004C0E00
compile_table src/data/jtbl_004C0E08.c jtbl_004C0E08
compile_table src/data/jtbl_004C0E10.c jtbl_004C0E10
compile_table src/data/jtbl_004C0E60.c jtbl_004C0E60
compile_table src/data/jtbl_004C0E78.c jtbl_004C0E78
compile_table src/data/jtbl_004C0E80.c jtbl_004C0E80
compile_table src/data/jtbl_004C0E88.c jtbl_004C0E88
compile_table src/data/jtbl_004C0E90.c jtbl_004C0E90
compile_table src/data/jtbl_004C0E98.c jtbl_004C0E98
compile_table src/data/jtbl_004C0EA0.c jtbl_004C0EA0
compile_table src/data/jtbl_004C0EB0.c jtbl_004C0EB0
compile_table src/data/jtbl_004C0F00.c jtbl_004C0F00
compile_table src/data/jtbl_004C0F18.c jtbl_004C0F18
compile_table src/data/jtbl_004C0F28.c jtbl_004C0F28
compile_table src/data/jtbl_004C0F78.c jtbl_004C0F78
compile_table src/data/jtbl_004C0F88.c jtbl_004C0F88
compile_table src/data/jtbl_004C0F90.c jtbl_004C0F90
compile_table src/data/jtbl_004C0F98.c jtbl_004C0F98
compile_table src/data/jtbl_004C0FA0.c jtbl_004C0FA0
compile_table src/data/jtbl_004C0FA8.c jtbl_004C0FA8
compile_table src/data/jtbl_004C0FC8.c jtbl_004C0FC8
compile_table src/data/jtbl_004C1098.c jtbl_004C1098
compile_table src/data/jtbl_004C10A0.c jtbl_004C10A0
compile_table src/data/jtbl_004C10A8.c jtbl_004C10A8
compile_table src/data/jtbl_004C10B0.c jtbl_004C10B0
compile_table src/data/jtbl_004C10B8.c jtbl_004C10B8
compile_table src/data/jtbl_004C10C0.c jtbl_004C10C0
compile_table src/data/jtbl_004C1100.c jtbl_004C1100
compile_table src/data/jtbl_004C1108.c jtbl_004C1108
compile_table src/data/jtbl_004C1110.c jtbl_004C1110
compile_table src/data/jtbl_004C1118.c jtbl_004C1118
compile_table src/data/jtbl_004C1120.c jtbl_004C1120
compile_table src/data/jtbl_004C1170.c jtbl_004C1170
compile_table src/data/jtbl_004C1178.c jtbl_004C1178
compile_table src/data/jtbl_004C1180.c jtbl_004C1180
compile_table src/data/jtbl_004C1188.c jtbl_004C1188
compile_table src/data/jtbl_004C1190.c jtbl_004C1190
compile_table src/data/jtbl_004C1198.c jtbl_004C1198
compile_table src/data/jtbl_004C11A0.c jtbl_004C11A0
compile_table src/data/jtbl_004C11A8.c jtbl_004C11A8
