typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00463310[8];

void residual_0035D4A0(u8 *p)
{
    jtbl_00463310[p[4]](p);
}
