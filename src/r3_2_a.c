typedef unsigned long u64;
typedef long s64;
double func_001001E0(s64 a)
{
    double d;
    if (a > 0)
        return (double)a;
    d = (double)(s64)(((u64)a >> 1) | (a & 1));
    return d + d;
}
