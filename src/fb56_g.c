typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f32 sqrtf(f32);
extern f32 func_00116FA0(f32);
extern s32 dptoli(f64);


void func_003F9698(s32 a, s32 b, s16 *o1, s16 *o2)
{
    f32 sq;
    f32 r, f, g;
    f64 d, s2, s3, q;

    sq = sqrtf(2.0f);
    d = (f64)a * 6.28318530717958 / (f64)b;
    r = func_00116FA0((f32)d);
    s3 = (f64)(sq - r);
    s2 = (f64)sqrtf(2.0f) - 1.0;
    f = (f32)((s3 + s2) * (s3 - s2));
    g = sqrtf(f);
    q = (s3 - (f64)g) / s2;
    *o1 = (s16)dptoli((q + q) * 4096.0);
    *o2 = (s16)dptoli((0.0 - q) * q * 4096.0);
}
