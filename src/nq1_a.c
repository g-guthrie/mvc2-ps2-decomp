typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_004B8380[];

void func_00355630(u8 *p)
{
    extern void func_001757E0(u8 *, u8, u8);
    u32 t = p[5];
    p[5] = t + 1;
    (*(u8 **)(p + 0x18))[0x2C2] = 0;
    p[0x169] = 0x15;
    p[0x168] = D_004B8380[p[0x20]];
    func_001757E0(p, p[0x169], p[0x168]);
}
