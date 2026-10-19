typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175C00(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794 __attribute__((section(".sdata")));

void func_002657E0(u8 *p)
{
    func_00175C00(p, 0);
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 16.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 64.0f;
        *(u32 *)(p + 0x68) = 0;
    }
    func_00185490(p);
    p[0x1B5] = 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    if (p[0x20D] == 0) {
        func_00183D10(p);
        func_001757E0(p, 0x16, 0);
    } else {
        func_001757E0(p, 0x16, 0x40);
    }
}
