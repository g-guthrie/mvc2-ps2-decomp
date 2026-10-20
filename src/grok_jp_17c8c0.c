typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BF4D8[10] __attribute__((section(".sdata")));
extern void func_001866A0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);

void func_0017C8C0(u8 *p)
{
    p[0x201] = 2;
    p[0x208] = 2;
    p[0x405] = 2;
    jtbl_004BF4D8[p[6]](p);
}
