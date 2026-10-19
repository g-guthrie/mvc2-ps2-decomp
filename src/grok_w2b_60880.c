typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void residual_00260880(u8 *p)
{
    p[6]++;
    p[0x1B5] = 65;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 0x430);
    func_00185490(p);
    func_00175C00(p, 0);
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    func_00183D10(p);
    p[35] = 0;
    p[33] = 0;
    *(s16 *)(p + 28) = 0;
    *(s16 *)(p + 30) = 0;
    func_001757E0(p, 22, 10);
}
