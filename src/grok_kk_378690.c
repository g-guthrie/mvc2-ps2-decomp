typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C298C __attribute__((section(".sdata")));
extern DispatchFn jtbl_004640E0[];

void func_00378690(u8 *p)
{
    D_004C298C = p + 208;
    jtbl_004640E0[p[4]](p);
}
