typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004568D0[5];

void residual_00289600(u8 *p)
{
    jtbl_004568D0[p[7]](p);
}
