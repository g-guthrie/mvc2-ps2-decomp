typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f32 func_00417440(u16);

void func_0033A920(u8 *p)
{
    f32 s, v;
    s32 sign;
    s16 h = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = h;
    if (!(h < 360)) *(s16 *)(p + 0x1C) = 0;
    s = func_00417440((s32)(0.5 + 65536.0 * (f64)*(s16 *)(p + 0x1C) / 360.0));
    sign = (p[0x20] != 0) ? 1 : -1;
    v = 14.0f * (f32)sign * s;
    *(u32 *)(p + 0x40) = (u32)(s32)(0.5 + 65536.0 * (f64)v / 360.0) & 0xFFFF;
}
