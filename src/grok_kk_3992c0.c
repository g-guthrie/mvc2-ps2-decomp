typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C29F0 __attribute__((section(".sdata")));
extern u8 *D_004C29F4 __attribute__((section(".sdata")));
extern DispatchFn jtbl_004725E0[];

void func_003992C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C29F0 = p + 208;
    D_004C29F4 = q + 696;
    jtbl_004725E0[p[4]](p);
}
