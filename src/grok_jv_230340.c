typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00451F60[3];

void residual_00230340(u8 *p)
{
    jtbl_00451F60[p[6]](p);
}
