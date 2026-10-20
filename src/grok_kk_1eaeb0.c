typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_004BFB58[] __attribute__((section(".sdata")));

void residual_001EAEB0(u8 *p)
{
    jtbl_004BFB58[p[6]](p, p + 696);
}
