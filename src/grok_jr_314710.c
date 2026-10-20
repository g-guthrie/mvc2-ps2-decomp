typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C16F0[2] __attribute__((section(".sdata")));
extern DispatchFn jtbl_004C16F8[2] __attribute__((section(".sdata")));

void func_00314710(u8 *p)
{
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    jtbl_004C16F0[p[7]](p);
}

void func_00314740(u8 *p)
{
    jtbl_004C16F8[p[6]](p);
}
