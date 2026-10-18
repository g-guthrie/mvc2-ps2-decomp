typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define GET_FLOAT_WORD(i, d) do { union { float f; u32 w; } gf_u; gf_u.f = (d); (i) = gf_u.w; } while (0)
#define SET_FLOAT_WORD(d, i) do { union { float f; u32 w; } sf_u; sf_u.w = (i); (d) = sf_u.f; } while (0)

extern float func_00116F60(float, float);

float func_00117178(float x, s32 n) {
    u32 ix;
    s32 k;
    float t;
    GET_FLOAT_WORD(ix, x);
    if ((ix & 0x7FFFFFFF) > 0x7FFFFF) {
        k = (ix & 0x7FFFFFFF) >> 23;
        k += n;
        if (k >= 256) {
            t = 1.0e30f;
            return func_00116F60(t, x) * t;
        }
        if (k > 0) {
            SET_FLOAT_WORD(x, (ix & 0x807FFFFF) | (k << 23));
            return x;
        }
        if (n > 50000) {
            t = 1.0e30f;
            return func_00116F60(t, x) * t;
        } else {
            t = 1.0e-30f;
            return func_00116F60(t, x) * t;
        }
    }
    return x;
}
