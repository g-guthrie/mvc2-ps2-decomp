typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_003A2250(u8 *p) {
    extern void func_003DAA40();
    extern void func_00174910();
    extern void func_00175700();
    extern s32 func_00174240();
    extern void func_001E7F60();
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_003DAA40(p);
        return;
    }
    func_00174910(p, *(s16 *)(p + 0xD0));
    func_00175700(p);
    if (func_00174240(p) != 0) {
        func_001E7F60(p);
    } else {
        func_003DAA40(p);
    }
}

void func_001D4750(u8 *a, u8 *b) {
    extern s32 func_00175700();
    u8 *q = b + 0x2B8;
    if (a[5] == 0) {
        if (b[0x1E4] == 0xB) {
            func_00175700(a);
            if (*(s8 *)(a + 0x151) != 0) {
                u32 t = a[5];
                a[5] = t + 1;
                a[0x151] = 0;
            }
        } else {
            a[4] = 2;
            a[0x13C] = 0;
        }
    } else {
        s8 r;
        a[0x24] = 7;
        *(V3 *)(a + 0x34) = *(V3 *)(b + 0x34);
        r = func_00175700(a);
        if (r < 0) {
            a[4] = 2;
            a[0x13C] = 0;
        } else if (*(s8 *)(a + 0x151) != 0) {
            a[4] = 2;
            a[0x13C] = 0;
            *q = 1;
        }
    }
}

void func_00265BE0(u8 *a) {
    extern void func_00175700();
    extern s32 func_00185980();
    extern void func_00185640();
    extern void func_001757E0();
    extern void func_001B53E0();
    s16 h;
    func_00175700(a);
    if (*(s8 *)(a + 0x1B2) != 0) {
        if (func_00185980(a) != 0) {
            a[0x1FE] = 1;
            a[0x20B] = 0xC3;
            func_00185640(a, *(s32 *)(a + 0x1C4));
            return;
        }
        { u32 t = a[6]; a[6] = t + 1; }
        func_001757E0(a, 0x15, 0x11);
        func_001B53E0(a, 0x23, 5);
    }
    h = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = h;
    if (h <= 0) {
        { u32 t = a[6]; a[6] = t + 1; }
        func_001757E0(a, 0x15, 0x11);
        func_001B53E0(a, 0x23, 5);
    }
}

void func_002BD7F0(u8 *a) {
    extern void func_00175700();
    extern void func_001E3A40();
    f32 *p5c, *p60, *p68, *p6c;
    a[0x1FE] = 1;
    a[0x201] = 2;
    a[0x209] = 2;
    if (*(s8 *)(a + 0x151) == 0) func_00175700(a);
    p5c = (f32 *)(a + 0x5C);
    p68 = (f32 *)(a + 0x68);
    p60 = (f32 *)(a + 0x60);
    p6c = (f32 *)(a + 0x6C);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (*(f32 *)(a + 0x38) <= *(f32 *)(a + 0x430)) {
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        a[0x20D] = 0;
        *(s32 *)p5c = 0;
        *(s32 *)p60 = 0;
        *(s32 *)p68 = 0;
        *(s32 *)p6c = 0;
        if (*(s8 *)(a + 0x151) != 0) {
            u32 t = a[6];
            a[6] = t + 1;
            a[0x151] = 0;
            func_001E3A40(a);
        }
    }
}

s32 func_00165340(u8 *a, u8 *b) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern void func_00186CE0();
    extern s32 func_001640A0();
    s32 t;
    if (func_0016B240(a, 7) == 0) return 0;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 1);
    a[0x22] = *(s32 *)(a + 0x4C8) >> 2;
    *(s32 *)(a + 0x46C) = *(s32 *)(a + 0x4C8) << 8;
    t = *(s32 *)(a + 0x46C);
    if ((t & 0xC00) != 0) {
        *(s32 *)(a + 0x46C) = t ^ (a[0x1E6] * 3 << 10);
    }
    func_0016B0C0(a, b, 3);
    {
        u32 c = a[0x451];
        a[0x451] = c + 1;
    }
    *(f32 *)(a + 0x460) = *(f32 *)(a + 0x4C8);
    *(f32 *)(a + 0x464) = *(f32 *)(a + 0x34);
    *(s32 *)(a + 0x468) = 0x1A;
    *(s16 *)(a + 0x4F0) = *(s16 *)(a + 0x46C);
    *(s16 *)(a + 0x20E) = *(s16 *)(a + 0x46C);
    func_00186CE0(a, 0x1A);
    return func_001640A0(a, b);
}

