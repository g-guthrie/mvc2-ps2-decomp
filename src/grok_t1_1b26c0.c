typedef unsigned char u8;
typedef signed char s8;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_004C85F0[];

void residual_001B26C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    jtbl_004C85F0[p[5]](p);
    if ((s8)q[0x1B3] != 0) {
        p[4] = p[4] + 1;
        p[0x13C] = 0;
    }
}
