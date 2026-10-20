typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0045D4E0[];

void residual_00313AE0(u8 *p)
{
    jtbl_0045D4E0[p[6]](p);
}
