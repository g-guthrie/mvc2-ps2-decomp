typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern u8 *D_004C2A00 __attribute__((section(".sdata")));
extern DispatchFn jtbl_004726A0[];

void func_0039AD80(u8 *p, u8 *r)
{
    u8 *q = *(u8 **)(p + 24);
    D_004C2A00 = q + 696;
    jtbl_004726A0[p[4]](p, r);
}
