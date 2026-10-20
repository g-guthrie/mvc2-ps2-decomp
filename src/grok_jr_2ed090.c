typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0045B650[13];

void residual_002ED090(u8 *p)
{
    jtbl_0045B650[p[0x1FD]](p, p + 0x2B8);
}
