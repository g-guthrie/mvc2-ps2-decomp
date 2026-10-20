typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00453350[8];

void residual_00250550(u8 *p)
{
    jtbl_00453350[p[7]](p, p + 0x2B8);
}
