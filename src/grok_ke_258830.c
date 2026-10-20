typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00453720[5];

void residual_00258830(u8 *p)
{
    jtbl_00453720[p[7]](p);
}
