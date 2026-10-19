typedef unsigned char u8;
typedef void (*OwnerDispatchFn)(u8 *, void *);

extern OwnerDispatchFn jtbl_00475FB0[22];

void func_003C5570(u8 *p, void *owner)
{
    ((u8 *)owner)[0x2BF] = 2;
    ((u8 *)owner)[0x205] = 2;
    jtbl_00475FB0[p[4]](p, owner);
}

void func_003C5BC0(u8 *p, void *owner)
{
    ((u8 *)owner)[0x2BF] = 2;
    ((u8 *)owner)[0x205] = 2;
    jtbl_00475FB0[p[4] + 4](p, owner);
}

void func_003C5FC0(u8 *p, void *owner)
{
    ((u8 *)owner)[0x2BF] = 2;
    ((u8 *)owner)[0x205] = 2;
    jtbl_00475FB0[p[4] + 8](p, owner);
}
