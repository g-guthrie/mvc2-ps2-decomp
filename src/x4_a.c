typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840[2];

void func_001D55F0(u8 *p) {
    extern int func_00175700(u8 *);
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        p[4] = 2;
        p[0x13C] = 0;
    } else if (*(s32 *)(D_004C2840[0] + 0x1C) & 1) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = p[0x15B] ? 0 : 1;
    }
}


typedef struct { f32 x, y, z; } V3;
void func_00381F30(u8 *p, V3 *vec, u8 a, u8 b) {
    extern u8 *func_003DA750();
    extern void func_00381FD0();
    u8 *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = func_00381FD0;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = a;
        o[0x21] = b;
        *(V3 *)(o + 0x34) = *vec;
        *(s16 *)(o + 0x26) = 0x1A00;
        *(u16 *)(o + 0x1E) = *(u16 *)(p + 0x168);
    }
}

extern u8 D_0045B750[];
s32 func_002EDEE0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (p[0x1E4] != 0x15) return 0;
    if (p[0x1FD] != 3) return 0;
    if (*(s32 *)(p + 0x308) <= 0) return 0;
    if (func_00189310(p, D_0045B750, p + 0x390) == 0) return 0;
    func_0018A990(p, p + 0x390);
    p[0x1FD] = 6;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G2794;
extern G2794 *D_004C2794;

void func_00285830(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    extern void func_00175C00();
    extern void func_001843A0();
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        p[0x1B5] = 0x56;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 0x14, 7);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}

void func_002219D0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    s8 s1 = p[0x151];
    s8 r = func_00175700(p);
    if (r >= 0 && s1 < 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        *(s32 *)(p + 0x68) = 0;
        func_001757E0(p, 1, 9);
        return;
    }
    if (*(s8 *)(p + 0x151) > 0) {
        p[0x151] = 0;
        p[0x1B5] = 0x50;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
}

void func_00312400(u8 *p) {
    extern int func_00175700(u8 *);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        { u32 t = p[7]; p[7] = t + 1; }
        *(s16 *)(p + 0x1C) = 0x20;
        p[0x20D] = 2;
        p[0x1EC] = 0;
        p[0x210] = 0;
        p[0x1E8] = 0;
        p[0x1E9] = 0;
        p[0x1EA] = 0x11;
        p[0x1ED] = 0;
        *(u32 *)(p + 0x5C) = 0xC1200000;
        *(u32 *)(p + 0x68) = 0x3E555555;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBE892492;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

void func_002E2740(u8 *p) {
    extern void func_001863F0();
    extern void func_001864a0();
    extern int func_00175700(u8 *);
    extern void func_002E1520();
    if (p[0x20D] == 2) {
        func_001863F0();
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001864a0(p);
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x2C0) != 0 || (--*(s16 *)(p + 0x1E)) < 0) {
        func_002E1520(p, p[0x20D]);
    }
}

extern s32 *D_004C1758[2];
extern s32 *D_004BFEE8[2];

void func_00218910(u8 *p, s32 idx) {
    s32 *e = D_004BFEE8[idx];
    e += p[0x1B7] * 4;
    *(f32 *)(p + 0x5C) = 1.6666666f * (f32)e[0] / 65536.0f;
    *(f32 *)(p + 0x68) = 1.6666666f * (f32)e[1] / 65536.0f;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)e[2] / 65536.0f;
    *(f32 *)(p + 0x6C) = 2.142857074737549f * (f32)e[3] / 65536.0f;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
}

void func_0031DE00(u8 *p, s32 idx) {
    s32 *e = D_004C1758[idx];
    e += p[0x1B7] * 4;
    *(f32 *)(p + 0x5C) = 1.6666666f * (f32)e[0] / 65536.0f;
    *(f32 *)(p + 0x68) = 1.6666666f * (f32)e[1] / 65536.0f;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)e[2] / 65536.0f;
    *(f32 *)(p + 0x6C) = 2.142857074737549f * (f32)e[3] / 65536.0f;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
}

void func_00386D30(u8 *p, u8 *q) {
    extern void func_00386570(u8 *, u8 *);
    extern s32 func_00174240();
    extern int func_00175700(u8 *);
    extern void func_001E7F60();
    u8 *r = q + 0x2B8;
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_00386570(p, q);
        return;
    }
    if (func_00174240() == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        r[5] = 0;
        *(s16 *)(p + 0x1C) = 7;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_001E7F60(p);
}

void func_002B3FE0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    f32 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) v = 2.5f; else v = -2.5f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = -0.20833333f; else v = 0.20833333f;
        *(f32 *)(p + 0x68) = v;
        func_001757E0(p, 2, 2);
    }
}

