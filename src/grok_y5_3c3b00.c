typedef unsigned char u8;
typedef signed char s8;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00475DE0[2];

void residual_003C3B00(u8 *p, u8 *q)
{
    jtbl_00475DE0[p[4]](p);
    p[0x24] = (s8)q[0x24] + (s8)p[0x31];
    if ((s8)p[0x24] > 7)
        p[0x24] = 7;
    if ((s8)p[0x24] < 0)
        p[0x24] = 0;
}
