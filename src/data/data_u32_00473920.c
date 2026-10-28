typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
/* Records 80..84 of the 14-byte record table based at D_004734C0 (0x004734C0 + 80 * 14 = 0x00473920;
 * the table starts in data_u32_00473360). func_003AB4A0 indexes it with the s8 at owner +0x151
 * ((i * 7) << 1) and loads +0 with lb; the record fields follow the Rec14 readers; each 8-record group ends with an f0 = -1
 * record. Field types match the Rec14 layout in data_u32_00473360.c. The last 10 bytes are the
 * head of record 85 (zero), which continues in data_zero_00473970. */
typedef struct Rec14 {
    s8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s16 x;
    s16 y;
    u8 f8;
    u8 f9;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
} Rec14;
typedef char Rec14_size_check[(sizeof(Rec14) == 14) ? 1 : -1];
typedef struct {
    Rec14 recs[5];
    u8 nextRecordHead[10];
} RecRun_00473920;
typedef char RecRun_00473920_size_check[(sizeof(RecRun_00473920) == 80) ? 1 : -1];

RecRun_00473920 data_u32_00473920 = {
    {
        { 0, 200, 252, 255, -21, 89, 0, 12, 240, 1, 136, 0 },
        { 0, 212, 252, 255, 49, 93, 64, 12, 240, 1, 224, 0 },
        { 0, 224, 252, 255, 43, 98, 32, 12, 16, 255, 80, 0 },
        { 0, 240, 252, 255, 2, 111, 16, 12, 16, 255, 120, 0 },
        { -1, 0, 4, 0, -37, 148, 0, 16, 0, 0, 0, 0 },
    },
    { 0 },
};
