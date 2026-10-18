typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00166130(u8 *a, s32 b) {
    extern s32 func_0016B250();
    extern void func_0016B0C0();
    extern s32 func_0016AC30();
    extern s32 func_00166C80();
    if (func_0016B250(a, 4) == 0) {
        return 0;
    }
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x460) = *(s32 *)(a + 0x4C8);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x464) = *(s32 *)(a + 0x4C8);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x468) = *(s32 *)(a + 0x4C8);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x46C) = *(s32 *)(a + 0x4C8);
    return func_00166C80(a, b, func_0016AC30(a, (u8 *)((s32)a + 0x460)));
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G7C;
extern G7C *D_004C2794;

void func_001EC320(u8 *p) {
    extern void func_00185490();
    extern void func_00183D10();
    extern void func_001757E0();
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
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    p[0x1B5] = 0x51;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    *(s16 *)(p + 0x1C0) = 0x10;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    func_001757E0(p, 0x16, 0);
}
