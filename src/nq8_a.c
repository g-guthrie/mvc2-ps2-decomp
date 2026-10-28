typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

void func_002F9240(u8 *p, u8 *context)
{
    extern void func_00185490(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F92E0(u8 *, u8 *);
    p[7]++;
    func_00185490(p);
    func_0018C4B0(p, 5);
    func_00175C00(p, 0);
    if (p[0x20D] != 2) func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x15, 2);
    func_002F92E0(p, context);
}
