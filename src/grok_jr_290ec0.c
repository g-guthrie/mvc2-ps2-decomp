typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00457818[3];

void residual_00290EC0(u8 *p)
{
    jtbl_00457818[p[7]](p);
}
