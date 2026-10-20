/* Actor motion uses signed 16.16 pairs and the native PS2 coordinate scales. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern s32 data_u32_00461EF0[];
extern int func_001757E0(u8 *, s32, s32);

void func_003486B0(u8 *p, u8 *q)
{
    *(u32 *)(p + 0x14C) = 0x20202424;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x38;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    *(u32 *)(p + 0x34) = 0x42555555;
    *(f32 *)(p + 0x5C) = (1.6666666269302368f * (f32)data_u32_00461EF0[p[0x1B7] * 2]) / 65536.0f;
    *(f32 *)(p + 0x60) = -((2.1428570747375488f * (f32)data_u32_00461EF0[p[0x1B7] * 2 + 1]) / 65536.0f);
    if (*(s16 *)(p + 0x140) != 0)
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + *(f32 *)(q + 0x34);
    else {
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34) + *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x38) = 137.14285278320312f + *(f32 *)(q + 0x38);
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x68) = 0;
    p[0x169] = 0x15;
    p[0x168] = 0xD;
    func_001757E0(p, p[0x169], p[0x168]);
}
