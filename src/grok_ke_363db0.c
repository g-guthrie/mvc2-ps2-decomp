typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00463720[4];

void residual_00363DB0(u8 *p)
{
    jtbl_00463720[p[5]](p);
}
