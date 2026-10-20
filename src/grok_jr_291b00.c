typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_004578B0[5];
extern DispatchFn jtbl_004578D0[5];

void residual_00291B00(u8 *p, u8 *c)
{
    jtbl_004578B0[c[0x18]](p, c);
}

void func_00291B20(u8 *p, u8 *c)
{
    jtbl_004578D0[c[0x18]](p, c);
}
