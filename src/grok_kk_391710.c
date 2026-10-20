typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C29C8 __attribute__((section(".sdata")));
extern u8 *D_004C29CC __attribute__((section(".sdata")));
extern DispatchFn jtbl_00471B80[];

void func_00391710(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C29C8 = p + 208;
    D_004C29CC = q + 696;
    jtbl_00471B80[p[32]](p);
}
