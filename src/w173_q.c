typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001DD130(u8 *p)
{
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, u8);
    s16 r;
    s32 k;
    r = func_00174170() & 0x3F;
    if (*(f32 *)(p + 0x5C) > 0.0f) r = -r;
    *(f32 *)(p + 0x5C) = 1.66666662693f * (f32)r / 256.0f;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)(u32)(((func_00174170() & 0x3F) - 0x20) << 4) / 256.0f;
    *(s16 *)(p + 0x1C) = (func_00174170() & 0x1F) + 8;
    k = 6;
    if ((func_00174170() & 3) == 0) k = 7;
    func_001757E0(p, 0x17, k);
}
