typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_00268710(u8 *p) {
    extern void func_001266A0();
    extern void func_00175700();
    extern s32 func_00268A60();
    func_001266A0(p, 1, 7);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00268A60(p) == 0) {
        f32 lim = *(f32 *)(p + 0x430);
        lim = 51.42856979f + lim;
        lim = 51.42856979f + lim;
        if (!(lim < *(f32 *)(p + 0x38))) {
            { u32 t = p[6]; p[6] = t + 1; }
        }
    }
}

void func_0023E570(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_0035DE70();
    extern u8 D_004F1F45;
    extern u8 D_004F1F46;
    s8 r;
    u32 f;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((r = func_00175700(p)) < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001843A0(p);
        return;
    }
    f = *(s8 *)(p + 0x151);
    if (f & 1) {
        p[0x151] = f & ~1;
        func_0035DE70(p, 0, 0);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
    }
}

void func_0023E4C0(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    s32 a;
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    a = *(s8 *)(p + 0x151);
    if (a & 1) {
        p[0x151] = a & ~1;
        { u32 t = p[6]; p[6] = t + 1; }
        v[0] = 95.0f;
        v[1] = 261.4285583f;
        v[2] = 0.0f;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_0029DA50(u8 *p) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001843A0();
    f32 *v1, *a1, *a2, *a3;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    a2 = (f32 *)(p + 0x68);
    a1 = (f32 *)(p + 0x60);
    a3 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *v1 = 0;
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001843A0(p);
    }
}

void func_0022BD30(u8 *p) {
    extern void func_00175700();
    f32 a, c, b;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        { u32 t = p[6]; p[6] = t + 1; }
        *(f32 *)(p + 0x38) += 60.0f;
        a = -3.333333254f;
        if (p[0x1E6] != 0) a = -a;
        *(f32 *)(p + 0x5C) = a;
        *(f32 *)(p + 0x68) = 0;
        b = 17.14285659f;
        c = -0.2678571343f;
        if (p[0x20D] == 2) {
            b = 4.285714149f;
            c = -0.06696428359f;
        }
        *(f32 *)(p + 0x60) = b;
        *(f32 *)(p + 0x6C) = c;
    }
}

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C2838;


void func_003A8A20(u8 *p) {
    extern void func_001548D0();
    extern f32 D_00472F80[];
    extern f32 D_00472F84[];
    f32 v[4];
    s32 t;
    u32 u;
    s8 c = *(s8 *)(p + 0x1B2);
    if (c != 0 && (((c << 24) >> 24) & 0x11) == 0) {
        v[0] = 1.666666627f * *(f32 *)((u32)D_00472F80 + (p[0x23] << 3));
        v[1] = 2.142857075f * *(f32 *)((u32)D_00472F84 + (p[0x23] << 3));
        t = p[0x23];
        p[0x23] = t + 1;
        func_001548D0(p, v, t + 9);
        u = p[0x23];
        p[0x23] = u & 7;
    }
}

void func_002D3A90(u8 *p) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *v1, *a1;
    func_00175700(p);
    v1 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a1 = (f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))) {
        { u32 t = p[6]; p[6] = t + 1; }
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *v1 = 0;
        *a1 = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0xD);
    }
}

void func_00299830(u8 *p, u8 *q) {
    extern void func_00175700();
    extern s32 func_0018AB10();
    extern void func_001757E0();
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(q + 3) > 0) {
        if (func_0018AB10(p) != 0) {
            s32 t = *(s8 *)(q + 3);
            q[3] = t - 1;
            v = *(s16 *)(p + 0x1C) + 1;
            *(s16 *)(p + 0x1C) = v;
        }
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 0x16, 2);
    }
}

void func_002580D0(u8 *p) {
    extern void func_00175700();
    extern void func_00186A20();
    s32 v;
    f32 x;
    v = *(s8 *)(p + 0x151);
    if (v > 1) {
        if (p[0x1E6] != 0) {
            x = 1.666666627f * (f32)v;
        } else {
            x = -(1.666666627f * (f32)v);
        }
        *(f32 *)(p + 0x34) += x;
    }
    if (*(s8 *)(p + 0x151) == 1) {
        { u32 t = p[7]; p[7] = t + 1; }
        *(s16 *)(p + 0x1C) = 1;
        func_00186A20(p);
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x68) = 0;
    }
    func_00175700(p);
}

extern u8 D_004D18A1;
extern u8 D_004598B0[];

