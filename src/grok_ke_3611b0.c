typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004634F0[7];

void residual_003611B0(u8 *p)
{
    jtbl_004634F0[p[4]](p);
}
