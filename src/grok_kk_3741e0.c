typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00463EE0[];

void func_003741E0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    q[510] = 1;
    jtbl_00463EE0[p[6]](p);
}
