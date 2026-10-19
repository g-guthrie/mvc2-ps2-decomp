typedef unsigned char u8;
typedef void (*DispatchFn2)(u8 *, void *);

extern DispatchFn2 jtbl_00451ED0[];

void residual_0022F160(u8 *p)
{
    jtbl_00451ED0[p[0x1FD]](p, p + 0x2B8);
}
