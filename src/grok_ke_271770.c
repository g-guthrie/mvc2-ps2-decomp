typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00454910[6];

void residual_00271770(u8 *p)
{
    jtbl_00454910[p[7]](p);
}
