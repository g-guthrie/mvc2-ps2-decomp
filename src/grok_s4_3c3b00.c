typedef unsigned char u8;
typedef signed char s8;

extern void (*D_00475DE0[])(u8 *, u8 *);

void residual_003C3B00(u8 *p, u8 *q)
{
    D_00475DE0[p[4]](p, q);
    p[0x24] = (s8)q[0x24] + (s8)p[0x31];
    if ((s8)p[0x24] >= 8)
        p[0x24] = 7;
    if ((s8)p[0x24] < 0)
        p[0x24] = 0;
}
