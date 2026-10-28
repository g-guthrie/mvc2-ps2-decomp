typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
/* Records 96..101 of the 14-byte record table based at D_004734C0 (0x004734C0 + 96 * 14 = 0x00473A00;
 * the table starts in data_u32_00473360). func_003AB4A0 indexes it with the s8 at owner +0x151
 * ((i * 7) << 1) and loads +0 with lb; the record fields follow the Rec14 readers; each 8-record group ends with an f0 = -1
 * record. Field types match the Rec14 layout in data_u32_00473360.c. The last 12 bytes are the
 * head of record 102 (zero), which continues in data_zero_00473A60. */
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
    Rec14 recs[6];
    u8 nextRecordHead[12];
} RecRun_00473A00;
typedef char RecRun_00473A00_size_check[(sizeof(RecRun_00473A00) == 96) ? 1 : -1];

RecRun_00473A00 data_u32_00473A00 = {
    {
        { 0, 200, 252, 255, -21, 89, 232, 16, 240, 1, 144, 0 },
        { 0, 212, 252, 255, 49, 93, 0, 16, 240, 1, 128, 0 },
        { 0, 224, 252, 255, 43, 98, 32, 16, 240, 1, 192, 0 },
        { 0, 240, 252, 255, 64, 110, 0, 16, 12, 255, 60, 0 },
        { 0, 240, 252, 255, 12, 118, 224, 16, 12, 255, 28, 0 },
        { -1, 160, 4, 0, -87, 61, 160, 16, 0, 0, 160, 0 },
    },
    { 0 },
};
