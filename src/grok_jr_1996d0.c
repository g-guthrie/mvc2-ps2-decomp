typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0044A6A0[];

void residual_001996D0(u8 *p)
{
    p[4]++;
    jtbl_0044A6A0[p[0x20]](p);
}
