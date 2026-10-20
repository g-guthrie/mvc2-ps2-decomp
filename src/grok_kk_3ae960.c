typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00473C20[];

void func_003AE960(u8 *p, u8 *r)
{
    u8 *q = *(u8 **)(p + 24);
    *(s8 *)(r + 42) = *(s8 *)(q + 487);
    p[34] = q[34];
    jtbl_00473C20[p[32]](p, r);
}
