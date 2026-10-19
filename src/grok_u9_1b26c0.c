typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BF860[2];

void residual_001B26C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    jtbl_004BF860[p[5]](p);
    if ((s8)q[0x1B3] != 0) {
        p[4]++;
        p[0x13C] = 0;
    }
}
