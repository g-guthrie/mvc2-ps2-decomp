typedef unsigned char u8;
typedef signed int s32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BF4E8[2];
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);

void func_0017CB40(u8 *p)
{
    p[0x201] = 2;
    p[0x208] = 2;
    p[0x405] = 2;
    jtbl_004BF4E8[p[6]](p);
}

void func_0017CB70(u8 *p)
{
    p[0x404] = 0xFF;
    p[0x405] = 0x10;
    p[6]++;
    p[0x211] = 0;
    p[0x13C] = 1;
    p[0x1F5] = 0x50;
    func_001757E0(p, 1, 1);
    func_00175C00(p, 1);
}
