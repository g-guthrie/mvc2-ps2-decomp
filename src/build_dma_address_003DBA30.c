typedef unsigned int u32;
typedef int s32;
typedef unsigned int u128 __attribute__((mode(TI)));
u32 *func_003DBA30(u32 *a0, u32 a1, u32 a2, s32 a3)
{
    u32 lo = a2 & 0x0FFFFFFF;
    u32 hi = 0;
    if ((a2 & 0x70000000) == 0x70000000)
        hi = 0x80000000;
    *(u128 *)a0 = 0;
    a0[0] = a1 + 0x20000000;
    a0[1] = lo | hi;
    if (a3 == 1)
        a0[0] = a0[0] | 0x80000000;
    return a0 + 4;
}
