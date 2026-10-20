typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C29D0 __attribute__((section(".sdata")));
extern u8 *D_004C29D4 __attribute__((section(".sdata")));
extern DispatchFn jtbl_004721D0[];

void func_00392930(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C29D0 = p + 208;
    D_004C29D4 = q + 696;
    jtbl_004721D0[p[32]](p);
}
