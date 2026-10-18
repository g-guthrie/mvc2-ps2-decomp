typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define GET_HIGH_WORD(i, d) do { union { double w; struct { u32 lo; s32 hi; } p; } gh_u; gh_u.w = (d); (i) = gh_u.p.hi; } while (0)
double func_001165B0(double x) {
    extern double func_001142F8();
    extern double func_00115120();
    extern s32 func_00112818();
    double y[2];
    double z = 0.0;
    s32 n, ix;
    GET_HIGH_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) return func_001142F8(x, z);
    else if (ix >= 0x7ff00000) return x - x;
    else {
        n = func_00112818(x, y);
        switch (n & 3) {
        case 0: return func_001142F8(y[0], y[1]);
        case 1: return -func_00115120(y[0], y[1], 1);
        case 2: return -func_001142F8(y[0], y[1]);
        default: return func_00115120(y[0], y[1], 1);
        }
    }
}
