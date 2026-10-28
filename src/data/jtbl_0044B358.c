typedef signed short s16;
/* 8-byte (x, y) offset records read by func_001A5BC0 through D_004BF748: each record holds
 * a normal pair (+0/+2) and an alternate pair (+4/+6) chosen by bit 7 of actor +0x21, both
 * loaded with lh. This unit holds records 1..3 of the table at D_0044B350 and record 0 of
 * the table at D_0044B370 (D_004BF748[1]), which continues in data_u32_0044B380. */
typedef struct {
    s16 x;
    s16 y;
    s16 altX;
    s16 altY;
} OffsetPairRecord;
typedef char OffsetPairRecord_size_check[(sizeof(OffsetPairRecord) == 8) ? 1 : -1];
const OffsetPairRecord jtbl_0044B358[4] = {
    { 0, 48, 0, 36 },
    { 0, 74, 0, 61 },
    { 20, 99, -8, 86 },
    { 0, 36, 0, 22 },
};
