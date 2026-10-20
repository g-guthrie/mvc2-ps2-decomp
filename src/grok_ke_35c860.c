typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004632C0[7];

void residual_0035C860(u8 *p)
{
    jtbl_004632C0[p[4]](p);
}
