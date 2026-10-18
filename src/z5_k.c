typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003DDDC0(f32 *m, f32 a, f32 b, f32 c) {
    extern f32 func_003DE790(f32);
    extern f32 func_003DE710(f32);
    f32 sa, ca, sb, cb, sc, cc;
    sa = func_003DE790(a);
    ca = func_003DE710(a);
    sb = func_003DE790(b);
    cb = func_003DE710(b);
    sc = func_003DE790(c);
    cc = func_003DE710(c);
    m[0] = cc * cb;
    {
        f32 t = sb * cc;
        m[4] = -sc * ca + sa * t;
        m[8] = sa * sc + ca * t;
    }
    m[1] = sc * cb;
    m[5] = sa * (sb * sc) + cc * ca;
    m[9] = -sa * cc + ca * (sb * sc);
    m[2] = -sb;
    m[6] = sa * cb;
    m[10] = cb * ca;
}

void func_002CEDB0(u8 *p) {
    f32 w4[4];
    f32 v;
    extern void func_00175700();
    extern void func_001830D0();
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) v = 16.6666660f; else v = -16.6666660f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = -0.625f; else v = 0.625f;
        *(f32 *)(p + 0x68) = v;
        p[0x404] = 0;
        p[0x405] = 0;
        *(u32 *)&w4[0] = 0xC2200000;
        *(u32 *)&w4[1] = 0x424DB6DB;
        *(u32 *)&w4[2] = 0;
        func_001830D0(p, w4, 1);
    }
}

void func_00324000(u8 *p) {
    f32 w4[4];
    s32 v;
    extern void func_00175700();
    extern void func_00175C00();
    extern void func_00176160();
    extern void func_001830D0();
    extern void func_00131AB0();
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if ((v = *(s8 *)(p + 0x150)) != 0) {
        if ((s8)v < 0) {
            func_00175C00(p, 1);
        } else {
            func_00176160(p, 0, *(s16 *)(p + 0x1C) + p[0x15B], 1);
        }
    }
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(s32 *)(p + 0x2D8) = 0x258;
        func_00175C00(p, 1);
        *(u32 *)&w4[0] = 0;
        *(u32 *)&w4[1] = 0x43092492;
        func_001830D0(p, w4, 1);
        func_00131AB0(p, (u8 *)((s32)p + 0x2D8), 6);
    }
}
