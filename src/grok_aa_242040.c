typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern s16 D_004C27A4 __attribute__((section(".sdata")));
extern void func_00175C00(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001A4450(u8 *, int);

void residual_00242040(u8 *p)
{
    unsigned int offset;
    u8 *q = p + 0x2B8;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[7]++;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(s16 *)(p + 0x1C) = 0;
    func_00175C00(p, 0);
    func_00185490(p);
    func_00183D10(p);
    if (D_004C27A4 < 3) {
        p[6] = 2;
        p[7] = 0;
        func_001757E0(p, 0x16, 8);
        return;
    }
    func_001A4450(p, 0);
    func_001A4450(p, 1);
    q[4] = 0;
    q[5] = 0xE;
    {
        int cmd = 0x3D;
        if (p[0x269] == 4 || p[0x269] == 5)
            cmd += 7;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x16, 7);
}
