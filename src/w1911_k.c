typedef unsigned int u32;
typedef int s32;
typedef unsigned long u64;
u64 func_00118D78(double a) {
    double b;
    u32 hi, lo;
    u64 v;
    if (a < 0) return 0;
    b = (a / 4294967296.0);
    hi = (s32) b;
    v = hi;
    v <<= 32;
    a -= (double)v;
    if (a < 0) { lo = (s32) (-a); v -= lo; }
    else { lo = (s32) a; v += lo; }
    return v;
}
