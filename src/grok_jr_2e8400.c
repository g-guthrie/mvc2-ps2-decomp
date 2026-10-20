typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0045B358[3];

void residual_002E8400(u8 *p)
{
    jtbl_0045B358[p[6]](p);
}
