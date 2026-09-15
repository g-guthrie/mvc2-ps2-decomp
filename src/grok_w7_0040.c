typedef unsigned char u8;
typedef signed int s32;

s32 func_00420A00(s32 *p)
{
    s32 x = p[2];
    return (s32)((u8 *)p[4] + (x << 3) + 16);
}

s32 func_00420A20(s32 *p, s32 a1)
{
    s32 v = p[2] + a1;
    if (p[5] < v)
        return 0;
    p[2] = v;
    return 1;
}

void func_00416640(u8 *p)
{
    u8 *q = *(u8 **)(p + 8);
    if (q[19] == 5)
        q[18] &= 0x7f;
}
