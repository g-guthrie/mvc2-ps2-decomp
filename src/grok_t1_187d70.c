typedef unsigned char u8;
typedef signed int s32;

extern int func_00186CE0(u8 *, int);

s32 func_00187D70(u8 *p)
{
    u8 *q;
    int k;

    if (*(int *)(p + 0x428) & 0x07000000)
        return 0;
    if (p[0x36D] != 1)
        return 0;
    q = p + 0x368;
    q[5] = 0;
    if (q[4] == 0)
        k = 10;
    else if (p[1] == 1)
        return 0;
    else
        k = 11;
    if (p[0x1E4] == (u8)k)
        return 0;
    return (u8)func_00186CE0(p, k);
}
