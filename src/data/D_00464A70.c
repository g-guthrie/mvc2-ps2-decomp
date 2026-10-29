typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
/* func_00388930 reads lh +0, lh +2, lbu +4, lb +5, lbu +6 of D_00464A70 + 8 * (u8 +0x20).
 * That byte is set by func_003888B0 from its second argument, which its callers pass as
 * the constants 0..0xD: 14 records. */
typedef struct { s16 x; s16 y; u8 b4; s8 b5; u8 b6; u8 b7; } Rec_00464A70;
typedef char Rec_00464A70_size_check[(sizeof(Rec_00464A70) == 8) ? 1 : -1];
Rec_00464A70 D_00464A70[14] = {
    { 0, 0, 0x00, -2, 0x09, 0x00 },
    { 0, 0, 0x00, -4, 0x0B, 0x00 },
    { 0, 0, 0x00, -1, 0x0C, 0x00 },
    { 0, 0, 0x00, 1, 0x0E, 0x00 },
    { 0, 0, 0x00, -3, 0x0D, 0x00 },
    { 7, 9, 0x00, 1, 0x26, 0x00 },
    { -1, 16, 0x00, 2, 0x26, 0x00 },
    { 15, 16, 0x00, 2, 0x26, 0x00 },
    { 16, 16, 0x00, 1, 0x27, 0x00 },
    { 8, 32, 0x00, 2, 0x27, 0x00 },
    { -4, 24, 0x00, 2, 0x27, 0x00 },
    { -20, 4, 0x01, 1, 0x27, 0x00 },
    { -16, 16, 0x01, 2, 0x27, 0x00 },
    { -32, 16, 0x01, 2, 0x27, 0x00 },
};
