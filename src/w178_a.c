typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a; s16 b; } T4;
extern T4 D_00464C90[];
void func_0038A5A0(u8 *d, u8 *s) {
    if (*(s16 *)(s + 0x140) == 0) {
        *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) + 1.6666666269302368f * (f32)D_00464C90[*(s8 *)(s + 0x150)].a;
    } else {
        *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) - 1.6666666269302368f * (f32)D_00464C90[*(s8 *)(s + 0x150)].a;
    }
    *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38) + 2.142857074737549f * (f32)D_00464C90[*(s8 *)(s + 0x150)].b;
}

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
void func_0035A560(u8 *p, s32 q) {
    extern void func_00175700();
    extern void func_0035A7B0();
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (D_004F1FC8 >= *(f32 *)(p + 0x34)) {
        *(f32 *)(p + 0x34) = D_004F1FC8;
        p[5]++;
        *(s16 *)(p + 0x1C) = 0x258;
    } else if (D_004F1FCC <= *(f32 *)(p + 0x34)) {
        *(f32 *)(p + 0x34) = D_004F1FCC;
        p[5]++;
        *(s16 *)(p + 0x1C) = 0x258;
    } else {
        func_0035A7B0(p, q);
    }
}

void func_00217EA0(u8 *p) {
    extern void func_00175700();
    extern s32 func_001864A0();
    extern void func_001757E0();
    extern void func_00183D50();
    s16 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        if (func_001864A0(p) != 0) {
            p[6]++;
            p[7] = 0;
            *(f32 *)(p + 0x34) -= *(f32 *)(p + 0x5C);
            p[0x20D] = 0;
            func_001757E0(p, 0x12, 2);
            func_00183D50(p);
        }
    } else {
        p[7]++;
        func_001757E0(p, 0x12, 1);
    }
}

extern f32 D_00444350[];
static void func_00150520(u8 *o, f32 a, f32 b, f32 c) {
    *(f32 *)(o + 0x40) = a;
    *(f32 *)(o + 0x44) = b;
    *(f32 *)(o + 0x48) = c;
}

void func_001508D0(u8 *a, s16 b, s32 c, f32 x, f32 y, f32 z) {
    extern u8 *func_003DA750();
    extern void func_001509D0();
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_001509D0;
        *(s32 *)(o + 0xD0) = 0x431;
        *(f32 *)(o + 0x34) = x + D_00444350[c];
        *(f32 *)(o + 0x38) = y;
        *(f32 *)(o + 0x3C) = z;
        *(s16 *)(o + 0x1E) = b;
        o[0x23] = c;
        func_00150520(o, 0.4991999864578247f, 1.0f, 1.0f);
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(u8 **)(o + 0x18) = a;
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_001F4950(u8 *p) {
    extern void func_00175700();
    extern s32 func_001864A0();
    extern void func_001E3210();
    extern void func_001F72E0();
    extern void func_0015B660();
    extern void func_001E3710();
    extern void func_0018FDB0();
    extern void func_001757E0();
    u8 *q;
    f32 v[4];
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_001864A0(p) != 0) {
        p[7]++;
        D_004F1F45 = 2;
        D_004F1F46 = 1;
        func_001E3210(p, 0x14);
        func_001F72E0(p);
        q = *(u8 **)(p + 0x1DC);
        q[0x1B5] = 0x50;
        p[0x1B5] = 0x50;
        v[0] = *(f32 *)(q + 0x34);
        v[1] = *(f32 *)(p + 0x430);
        func_0015B660(v, 1);
        func_001E3710(p, 0x49);
        func_0018FDB0(p);
        func_001757E0(p, 0xF, 0x20);
    }
}

