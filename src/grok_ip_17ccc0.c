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
