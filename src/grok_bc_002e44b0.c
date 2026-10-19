typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00175C00(u8 *, int);
extern int func_00176160(u8 *, int, int, int);

void func_002E44B0(u8 *p, u8 *q)
{
    if (*(s8 *)(q + 9) == 0)
        return;
    {
        u8 x = p[0x1E4];
        if (x == 0x1C || x == 0x16 || *(s16 *)(p + 0x434) == 0)
            *(s16 *)(q + 10) = 1;
    }
    if ((*(s16 *)(q + 10) = *(s16 *)(q + 10) - 1) == 0) {
        q[9] = 0;
        q[13] = 0;
        q[14] = 0;
        func_00175C00(p, 0);
        return;
    }
    if ((*(s8 *)(q + 14) = *(s8 *)(q + 14) - 1) == 0) {
        s8 old;
        q[14] = 8;
        func_00176160(p, 0, *(s8 *)(q + 15) + ((p[37] * 3) << 4) + 37, 2);
        old = *(s8 *)(q + 15);
        q[15] = old + *(s8 *)(q + 9);
        if (*(s8 *)(q + 15) == 0 || *(s8 *)(q + 15) == 4)
            q[9] = -*(s8 *)(q + 9);
    }
}
