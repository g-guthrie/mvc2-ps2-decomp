typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C26D4 __attribute__((section(".sdata")));
extern u8 *D_004C26D8 __attribute__((section(".sdata")));
extern DispatchFn jtbl_0044B940[];

void func_001AD260(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);

    D_004C26D4 = p + 0xD0;
    D_004C26D8 = q + 0x2B8;
    jtbl_0044B940[p[0x20]](p);
}
