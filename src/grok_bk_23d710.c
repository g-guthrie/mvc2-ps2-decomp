typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, s32);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0023D800(u8 *, u8 *);
extern u8 *D_004C2794;

void residual_0023D710(u8 *p, u8 *q)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    p[0x1B5] = 0x3D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    p[0x169] = 0x16;
    p[0x168] = 0;
    func_001757E0(p, p[0x169], p[0x168]);
    func_0023D800(p, q);
}