extern f32 D_00464A50[];
extern f32 D_00464A60[];
void func_00388680(u8 *d, u8 *s) {
    d[0x24] = *(s8 *)(s + 0x24);
    if (s[1] == 0x1C) {
        if (*(s16 *)(s + 0x140) == 0) {
            *(f32 *)(d + 0x34) = -11.666666030883789f + *(f32 *)(s + 0x34);
        } else {
            *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) - -11.666666030883789f;
        }
        *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38) + D_00464A50[s[0x20D]];
    } else {
        if (*(s16 *)(s + 0x140) == 0) {
            *(f32 *)(d + 0x34) = -6.666666507720947f + *(f32 *)(s + 0x34);
        } else {
            *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) - -6.666666507720947f;
        }
        *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38) + D_00464A60[s[0x20D]];
    }
}

void func_00186800(u8 *p) {
    f32 v;
    if ((*(s8 *)(p + 0x211) & (1 << *(s16 *)(p + 0x140))) == 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 26.66666603088379f;
        } else {
            *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) - 26.66666603088379f;
        }
    }
    v = 640.0f;
    if (*(s16 *)(p + 0x140) != 0) v = -v;
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x5C) = -(v / 21.0f);
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x38) = 137.14285278320312f + *(f32 *)(p + 0x430);
    *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    *(f32 *)(p + 0x60) = (*(f32 *)(p + 0x430) - *(f32 *)(p + 0x38)) / 20.0f - (20.0f * *(f32 *)(p + 0x6C)) / 2.0f;
}
void func_0038F300(u8 *p) {
    extern s32 func_00175700();
    extern void func_0038F2D0();
    extern void func_001E7F60();
    extern void func_0038F410();
    u8 *q = *(u8 **)(p + 0x18);
    if (p[5] == 0) {
        if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
            func_0038F2D0(p);
            return;
        }
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            func_0038F2D0(p);
        }
        func_001E7F60(p);
    } else {
        if ((s8)func_00175700(p) < 0) {
            p[4]++;
            func_0038F410(p);
        }
    }
}

void func_001FA260(u8 *p) {
    extern void func_00175700();
    extern void func_00183D50();
    extern void func_001757E0();
    u32 *d, *c, *b, *a;
    p[0x40C] = 2;
    p[0x33C] = 5;
    a = (u32 *)(p + 0x6C);
    b = (u32 *)(p + 0x68);
    c = (u32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = (u32 *)(p + 0x5C);
    if (*(s8 *)(p + 0x161) >= 0) func_00175700();
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        *d = 0;
        *c = 0;
        *b = 0;
        *a = 0;
        func_00183D50(p);
        func_001757E0(p, 0x16, 5);
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_0025BD90(u8 *p) {
    extern void func_001266A0();
    extern void func_00154940();
    extern void func_001E3A40();
    extern s32 func_00175700();
    extern void func_001843A0();
    f32 v[4];
    u8 *q;
    if (*(s8 *)(p + 0x151) != 2) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (*(s8 *)(p + 0x151) == 1) {
        func_001266A0(p, 0, 0);
        *(u32 *)&v[0] = 0;
        *(u32 *)&v[1] = 0;
        func_00154940(p, v, 2);
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1E6] = p[0x1E6];
        q[0x1B5] = 0x22;
        q[0x20A] = 3;
        D_004F1F45 = 2;
        D_004F1F46 = 1;
        func_001E3A40(q);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        p[0x20D] = 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}

void func_00225AD0(u8 *p) {
    extern void func_0019CAF0();
    extern void func_001266A0();
    extern void func_00154790();
    extern void func_001E3710();
    extern s32 func_00175700();
    extern void func_001843A0();
    f32 v[4];
    u8 *q;
    s8 t;
    if (p[6] == 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[6] = p[6] + 1;
            func_0019CAF0(p);
        }
    }
    t = *(s8 *)(p + 0x151);
    if (t < 0) {
        p[0x151] = t & 0xF;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x21;
        q[0x1E6] = p[0x1E6];
        v[1] = 105.0f + *(f32 *)(p + 0x38);
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)&v[0] = 0x41FD5555;
        } else {
            *(u32 *)&v[0] = 0xC1FD5555;
        }
        v[0] += *(f32 *)(p + 0x34);
        v[2] = *(f32 *)(p + 0x3C);
        func_00154790(v, *(s16 *)(p + 0x140), 2, 0);
        func_001E3710(p, 1);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_0024F2E0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    u32 *d, *c, *b, *a;
    f32 v;
    a = (u32 *)(p + 0x6C);
    b = (u32 *)(p + 0x68);
    c = (u32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = (u32 *)(p + 0x5C);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *d = 0;
        *c = 0;
        *b = 0;
        *a = 0;
        if (p[0x1E6] != 0) v = 6.666666507720947f; else v = -6.666666507720947f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = -0.20833332836627960f; else v = 0.20833332836627960f;
        *(f32 *)(p + 0x68) = v;
        p[0x169] = 2;
        p[0x168] = 2;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}

void func_00377B30(u8 *p, u8 *q) {
    extern s32 func_00174470();
    extern s32 func_00185980();
    extern void func_001757E0();
    extern void func_00185870();
    extern void func_00178F20();
    extern void func_00175700();
    extern void func_001E7F60();
    u8 *r;
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0x1E)) {
        if (q[0x169] == 0x16) {
            p[5] = 2;
        } else {
            p[4] = 2;
            p[0x13C] = 0;
        }
    } else {
        if (func_00174470(p) == 0) *(s16 *)(q + 0x1C) = 0;
        if (*(s8 *)(p + 0x1B2) != 0) {
            if (func_00185980(p) != 0) {
                p[5] = 3;
                p[6] = 0;
                func_001757E0(p, 0xF, 2);
                p[0x20] = 0xFF;
                q[0x20B] = 0xC1;
                q[0x1B1] = 0;
                q[0x201] = 3;
                q[0x1FE] = 1;
                q[6] = 3;
                q[7] = 0;
                r = *(u8 **)(p + 0x1C4);
                func_00185870(p, r);
                func_00178F20(p, r);
            } else {
                p[5] = 2;
                *(s16 *)(q + 0x1C) = 0;
            }
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            func_00175700(p);
            func_001E7F60(p);
        }
    }
}

