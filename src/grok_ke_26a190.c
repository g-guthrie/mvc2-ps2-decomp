typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00454490[8];

void residual_0026A190(u8 *p)
{
    jtbl_00454490[p[6]](p);
}