void func_003B4F10(u8 *p, u8 *q) {
    extern void func_003B5560();
    extern void func_003B54E0();
    extern void func_003B5530();
    f32 *b;
    u8 *w;
    f32 a = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x90);
    f32 d;
    f32 z = 0.0f;
    b = (f32 *)(p + 0x88);
    w = q + 0x2B8;
    d = *(f32 *)(p + 0x34) - a;
    if (*(s16 *)(p + 0x140) == 0) d = -d;
    if (d <= z) {
        u32 t;
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + b[3];
        b[4] = z;
        p[0x1B0] = 0;
        *(s16 *)(p + 0x1C) = 3;
        w[4] = 1;
        t = p[5];
        p[5] = t + 1;
        func_003B5560(p, q);
    } else {
        func_003B54E0(p, q);
        func_003B5530(p, q);
    }
}



void func_00217390(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001843A0();
    f32 v;
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        v = 1.6666666f * (f32)*(s8 *)(p + 0x150);
        if (p[0x1E6] == 0) v = -v;
        *(f32 *)(p + 0x34) += v;
        break;
    }
}

void func_002808F0(u8 *p) {
    switch (p[0x452]) {
    case 0: {
        u32 t = p[0x452];
        p[0x452] = t + 1;
        *(s32 *)(p + 0x460) = 0x1E0;
        break;
    }
    case 1: {
        s32 v;
        if (p[0x1E4] == 1 && p[6] == 3) {
            if (--p[0x472] == 0) {
                p[0x452] = 2;
                break;
            }
        }
        v = *(s32 *)(p + 0x460) - 1;
        *(s32 *)(p + 0x460) = v;
        if (v < 0) p[0x452] = 2;
        if (*(s8 *)(p + 0x1E7) == 0 && *(s16 *)(p + 0x140) == 0) {
            *(s16 *)(p + 0x4F0) = 0x800;
        } else {
            *(s16 *)(p + 0x4F0) = 0x400;
        }
        break;
    }
    case 2:
        if (p[0x1E4] != 1) p[0x451] = 1;
        break;
    }
}

void func_002430A0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_0018FDB0();
    extern void func_00185490();
    extern void func_00126400();
    extern void func_001843A0();
    extern void func_001A5590();
    u8 *q;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x20;
        func_0018FDB0(p);
        if (*(s16 *)(q + 0x434) == 0) {
            func_00185490(p);
            q[0x20A] = 1;
            q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
            *(s16 *)(q + 0x140) = *(s16 *)(p + 0x140) ^ 1;
            q[0x20D] = 2;
            func_00126400();
            p[0x1FE] = 0;
            func_001843A0(p);
            return;
        }
        func_001A5590(p, q, 0);
        func_001A5590(p, q, 1);
        func_00126400();
    }
}

void func_00347C70(u8 *p) {
    extern void func_001757E0();
    extern int func_00175700(u8 *);
    extern void func_00347D50();
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x34) += 53.333332f;
    } else {
        *(f32 *)(p + 0x34) -= 53.333332f;
    }
    func_001757E0(p, 0x17, 3);
    do {
        if (*(s8 *)(*(u8 **)(p + 0x18) + 0x161) == *(s8 *)(p + 0x161)) {
            p[0x13C] = 1;
            return;
        }
    } while ((s8)func_00175700(p) >= 0);
    func_00347D50(p);
}

extern u8 D_004C1508[4];
extern u8 D_004C150C[4];
extern u8 D_004C1510[4];
void func_003055B0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    u32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = D_004C1508;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C150C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C1510;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}


extern u8 D_004C26CC;
void func_00191840(u8 *p, u32 a, u32 b) {
    extern u8 func_00191920();
    u8 *q;
    q = (u8 *)&b;
    D_004C26CC = 0;
    p[0] = func_00191920(p[0], q[0]);
    p[1] = func_00191920(p[1], q[1]);
    p[2] = func_00191920(p[2], q[2]);
    p[3] = func_00191920(p[3], q[3]);
    q = (u8 *)&a;
    p[4] = func_00191920(p[4], q[0]);
    p[5] = func_00191920(p[5], q[1]);
    p[6] = func_00191920(p[6], q[2]);
    p[7] = func_00191920(p[7], q[3]);
    if (*(u32 *)(p + 4) > 0x999) {
        *(u32 *)(p + 4) = 0x999;
        *(u32 *)p = 0x99999999;
    }
}

void func_00157890(u8 *p) {
    extern void func_003DAA40();
    switch (p[4]) {
    case 0: {
        s16 v;
        *(f32 *)(p + 0x50) += 0.061999999f;
        *(f32 *)(p + 0x54) += 0.061999999f;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 8) {
            u32 t = p[4];
            p[4] = t + 1;
        }
        break;
    }
    case 1: {
        s16 v;
        *(f32 *)(p + 0x50) -= 0.0419999994f;
        *(f32 *)(p + 0x54) -= 0.0419999994f;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0x14) func_003DAA40();
        break;
    }
    }
}

