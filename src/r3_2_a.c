typedef unsigned long u64;
typedef long s64;
extern u64 __floatdidf(s64);
extern u64 func_00119510(u64, u64);
u64 func_001001E0(s64 a)
{
    u64 d;
    if (a > 0)
        return __floatdidf(a);
    d = __floatdidf(((u64)a >> 1) | (a & 1));
    return func_00119510(d, d);
}
