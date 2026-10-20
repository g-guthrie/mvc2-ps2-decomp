typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C2710 __attribute__((section(".sdata")));
extern u8 *D_004C270C __attribute__((section(".sdata")));
extern DispatchFn jtbl_0044DCD0[];

void func_001CBE90(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C2710 = p + 208;
    D_004C270C = q + 696;
    jtbl_0044DCD0[p[32]](p);
}
