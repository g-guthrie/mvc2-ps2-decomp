typedef unsigned char u8;
typedef signed char s8;

extern void (*jtbl_004C85F0[2])(void);

void residual_001B26C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    ((void (*)(u8 *))jtbl_004C85F0[p[5]])(p);
    if ((s8)q[0x1B3] != 0) {
        p[4]++;
        p[0x13C] = 0;
    }
}
