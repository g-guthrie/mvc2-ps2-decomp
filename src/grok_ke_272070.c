typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004549B0[5];

void residual_00272070(u8 *p)
{
    jtbl_004549B0[p[7]](p);
}
