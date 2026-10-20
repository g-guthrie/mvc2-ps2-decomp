typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00450D70[4];

void residual_00214D3C(u8 *p)
{
    jtbl_00450D70[p[6]](p);
}