void func_002C8A00(u8 *a) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *p5c, *p60, *p68, *p6c;
    p5c = (f32 *)(a + 0x5C);
    p68 = (f32 *)(a + 0x68);
    p60 = (f32 *)(a + 0x60);
    p6c = (f32 *)(a + 0x6C);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_00175700(a);
    if (*(f32 *)(a + 0x38) > *(f32 *)(a + 0x430)) {
        if (*(s8 *)(a + 0x1B2) != 0) {
            u32 t = a[6];
            a[6] = t + 1;
        }
        return;
    }
    {
        a[6] = 8;
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        a[0x20D] = 1;
        *(s32 *)p5c = 0;
        *(s32 *)p60 = 0;
        *(s32 *)p68 = 0;
        *(s32 *)p6c = 0;
        func_00183d50(a);
        func_001757E0(a, 0x15, 0xC);
    }
}

void func_003CC1C0(u8 *a, u8 *b) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00185870();
    extern void func_00182C30();
    u8 *o = *(u8 **)(a + 0x1C4);
    f32 z = 0.0f;
    func_00175700(a);
    if (*(s8 *)(o + 0x1B4) == 0) {
        u32 t = a[6];
        a[6] = t + 1;
        func_001757E0(o, 0xE, 0);
        func_00185870(a, o);
        *(s32 *)(a + 0xD4) = *(s32 *)(b + 0x1DC);
        *(s16 *)(a + 0x1C) = 0x78;
        *(s16 *)(a + 0x1E) = 0x3C;
        func_00182C30(*(s32 *)(b + 0x1DC), 1);
        o[0x20A] = 6;
        b[0x20B] = 0xC2;
        o[0x20B] = 0xC2;
        b[0x1FE] = 1;
        *(s8 *)(b + 0x16A) = -1;
        if (o[0x20D] == 2) {
            *(f32 *)(o + 0x5C) /= 4.0f;
            *(f32 *)(o + 0x68) /= 4.0f;
            if (*(f32 *)(o + 0x60) > z) {
                *(f32 *)(o + 0x60) /= 4.0f;
            }
            *(u32 *)(o + 0x6C) = 0xBF4DB6DB;
        }
    }
}

void func_002248B0(u8 *a) {
    extern void func_00183d50();
    extern void func_003569A0(u8 *, u8);
    extern s8 func_00175700();
    extern void func_00184540();
    extern void func_001843A0();
    f32 *p5c, *p60, *p68, *p6c;
    if (a[0x20D] == 2) {
        p5c = (f32 *)(a + 0x5C);
        p68 = (f32 *)(a + 0x68);
        p60 = (f32 *)(a + 0x60);
        p6c = (f32 *)(a + 0x6C);
        *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
        *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
        *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
        if (*(f32 *)(a + 0x38) <= *(f32 *)(a + 0x430)) {
            *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
            *(s32 *)p5c = 0;
            *(s32 *)p60 = 0;
            *(s32 *)p68 = 0;
            *(s32 *)p6c = 0;
            func_00183d50(a);
            a[0x20D] = 0;
        }
    }
    if (*(s8 *)(a + 0x151) != 0) {
        a[0x151] = 0;
        func_003569A0(a, *(s16 *)(a + 0x1E) + a[0x1B7]);
    }
    if (func_00175700(a) < 0) {
        if (a[0x20D] == 2) {
            *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
            func_00184540(a);
            return;
        }
        func_001843A0(a);
    }
}

void func_0017A450(u8 *a) {
    extern s32 func_00184720();
    extern s32 func_00185A90();
    extern s32 func_00184E70();
    extern void func_00184CA0();
    extern void func_00175700();
    extern void func_001820A0();
    extern s32 func_001864a0();
    extern void func_00185490();
    extern void func_001865B0();
    u32 *s0, *s1;
    if (func_00184720(a) != 0) return;
    if (func_00185A90(a) != 0) return;
    s1 = (u32 *)(a + 0x428);
    s0 = (u32 *)(a + 0x42C);
    if ((*s1 & 0x184010A0) | (*s0 & 0x02000801)) {
        if (func_00184E70(a) != 0) return;
    }
    if ((*s1 & 0xA8400960) | (*s0 & 0x10)) func_00184CA0(a);
    if (a[1] == 0x2A) (*(void (**)())(*(u8 **)(a + 0x43C) + 0x60))(a);
    func_00175700(a);
    func_001820A0(a);
    if (func_001864a0(a) == 0) return;
    if (func_00185A90(a) != 0) return;
    if (*(s8 *)(a + 0x539) != 0) func_00185490(a);
    func_001865B0(a);
}
