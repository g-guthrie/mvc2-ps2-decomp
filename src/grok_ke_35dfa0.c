typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00463370[15];

void residual_0035DFA0(u8 *p)
{
    jtbl_00463370[p[4]](p);
}
