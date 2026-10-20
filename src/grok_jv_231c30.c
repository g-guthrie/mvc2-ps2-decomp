typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);
typedef void (*DispatchFn2)(u8 *, u8 *);

extern DispatchFn jtbl_00451FA8[3];
extern DispatchFn2 jtbl_00451FB8[3];

void residual_00231C2C(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    jtbl_00451FA8[p[7]](p);
}

void func_00231C60(u8 *p, u8 *unused)
{
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    jtbl_00451FB8[p[7]](p, unused);
}
