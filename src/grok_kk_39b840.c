typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C2A08 __attribute__((section(".sdata")));
extern u8 *D_004C2A04 __attribute__((section(".sdata")));
extern DispatchFn jtbl_004726E0[];

void func_0039B840(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C2A08 = p + 208;
    D_004C2A04 = q + 696;
    p[435] = 0;
    jtbl_004726E0[p[4]](p);
}
