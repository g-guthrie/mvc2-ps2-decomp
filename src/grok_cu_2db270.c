typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00186A20(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_00176160(u8 *, int, int, int);
extern u8 *D_004C2794;

void residual_002DB270(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00185490(p);
    *(s16 *)(p + 0x1C) = 0x28;
    p[0x1B5] = 0x5A;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_00186A20(p);
    func_00183D10(p);
    {
        u32 bits = 0x40D55555;
        f32 d = *(f32 *)&bits;
        if (p[0x1E6])
            d = -d;
        *(f32 *)(p + 0x5C) = d;
    }
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 21, 23);
    *(u32 *)(p + 0x2F8) = 0x60;
    func_00175C00(p, 1);
    func_00176160(p, 3, 18, 1);
}
