typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C29AC __attribute__((section(".sdata")));
extern u8 *D_004C29A8 __attribute__((section(".sdata")));
extern DispatchFn jtbl_00464670[];

void func_00383C90(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C29AC = p + 208;
    D_004C29A8 = q + 696;
    jtbl_00464670[p[32]](p);
}
