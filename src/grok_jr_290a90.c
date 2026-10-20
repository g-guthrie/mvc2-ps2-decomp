typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004577F8[3];

void residual_00290A90(u8 *p)
{
    jtbl_004577F8[p[7]](p);
}
