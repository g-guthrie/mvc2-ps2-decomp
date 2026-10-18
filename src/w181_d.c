typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004ABB74;

f32 func_001135B0(f32 x)
{
    extern f32 func_001132D0(f32);
    s32 hx, ix, k, i;
    f32 y, z, xx;
    f32 zero = 0.0f;
    do { union { f32 f; s32 w; } gf_u; gf_u.f = x; hx = gf_u.w; } while (0);
    ix = hx & 0x7FFFFFFF;
    if (ix <= 0x7FFFFF)
        return D_004ABB74;
    if (hx < 0)
        return (x - x) / zero;
    k = (hx >> 23) - 127;
    i = ((u32)k & 0x80000000) >> 31;
    hx = (hx & 0x7FFFFF) | ((0x7F - i) << 23);
    y = (f32)(k + i);
    do { union { f32 f; s32 w; } sf_u; sf_u.w = hx; xx = sf_u.f; } while (0);
    z = y * 7.9034153e-07f + 0.4342944920063019f * func_001132D0(xx);
    return z + y * 0.30102917551994324f;
}
