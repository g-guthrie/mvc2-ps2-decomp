typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001FEFD0(u8 *p) {
    extern void func_003484A0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern s32 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q = p + 0x2B8;
    f32 a, b;
    u32 t;
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_003484A0(p, 1, 0);
        func_001E3210(p, 0x1E);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    if ((s8)func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        q[0xC] = 0;
        a = p[0x1E6] != 0 ? -1.6666666269302368f : 1.6666666269302368f;
        *(f32 *)(p + 0x5C) = a;
        b = p[0x1E6] != 0 ? 0.02604166604578495f : -0.02604166604578495f;
        *(f32 *)(p + 0x68) = b;
        *(u32 *)(p + 0x60) = 0x40F00000;
        *(u32 *)(p + 0x6C) = 0xBECDB6DB;
        func_001757E0(p, 0x15, 4);
    }
}
