typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C2714 __attribute__((section(".sdata")));
extern DispatchFn jtbl_004BFA68[] __attribute__((section(".sdata")));

void func_001CE500(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    D_004C2714 = q + 696;
    jtbl_004BFA68[p[32]](p);
}
