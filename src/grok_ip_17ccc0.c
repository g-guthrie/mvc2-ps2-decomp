typedef unsigned char u8;
typedef signed int s32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BF4F0[2];
extern void func_00186900(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);

void func_0017CCC0(u8 *p)
{
    p[0x201] = 2;
    p[0x208] = 2;
    jtbl_004BF4F0[p[6]](p);
}

void func_0017CCF0(u8 *p)
{
    p[6]++;
    p[0x211] = 0;
    p[0x13C] = 1;
    func_00186900(p);
    p[0x1F5] = 0x50;
    func_001757E0(p, 1, 1);
    func_00175C00(p, 1);
}
