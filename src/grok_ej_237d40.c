typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern f32 func_00417500(s32);
extern f32 func_00417440(s32);

void func_00237D40(u8 *p, u8 a1)
{
    s16 ang = (s16)(((0x50 - a1) & 0x3F) << 10);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x68) + 1.6666666269302368f * (665600.0f * (1000.0f * func_00417500(ang)) / 100000.0f / 256.0f);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x6C) + 2.142857074737549f * (665600.0f * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
}
