typedef unsigned char u8;
typedef void (*DispatchFn2)(u8 *, u8 *);

extern DispatchFn2 const jtbl_004BF580[2] __attribute__((section(".sdata")));

void func_001966C0(u8 *p, u8 *q)
{
    u8 *dst = p + 0x88;
    u8 *src = q + 0x2B8;

    if (q[0x1E4] != 0x16) {
        src[0xC] = 0;
        dst[0] = 0;
    }
    jtbl_004BF580[p[5]](p, q);
}
