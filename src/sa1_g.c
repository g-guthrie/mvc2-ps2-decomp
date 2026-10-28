typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f32 func_00417440(u32);

void func_0033F790(u8 *p)
{
    switch (p[4]) { case 0:
    *(s16 *)(p + 0x1C) += 1;
    if (*(s16 *)(p + 0x1C) >= 0x168) *(s16 *)(p + 0x1C) = 0;
    *(u32 *)(p + 0x40) = (u32)(int)(0.5 + 65536.0 * (double)(-90.0f + 45.0f * func_00417440((u32)(int)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0) & 0xFFFF)) / 360.0) & 0xFFFF;
    break; default: break; }
}
