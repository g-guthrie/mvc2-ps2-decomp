typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C29DC __attribute__((section(".sdata")));
extern u8 *D_004C29D8 __attribute__((section(".sdata")));
extern DispatchFn jtbl_004722B0[];

void func_003947F0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C29DC = p + 208;
    D_004C29D8 = q + 696;
    jtbl_004722B0[p[32]](p);
}
