typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00461FA0[];

void func_0034A720(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    if (p[4] < 2) {
        if (q[484] != 29)
            p[4] = 2;
    }
    jtbl_00461FA0[p[4]](p, q);
}
