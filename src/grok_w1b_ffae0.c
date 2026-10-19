typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void func_00175C00(u8 *, int);
extern void func_001FED30(u8 *);
extern void func_00183D10(u8 *);
extern void func_001933B0(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001FFBA0(u8 *);
extern u8 *D_004C2794;

void residual_001FFAE0(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    func_00175C00(p, 0);
    p[6]++;
    p[0x1B5] = 69;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001FED30(p);
    func_00183D10(p);
    *(s16 *)(p + 0x1C) = 114;
    func_001933B0(p);
    func_001757E0(p, 22, 25);
    func_001FFBA0(p);
}
