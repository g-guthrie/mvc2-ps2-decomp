typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001F1C00(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_001266A0();
    u8 *q = p + 0x2B8;
    u8 *o;
    s32 t;
    s8 x;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        u32 u = p[7];
        p[7] = u + 1;
        func_001757E0(p, 0xF, 0x21);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        o = *(u8 **)(p + 0x1DC);
        o[0x20A] = 2;
        o[0x1B5] = *(s8 *)(p + 0x1B7) + 0x3D;
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x3D;
        x = *(s8 *)(q + 2);
        p[0x219] = x / 2 + 0x20;
    }
}
