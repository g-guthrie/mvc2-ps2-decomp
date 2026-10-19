typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_002FEB80(u8 *, u8 *);

void residual_002FEA70(u8 *p, u8 *q)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    if (p[0x20D] != 2) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D10(p);
    }
    q[7] = 0;
    q[8] = 1;
    q[9] = 0;
    p[0x1B5] = 0x33;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x60) = 0x41CDB6DB;
    func_001757E0(p, 0x16, 0);
    *(s16 *)(p + 0x1C) = 0x32;
    func_002FEB80(p, q);
}
