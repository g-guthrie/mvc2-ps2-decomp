typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, s32, s32);
extern void func_00176160(u8 *, s32, s32, s32);

void func_001B5700(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    {
        unsigned int t = p[6];
        p[6] = t + 1;
    }
    func_001757E0(p, 0x16, 0x39);
    *(s8 *)(p + 0x24) = 7;
    func_00176160(q, 2, 0xC, 2);
    *(f32 *)(p + 0x118) = 0.5f;
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50) + 0.30000001192092896f;
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54) + 0.20000000298023224f;
    *(s16 *)(p + 0x1C) = 6;
    *(f32 *)(p + 0x5C) = 0.039999999105930328f;
    *(f32 *)(p + 0x68) = -0.0040000001899898052f;
    *(f32 *)(p + 0x60) = 0.039999999105930328f;
    *(f32 *)(p + 0x6C) = -0.0040000001899898052f;
    *(s32 *)(p + 0x70) = 0xC0AB6DB6;
}
