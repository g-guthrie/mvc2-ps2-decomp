typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0040EE00(s32 *p, s32 i, s32 v)
{
    s32 lo = (v < -15) ? -15 : v;
    if (lo > 15) {
        lo = 15;
    }
    p[i + 14] = lo;
}

#define GET_FLOAT_WORD(i, d) do { union { f32 f; s32 w; } gf_u; gf_u.f = (d); (i) = gf_u.w; } while (0)
#define SET_FLOAT_WORD(d, i) do { union { f32 f; s32 w; } sf_u; sf_u.w = (i); (d) = sf_u.f; } while (0)
f32 func_00117078(f32 x)
{
    s32 ix;
    GET_FLOAT_WORD(ix, x);
    SET_FLOAT_WORD(x, ix & 0x7FFFFFFF);
    return x;
}
