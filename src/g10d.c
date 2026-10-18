typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *func_003DA750();
extern u8 *func_003DA780();
extern void func_00378690();
extern void func_00160990();
extern void func_003413B0();
extern s32 D_004C2838;
extern s32 D_004C283C;

void func_00341800(u8 *a, s32 b, s32 c, s32 d) {
    u8 *o = func_003DA750(0, d, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003413B0;
        *(s16 *)(o + 0xCC) = b + 1;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = c;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
        o[0x20] = b;
    }
}

void func_00160600(u8 *p) {
    u8 *o = func_003DA780(0, 10, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00160990;
        *(s16 *)(o + 0xCC) = 0xEF;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(s32 *)(o + 0xD0) = 11;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u32 *)(o + 0x3C) = 0x476A6000;
        *(s16 *)(o + 0x1C) = 0;
    }
}
extern void func_0016B0C0();
extern s32 func_00174170();
extern s8 D_004BF484[4];

s32 func_00165DD0(u8 *a, u8 *b) {
    s32 v;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 1);
    v = *(s32 *)(a + 0x4C8);
    if (v == 0) {
        v = D_004BF484[func_00174170() & 3];
    }
    *(s8 *)(a + 0x4B8) = v;
    return 1;
}
