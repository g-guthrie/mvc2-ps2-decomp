typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern f32 func_00417440(s32);

void func_003CD610(u8 *p, s32 n)
{
    s16 ang = (s16)(((0x28 - p[0x22]) & 0x1F) << 11);
    *(f32 *)(p + 0x38) += 2.14285707f * (256.0f * (f32)n * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
}
