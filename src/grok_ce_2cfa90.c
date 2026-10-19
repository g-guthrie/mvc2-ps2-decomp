typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_002CFA20(u8 *);
extern u8 *D_004C2794;

void residual_002CFA90(u8 *p)
{
    p[6]++;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    *(s16 *)(p + 0x1C) = 0;
    func_00185490(p);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    {
        u32 bits = 0xC0F00000;
        if (p[0x1E6])
            bits = 0x40F00000;
        *(u32 *)(p + 0x5C) = bits;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    p[0x1B5] = 0x58;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_001757E0(p, 22, 5);
    func_002CFA20(p);
}
