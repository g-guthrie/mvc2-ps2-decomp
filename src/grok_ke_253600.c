typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004534C0[5];

void residual_00253600(u8 *p)
{
    jtbl_004534C0[p[6]](p);
}
