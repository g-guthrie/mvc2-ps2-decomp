typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00456878[3];

void residual_00289020(u8 *p)
{
    jtbl_00456878[p[7]](p);
}
