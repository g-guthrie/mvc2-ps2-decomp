typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00452800[19];

void residual_0023E87C(u8 *p)
{
    jtbl_00452800[p[0x1FD]](p, p + 0x2B8);
}