s32 func_001696F0(u8 *p) {
    extern void func_00169E50();
    extern s32 func_0016A250();
    extern s32 func_00169AE0();
    extern s32 func_00169BC0();
    u32 s = p[0x451];
    switch (s) {
    case 0:
        p[0x451] = s + 1;
        if (D_004D18A1 & 4) p[0x470] = 8;
        func_00169E50(p, 0, 0);
    case 1:
        if (!(D_004D18A1 & 4)) {
            if (func_0016A250(p) != 0) func_00169E50(p, 0, 0);
        }
        return func_00169AE0(p, 0);
    case 2:
        return func_00169BC0(p, 0);
    default:
        return 0;
    }
}

void func_003702C0(u8 *p, u8 *q) {
    extern void func_00370730();
    u8 *s0;
    f32 d;
    s0 = *(u8 **)(q + 0x220);
    func_00370730(p);
    { u32 t = p[5]; p[5] = t + 1; }
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    d = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) ? 400.0f : -400.0f;
    *(f32 *)(p + 0x34) += d;
    *(f32 *)(p + 0x38) += 171.4285583f;
    *(f32 *)(s0 + 0x34) = *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x38);
}


void func_0031DD30(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    extern void func_001843A0();
    if (p[7] == 0) {
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            { u32 t = p[7]; p[7] = t + 1; }
            p[0x20D] = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            func_001757E0(p, 0x15, (u8)(p[0x1B7] + 5));
            func_00183d50(p);
        }
    } else {
        if (func_00175700(p) < 0) func_001843A0(p);
    }
}

void func_002BD8E0(u8 *p) {
    extern void func_00175700();
    extern void func_001266A0();
    u8 *q;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x151] = 0;
        p[0x20D] = 2;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        q[0x1B5] = 0x26;
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? -6.666666508f : 6.666666508f;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}

void func_0022F2B0(u8 *p) {
    extern void func_0018C4B0();
    extern void func_0022F1E0();
    extern void func_0022F190();
    extern void func_00185490();
    extern void func_001757E0();
    f32 d;
    { u32 t = p[6]; p[6] = t + 1; }
    func_0018C4B0(p, 5);
    func_0022F1E0(p);
    if (p[0x20D] == 2) {
        func_00185490(p);
        d = 8.0f;
        *(f32 *)(p + 0x5C) /= d;
        *(f32 *)(p + 0x60) /= d;
        *(f32 *)(p + 0x68) /= d;
        *(f32 *)(p + 0x6C) /= d;
        p[0x168] = *(s8 *)(p + 0x1B7) + 2;
    } else {
        p[0x168] = p[0x1B7];
        func_0022F190(p);
    }
    p[0x169] = 0x15;
    func_001757E0(p, p[0x169], p[0x168]);
}

void func_002BE910(u8 *p) {
    extern void func_0018C6E0(void *);
    extern void func_0015D010();
    extern void func_001757E0();
    u32 v[3];
    func_0018C6E0(p);
    (*(u8 **)(p + 0x1DC))[0x1E6] = *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = p[0x1E6] ^ 1;
    if (p[0x22] & 2) {
        p[0x1E6] = *(s16 *)(p + 0x140) = p[0x1E6] ^ 1;
        (*(u8 **)(p + 0x1DC))[0x1E6] = *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = p[0x1E6] ^ 1;
    }
    *(u32 *)(p + 0x60) = 0;
    v[0] = 0x413AAAAA;
    v[2] = 0;
    v[1] = 0x43654924;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 2);
}

void func_002F72C0(u8 *p, u8 *q) {
    extern void func_00175C00();
    extern void func_00176160();
    extern u8 D_0045BE10[];
    s32 h;
    u32 t;
    h = *(s16 *)(q + 0xE);
    if (h != 0) {
        if (*(s8 *)(p + 0x1B4) == 0) *(s16 *)(q + 0xE) = h - 1;
        t = q[0x14];
        q[0x14] = t - 1;
        if (t == 0) {
            q[0x14] = 4;
            t = q[0x15];
            q[0x15] = t + 1;
            if (D_0045BE10[q[0x15]] == 0xFF) q[0x15] = 2;
            func_00176160(p, 0, D_0045BE10[q[0x15]] + 0x22 + p[0x25] * 28, 1);
        }
    } else {
        func_00175C00(p, 0);
        q[0xD] = 0;
    }
}