void func_001945D0(u8 *p, u8 *q) {
    u8 *r = *(u8 **)(p + 0x14);
    s32 done;
    s32 a;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    if (*(f32 *)(p + 0x5C) > 0.0f) {
        *(f32 *)(p + 0x68) += *(f32 *)(p + 0x5C);
    } else {
        *(f32 *)(p + 0x68) -= *(f32 *)(p + 0x5C);
    }
    done = 0;
    do {
        a = 0;
        if (r[0x21] != 0) a = 0x200000;
        if (*(s16 *)(p + 0x140) == 0) a = -a;
        *(f32 *)(r + 0x34) = *(f32 *)(p + 0x34) + (1.6666666269302368f * (f32)a) / 65536.0f;
        if (*(f32 *)(p + 0x68) < 53.33333206176758f) {
            done = 1;
        } else if (53.33333206176758f == *(f32 *)(p + 0x68)) {
            p[5]++;
            done = 1;
        } else {
            *(f32 *)(p + 0x68) = 53.33333206176758f;
            a = 0x880000;
            if (*(s16 *)(p + 0x140) == 0) a = -a;
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + (1.6666666269302368f * (f32)a) / 65536.0f;
        }
    } while (done == 0);
}

void func_00378300(u8 *p, u8 *q) {
    extern void func_003785F0();
    extern void func_001E7F60();
    extern void func_00175700();
    u8 *r = (u8 *)((s32)q + 0x2B8);
    s16 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((p[0x20] & 2) && *(volatile f32 *)(p + 0x38) <= *(volatile f32 *)(q + 0x430)) {
        func_003785F0(p);
        r[4] = 0;
        return;
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[5]++;
        *(s16 *)(p + 0x1C) = 0x3C;
        p[0x1B0] = 0x44;
        p[0x1B1] = 0x44;
        *(u32 *)(p + 0x50) = 0x3FA00000;
        *(u32 *)(p + 0x54) = 0x3FA00000;
    }
    func_001E7F60(p);
    func_00175700(p);
}

