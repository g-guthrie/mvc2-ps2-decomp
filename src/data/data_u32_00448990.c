typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

/* Record pointed to by obj+0x1D4 (stored in func_00178680 area); readers (func_0016A6EC, func_0016ACB0, func_00183E34) read lhu at +4/+6/+8/+0xA. */
typedef struct HitRec990 {
    u32 hdr;
    u16 w[6];
} HitRec990;
typedef char HitRec990_size_check[(sizeof(HitRec990) == 16) ? 1 : -1];

HitRec990 data_u32_00448990 = { 0x00000000u, { 0x0000, 0x00FB, 0x0000, 0x0000, 0x0000, 0x0000 } };
