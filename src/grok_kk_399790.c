typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C29FC __attribute__((section(".sdata")));
extern u8 *D_004C29F8 __attribute__((section(".sdata")));
extern DispatchFn jtbl_004725F0[];

void func_00399790(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C29FC = p + 208;
    D_004C29F8 = q + 696;
    jtbl_004725F0[p[32]](p);
}
