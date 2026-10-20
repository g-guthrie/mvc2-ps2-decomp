typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0045ADE0[3];

void residual_002E0790(u8 *p)
{
    jtbl_0045ADE0[p[6]](p);
}
