typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00456980[5];
extern DispatchFn jtbl_004569A0[5];

void residual_0028A790(u8 *p, u8 *c)
{
    jtbl_00456980[c[0x18]](p, c);
}

void func_0028A7B0(u8 *p, u8 *c)
{
    jtbl_004569A0[c[0x18]](p, c);
}
