typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern u8 *D_004C29E0 __attribute__((section(".sdata")));
extern u8 *D_004C29E4 __attribute__((section(".sdata")));
extern DispatchFn jtbl_00472540[];

void func_003985C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C29E0 = p + 208;
    D_004C29E4 = q + 696;
    jtbl_00472540[p[4]](p, q);
}
