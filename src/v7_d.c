typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 *D_004C2794;
extern void func_0022F190();
extern void func_001757E0();
extern void func_00183D10();
extern void func_00230B50();

void func_00230BF0(u8 *p, u8 *q) {
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    {
        u32 t = p[7];
        p[7] = t + 1;
    }
    q[0x13] = 0;
    func_0022F190(p);
    p[0x169] = 0x16;
    p[0x168] = 2;
    func_001757E0(p, p[0x169], p[0x168]);
    func_00183D10(p);
    p[0x1B5] = 0x4C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794[p[2] + 0x3E] += 1;
    func_00230B50(p, q);
}

extern void func_00185490();
extern void func_001E15A0();

void func_00323F30(u8 *p) {
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    func_00185490(p);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(s16 *)(p + 0x1C) = p[0x25] * 5;
    p[0x1B5] = 0x52;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794[p[2] + 0x3E] += 1;
    func_001E15A0(p);
    func_001757E0(p, 0x16, 5);
}
