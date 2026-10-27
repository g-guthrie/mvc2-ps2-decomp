typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002BE1B0(u8 *p) {
    extern void func_00175700();
    s16 v;
    u32 t;
    f32 lim = 2.142857074737549f;
    v = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = v;
    v = v & 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) func_00175700();
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= lim) {
        t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBF3C9249;
    }
}

extern void func_0016B0C0();
extern void func_00166C80();
void func_00168350(u8 *p, u8 *q) {
    s16 lim;
    s16 v;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 2);
    lim = *(s16 *)(*(u8 **)(p + 0x220) + 0x434);
    v = *(s32 *)(p + 0x4C8) * 144 / 200;
    func_00166C80(p, q, v >= lim, lim);
}

void func_0013FF00(u8 *p) {
    extern s32 func_003D7130();
    extern void func_0013FFC0();
    s16 v;
    f32 x;
    f32 one = 1.0f;
    f32 step = 0.003125f;
    v = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = v;
    if (v >= 0x168) *(s16 *)(p + 0x1C) = 0;
    v = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = v;
    if (v >= 0xC8) *(s16 *)(p + 0x1E) = 0;
    if (func_003D7130() == 0) {
        x = *(f32 *)(p + 0x78);
        if (x < one) {
            x += step;
            *(f32 *)(p + 0x78) = x;
            *(f32 *)(p + 0x7C) = x;
            *(f32 *)(p + 0x80) = x;
        }
    }
    func_0013FFC0(p);
}

typedef struct { f32 x, y, z; } V3;
extern u8 D_004D18A5;
extern void (*D_00448E50[])(u8 *);
s32 func_00186CE0(u8 *p, u8 q) {
    extern void func_00186A60(u8 *, u8);
    extern void func_00191210(u8 *);
    u8 z;
    p[0x13C] = 1;
    func_00186A60(p, q);
    p[7] = 0;
    p[6] = 0;
    p[5] = 0;
    z = *(s32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    if (q != 0x17) {
        p[0x1EF] = 0; p[0x1EE] = z;
    }
    D_004D18A5 = 1;
    D_00448E50[q](p);
    if (p[0x1E4] != 0x17) func_00191210(p);
    return 1;
}

u8 *func_0039C5B0(u8 *p, u8 q) {
    extern u8 *func_003DA750();
    extern void func_0039E390();
    extern void func_0039C710();
    u8 *o;
    u32 v;
    if (p[0x269] == 6 && q == 9) {
        if ((o = func_003DA750(0, 2, 0)) != 0) {
            *(void **)(o + 0x10) = func_0039E390;
            *(u8 **)(o + 0x18) = p;
            o[0x20] = q;
            *(s16 *)(o + 0x26) = 0x2800;
            v = p[1];
            o[1] = v;
            *(s16 *)(o + 0x8A) = v;
            *(u16 *)(o + 0x88) = *(u16 *)(p + 0x168);
            return o;
        }
    } else if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = func_0039C710;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = q;
        *(s16 *)(o + 0x26) = 0x2800;
        v = p[1];
        o[1] = v;
        *(s16 *)(o + 0x8A) = v;
        *(u16 *)(o + 0x88) = *(u16 *)(p + 0x168);
        return o;
    }
    return 0;
}

void func_003219A0(u8 *p, u8 *q) {
    extern void func_00126400();
    extern void func_001E3710();
    extern void func_001E3210();
    extern void func_001548D0();
    extern void func_001E3A40();
    u32 v[4];
    func_00126400(p, q);
    p[0x151] = 0x10;
    *(u32 *)(p + 0x5C) = 0x41555555;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u8 **)(q + 0x1C8) = p;
    q[0x20A] = 2;
    q[0x1E6] = (s8)p[0x1E6] ^ 1;
    q[0x1B5] = 0x22;
    func_001E3710(p, 2);
    func_001E3210(p, 4);
    v[0] = 0xC2D55555;
    v[1] = 0x42092492;
    func_001548D0(p, v, 2);
    func_001E3A40(p);
}

