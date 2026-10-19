typedef unsigned char u8;

extern void (*D_00463D68[])(u8 *);

void residual_0036D7D0(u8 *p)
{
    u8 *o = *(u8 **)(p + 0x18);
    D_00463D68[p[5]](p);
    if (o[0x2b9]) {
        p[4]++;
        p[0x13c] = 0;
        o[0x2b8] = 0;
    }
}
