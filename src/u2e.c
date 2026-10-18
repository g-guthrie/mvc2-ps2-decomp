typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define GET_FLOAT_WORD(i, d) do { union { float f; s32 w; } gf_u; gf_u.f = (d); (i) = gf_u.w; } while (0)
#define SET_FLOAT_WORD(d, i) do { union { float f; s32 w; } sf_u; sf_u.w = (i); (d) = sf_u.f; } while (0)

static const float huge = 1.0e30f;

float func_001170A0(float x) {
    s32 i0, j0;
    u32 i, ix;
    GET_FLOAT_WORD(i0, x);
    ix = i0 & 0x7FFFFFFF;
    j0 = (ix >> 23) - 0x7F;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge + x > (float)0.0) {
                if (i0 >= 0) {
                    i0 = 0;
                } else if (ix > 0x7FFFFF) {
                    i0 = 0xBF800000;
                }
            }
        } else {
            i = 0x007FFFFF >> j0;
            if ((i0 & i) == 0) return x;
            if (huge + x > (float)0.0) {
                if (i0 < 0) i0 += 0x00800000 >> j0;
                i0 &= ~i;
            }
        }
    } else {
        return x;
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}
