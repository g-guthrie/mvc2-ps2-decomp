typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00453390[8];

void residual_00251120(u8 *p)
{
    jtbl_00453390[p[7]](p);
}
