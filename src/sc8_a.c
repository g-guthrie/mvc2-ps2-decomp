typedef unsigned char u8;
typedef signed int s32;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0044ECB0[];

void func_001DCF20(u8 *p)
{
    u8 *q = *(u8 **)(p + 0xD0);

    *(s32 *)(q + 0x2CC) = 4;
    jtbl_0044ECB0[p[4]](p, q);
}
