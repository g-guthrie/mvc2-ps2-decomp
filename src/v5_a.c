typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00224420(u8 *p) {
    extern void func_00175700();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 6) {
        p[6]++;
        *(s8 *)(p + 0x151) = 0;
    }
}

void func_0027CD00(u8 *p) {
    extern void func_00186A60(u8 *, s32);
    f32 z = 0.0f;
    f32 v = *(f32 *)(p + 0x118) - 0.025000000372529f;
    *(f32 *)(p + 0x118) = v;
    if (v <= z) {
        func_00186A60(p, 0x17);
        p[7] = 0;
        p[6] = 0;
        p[0x20D] = 3;
        p[0x13C] = 0;
    }
}

void func_002C6FB0(u8 *p) {
    extern void func_00175700();
    f32 f;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x1C;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) f = 15.833333f; else f = -15.833333f;
        *(f32 *)(p + 0x5C) = f;
        if (p[0x1E6] != 0) f = -0.3125f; else f = 0.3125f;
        *(f32 *)(p + 0x68) = f;
    }
}

s32 func_002D9230(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    extern u8 D_0045A8A0[];
    if (func_00189310(p, D_0045A8A0, p + 0x3A0) == 0) return 0;
    func_0018A990(p, p + 0x3A0);
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    p[0x1FD] = 6;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

void func_003A82E0(u8 *p, u8 *q) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_003A8380();
    u8 *o;
    f32 t;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = (void *)func_003A8380;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = (u32)q;
        *(s16 *)(o + 0x26) = 0x2F00;
        t = 26.666666f;
        if (*(s16 *)(p + 0x140) != 0) t = -t;
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + t;
        *(f32 *)(o + 0x38) = 137.14285f + *(f32 *)(p + 0x38);
    }
}

void func_0036A9B0(u8 *p, u8 *q) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0036AB90();
    u8 *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = (void *)func_0036AB90;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = (u32)q;
        o[0x23] = (*(u8 **)(o + 0x18))[0x23];
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        *(f32 *)(o + 0x34) = *(f32 *)(*(u8 **)(o + 0x18) + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(*(u8 **)(o + 0x18) + 0x38);
        *(f32 *)(o + 0x3C) = *(f32 *)(*(u8 **)(o + 0x18) + 0x3C);
        *(f32 *)(o + 0x34) += (f32)(*(s16 *)(o + 0x140) != 0 ? 0xB0 : -0xB0);
    }
}

void func_001C7340(u8 *p, u8 *q) {
    extern void func_001C84D0();
    extern void func_001C8570();
    extern void func_00175700();
    extern u8 D_0044CC70[];
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        p[7]++;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(s16 *)(q + 0x1C) = 0;
        func_001C84D0(p, q, D_0044CC70);
        func_001C8570(p, q);
        func_00175700(p);
    }
}

typedef struct { f32 a, b; } FP;
void func_002BADA0(u8 *p) {
    extern FP D_004594D0[];
    extern void func_00175700();
    extern void func_00186A20(u8 *);
    f32 f;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        func_00186A20(p);
        if (p[0x1E6] != 0) f = D_004594D0[p[0x1B7]].a;
        else f = -D_004594D0[p[0x1B7]].a;
        *(f32 *)(p + 0x5C) = f;
        *(u32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x60) = D_004594D0[p[0x1B7]].b;
        *(f32 *)(p + 0x6C) = -0.8035714f;
    }
}

void func_002C7060(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    u32 *a, *b;
    f32 f;
    s16 v;
    s32 k;
    func_00175700(p);
    a = (u32 *)(p + 0x5C);
    b = (u32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        p[6]++;
        *a = 0;
        *(u32 *)(p + 0x60) = 0;
        *b = 0;
        *(u32 *)(p + 0x6C) = 0;
        k = 2;
        if (p[0x1E6] != 0) f = 1.6666666f; else f = -1.6666666f;
        *(f32 *)(p + 0x5C) = f;
        func_001757E0(p, k, k);
    }
}

