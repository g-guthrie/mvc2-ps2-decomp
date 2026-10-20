typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0044D9A0[];

void residual_001CA5A0(u8 *p)
{
    jtbl_0044D9A0[p[33]](p);
}