void func_00287880(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p[6] == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                u32 t;
                p[0x151] = 0;
                t = p[6];
                p[6] = t + 1;
                if (*(s16 *)(p + 0x140) == 0) {
                    *(u32 *)(p + 0x5C) = 0xC162AAAA;
                    *(u32 *)(p + 0x68) = 0x3ED55555;
                } else {
                    *(u32 *)(p + 0x5C) = 0x4162AAAA;
                    *(u32 *)(p + 0x68) = 0xBED55555;
                }
            }
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

void func_003191C0(u8 *p) {
    extern s32 func_00175700();
    extern s32 func_00118FA8(f32);
    extern void func_00319980();
    s32 r;
    s32 n;
    f32 *a;
    f32 *b;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    r = func_00118FA8(*(f32 *)(p + 0x5C));
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    n = func_00118FA8(*(f32 *)(p + 0x5C));
    n ^= r;
    if (n < 0) {
        *a = 0;
        *b = 0;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    func_00319980(p);
}

void func_0028F050(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_00183DF0();
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p[6] == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                u32 t;
                p[0x151] = 0;
                t = p[6];
                p[6] = t + 1;
                if (*(s16 *)(p + 0x140) == 0) {
                    *(u32 *)(p + 0x5C) = 0xC12D5555;
                    *(u32 *)(p + 0x68) = 0x3ED55555;
                } else {
                    *(u32 *)(p + 0x5C) = 0x412D5555;
                    *(u32 *)(p + 0x68) = 0xBED55555;
                }
            }
        } else {
            func_00183DF0(p, 7);
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

void func_002AFAC0(u8 *p) {
    extern void func_00175700();
    extern void func_003958B0();
    extern void func_001E3210();
    extern void func_001757E0();
    f32 lim;
    s16 v;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    lim = *(f32 *)(p + 0x430);
    if (!(lim <= *(f32 *)(p + 0x38))) *(f32 *)(p + 0x38) = lim;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (*(u32 *)(p + 0xD0) == 0) func_003958B0(p, 1);
        else func_003958B0(p, 7);
        func_001E3210(p, 0x1E);
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x17));
    }
}

void func_0021AE20(u8 *p) {
    extern void func_00175700();
    extern void func_00175910();
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) *(u32 *)(p + 0x60) = 0;
    if (*(s16 *)(p + 0x1E) != 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0xC0855555;
        if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40AB6DB6;
        *(u32 *)(p + 0x6C) = 0xBF700000;
        func_00175910(p, 1, 1, 8);
    }
}

void func_003A27E0(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern s32 func_00174240();
    extern void func_001E3710();
    extern void func_003A25E0();
    s16 v;
    u32 t;
    if ((s8)func_00175700(p) < 0) {
        v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            t = p[4];
            p[4] = t + 2;
            p[0x13C] = 0;
            func_001E3710(q, 0x3A);
            return;
        }
        p[4] = 0;
        p[5] = 0;
        if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x34) += 320.0f;
        else *(f32 *)(p + 0x34) -= 320.0f;
        *(s16 *)(p + 0x1C) = 0;
        func_003A25E0(p, q);
    } else if (func_00174240(p) != 0) {
        p[0x13C] = 1;
    } else {
        p[0x13C] = 0;
        func_001E3710(q, 0x3A);
    }
}

void func_003AA3C0(s32 a, f32 *out) {
    extern f32 func_00417500();
    extern f32 func_00417440();
    s16 ang;
    u8 t = a;
    t += 4;
    t = t >> 3;
    ang = ((0x28 - t) & 0x1F) << 11;
    out[0] = 1.6666666269302368f * (409600.0f * (1000.0f * func_00417500(ang)) / 100000.0f / 256.0f);
    out[1] = 2.142857074737549f * (409600.0f * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
}