void func_00236820(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_00238B70(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    s8 v;
    func_00175700(p, q);
    p[0x22] = *(s8 *)(p + 0x150);
    func_00238B70(p, q);
    v = q[7];
    if (v > 0) {
        p[7]++;
        p[0x1FE] = 1;
        p[0x206] = 3;
        func_001757E0(p, 0x15, p[0x1B7] + 0x15);
    } else if (v < 0) {
        p[6]++;
        p[7] = 0;
        func_001757E0(p, 0x15, p[0x1B7] + 0x19);
    }
}

void func_0027A370(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0(u8 *);
    u16 n;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    n = *(u16 *)(p + 0x160);
    if (n != 0) {
        if (*(s16 *)(p + 0x140) == 0) *(f32 *)(p + 0x34) += 1.6666666f * (f32)(s16)n;
        else *(f32 *)(p + 0x34) -= 1.6666666f * (f32)(s16)n;
        *(s16 *)(p + 0x160) = 0;
    }
}

void func_0034F0F0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0034F330(u8 *);
    extern void func_0034F3B0(u8 *);
    extern void func_001E7F60(u8 *);
    f32 f;
    if (func_00175700(p) < 0) {
        p[5]++;
        if (*(s16 *)(p + 0x140) != 0) f = 13.333333f; else f = -13.333333f;
        *(f32 *)(p + 0x5C) = f;
        *(u32 *)(p + 0x68) = 0;
        func_001757E0(p, 0x17, 0x10);
    }
    if (*(s8 *)(p + 0x1B3) != 0) func_0034F330(p);
    else if (*(s8 *)(p + 0x1B2) != 0) func_0034F3B0(p);
    else func_001E7F60(p);
}

/* Real body of func_00221440 (src/n10.c); a leaf that leaves $a0 intact. */
static void func_00221440(u8 *p) {
    s8 a = -8;
    s8 b = -4;
    u8 *q = *(u8 **)(p + 0x220);
    s8 c;
    if (q[0x1E6] == 0) {
        if (!(*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34))) {
            a = 8;
            b = 4;
        }
    } else {
        if (*(f32 *)(p + 0x34) <= *(f32 *)(q + 0x34)) {
            a = 8;
            b = 4;
        }
    }
    c = a + 0x10;
    if (*(f32 *)(q + 0x38) <= 102.8571396f + *(f32 *)(p + 0x38)) {
        c = c + b;
    }
    p[0x22] = c;
}

void func_002214E0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32);
    f32 v[3];
    func_00221440(p);
    func_00175700(p);
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        p[6]++;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x60) = 25.714285f;
        *(f32 *)(p + 0x6C) = -0.46875f;
        v[0] = -6.6666665f;
        v[1] = 210.0f;
        v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_0039DD40(u8 *p) {
    extern void func_00174910(u8 *, s32);
    extern int func_00174470(const void *);
    extern void func_0039E450(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_0015B200(u8 *, u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    s32 v;
    func_00174910(p, 0x960);
    v = *(s8 *)(p + 0x1B2);
    if (v == 0) {
        if (*(s8 *)(p + 0x1B3) == 0) {
            if (func_00174470(p) == 0) {
                func_0039E450(p);
                return;
            } else func_001E7F60(p);
        } else goto L1;
    } else if (((s8)v & 1) == 0) {
        func_0039E450(p);
    } else {
L1:
        p[4]++;
        p[0x13C] = 0;
        func_0015B200(p, p + 0x34, 1, 8);
        func_001E3710(p, 0x49);
    }
}

void func_00193090(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00193160();
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = (void *)func_00193160;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 2;
        o[0x20] = 0;
        o[0x21] = 0;
    }
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = (void *)func_00193160;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 2;
        o[0x20] = 1;
        o[0x21] = 1;
    }
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = (void *)func_00193160;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 2;
        o[0x20] = 2;
        o[0x21] = 1;
    }
}

void func_002E6D30(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    f32 f;
    q = p + 0x2B8;
    if (*(s8 *)(p + 0x151) != 0) {
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        f = 77.14285f + *(f32 *)(p + 0x430);
        if (!(*(f32 *)(p + 0x38) <= f)) return;
        *(f32 *)(p + 0x38) = f;
    }
    if (func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s8 *)(q + 7) = -1;
        func_001757E0(p, 0x15, 0x10);
    }
}

void func_00282D60(u8 *p) {
    extern void func_00175700();
    f32 f;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x10;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) f = 15.833333f; else f = -15.833333f;
        *(f32 *)(p + 0x5C) = f;
        if (p[0x1E6] != 0) f = -0.3125f; else f = 0.3125f;
        *(f32 *)(p + 0x68) = f;
    }
}
