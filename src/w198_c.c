typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G1;
extern G1 *D_004C2794;

void func_001AA8E0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    f32 c = 0.03125f;
    *(f32 *)(p + 0x50) += c;
    *(f32 *)(p + 0x54) += c;
    if (func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = 0;
        *(u32 *)(p + 0x50) = 0x40000000;
        *(u32 *)(p + 0x54) = 0x40000000;
        if (*(s16 *)(p + 0x140) == 0) *(u32 *)(p + 0x5C) = 0xC0D55555;
        else *(u32 *)(p + 0x5C) = 0x40D55555;
        *(u32 *)(p + 0x68) = 0;
        func_001757E0(p, 0x17, 0x44);
        p[0x1B5] = 0x3A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    func_001E7F60(p);
}

extern u8 D_004C1020[8];
extern u32 *const D_0045A840[];
extern u8 D_0045A990[], D_0045A9A0[], D_0045A9B0[];

void func_002D99F0(u8 *p) {
    extern void func_001861B0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 a;
    func_001861B0(p);
    a = p[0x1FC];
    if (p[0x20D] == 1) a = (u8)(a + 6);
    if (p[0x212] != 0) a = (u8)(a + 3);
    a = (u8)a;
    *(u32 **)(p + 0x408) = D_0045A840[a % 6];
    p[0x1BB] = D_004C1020[p[0x1FC]];
    p[0x1B5] = D_0045A990[a];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, D_0045A9B0[a], D_0045A9A0[a]);
    if (p[0x212] == 0) {
        *(u32 *)(p + 0x300) = 0x20;
        *(u32 *)(p + 0x304) = *(u16 *)(p + 0x168);
    }
}

extern u16 D_004C11C0[4];

void func_002F1BB0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_002F1DF0(u8 *);
    extern void func_00126400(u8 *);
    u8 *q;
    if (p[6] == 0) {
        f32 c;
        p[6] = p[6] + 1;
        c = 6.666666507720947f;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) c = -c;
        *(f32 *)(p + 0x5C) = c;
        *(u32 *)(p + 0x68) = 0;
    }
    if (*(s8 *)(p + 0x150) > 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (func_00175700(p) < 0) {
        func_002F1DF0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u16 *)(p + 0x1C0) = D_004C11C0[*(s32 *)(p + 0x2D4)];
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1E6] = p[0x1E6];
        q[0x1B5] = 0x20;
        func_00126400(q);
    }
}

void func_00396940(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern int func_00174470(const void *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    extern void func_00396C50(u8 *, void *);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (p[5] == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (func_00174470(p) != 0) {
            if (*(s8 *)(p + 0x1B2) != 0) {
                u32 t = p[5];
                p[5] = t + 1;
                func_001757E0(p, 0x17, 0xC);
            }
            func_001E7F60(p);
            return;
        }
        func_00396C50(p, q);
    } else {
        if (func_00175700(p) < 0) func_00396C50(p, q);
    }
}

void func_0036FD90(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0036FEE0(u8 *);
    extern s8 func_00175700(u8 *);
    f32 c, d, e;
    if (*(s8 *)(p + 0x151) == 2) func_001E3710(p, 0x18);
    if (*(s8 *)(p + 0x151) == 0) {
        if ((*(u8 **)(p + 0x18))[6] == 5) {
            if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) c = 26.66666603088379f;
            else c = -26.66666603088379f;
            *(f32 *)(p + 0x34) += c;
        }
        if ((*(u8 **)(p + 0x18))[6] == 6) {
            u32 t = p[5];
            p[5] = t + 1;
            func_001E3210(p, 0x26);
            *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
            *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
            if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) d = 400.0f;
            else d = -400.0f;
            e = 171.4285583496094f;
            *(f32 *)(p + 0x34) += d;
            *(f32 *)(p + 0x38) += e;
            func_001757E0(p, 0x17, 0x19);
            func_0036FEE0(p);
        }
    }
    func_00175700(p);
}

void func_003AF160(u8 *p, u8 *q) {
    extern void func_003AF770(u8 *, u8 *, u8 *);
    extern void func_003AF280(u8 *, u8 *);
    extern void func_003DAA40(u8 *);
    u8 *s2, *x, *y, *z;
    s32 t;
    u32 n;
    s2 = *(u8 **)(p + 0x18);
    func_003AF770(p, q, s2);
    p[0x13C] = 1;
    x = *(u8 **)(p + 0xC);
    *(f32 *)(x + 0x34) = *(f32 *)(p + 0x34) + *(f32 *)(q + 0xC);
    *(f32 *)(x + 0x38) = *(f32 *)(p + 0x38) + *(f32 *)(q + 0x10);
    x[0x13C] = 1;
    *(s16 *)(x + 0x1C) = 1;
    y = *(u8 **)(x + 0xC);
    *(f32 *)(y + 0x34) = *(f32 *)(p + 0x34) + *(f32 *)(q + 0x14);
    *(f32 *)(y + 0x38) = *(f32 *)(p + 0x38) + *(f32 *)(q + 0x18);
    y[0x13C] = 1;
    *(s16 *)(y + 0x1C) = 1;
    t = *(s8 *)(q + 0x28);
    q[0x29] = t;
    if (t > 2) {
        z = *(u8 **)(y + 0xC);
        func_003AF280(z, z + 0x88);
        return;
    }
    *(f32 *)(s2 + 0x34) = *(f32 *)(y + 0x34) - *(f32 *)(q + 0x1C);
    *(f32 *)(s2 + 0x38) = *(f32 *)(y + 0x38) - *(f32 *)(q + 0x20);
    *(s16 *)(s2 + 0x2BA) = 1;
    n = p[4];
    p[4] = n + 1;
    t = *(s8 *)(q + 0x28);
    q[0x28] = t - 2;
    z = *(u8 **)(y + 0xC);
    func_003DAA40(z);
    func_003DAA40(*(u8 **)(z + 0xC));
}

void func_001C7050(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 h;
    f32 e, c;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (q[0x1E4] != 0x16) {
        p[7] = 3;
    } else {
        h = *(s16 *)(p + 0x140);
        if (h == 0) { c = 90.0f; e = c + *(f32 *)(q + 0x34); }
        else { c = 90.0f; e = *(f32 *)(q + 0x34) - c; }
        if ((h == 0 && *(f32 *)(p + 0x34) <= e) || (h != 0 && !(*(f32 *)(p + 0x34) < e))) {
            u32 t = p[7];
            p[7] = t + 1;
            *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
            *(s16 *)(p + 0x140) ^= 1;
            *(s16 *)(q + 0x1C) = 0;
            func_001757E0(p, 0x19, 0x1B);
        }
    }
}

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_0035E980(u8 *p, void *owner_context) {
    u8 *q = owner_context;
    extern s8 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *s, *r;
    u32 v;
    r = *(u8 **)(p + 0x14);
    s = q + 0x2B8;
    if (q[5] != 0 || q[0x1E4] != 0x15 || q[0x1FD] != 1) {
        p[4] = 2;
        p[0x13C] = 0;
        s[0] = 1;
        return;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -8;
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) != 0) return;
    if (*(s8 *)(p + 0x1B3) == 0) {
        if (func_00175700(p) >= 0) {
            *(V3 *)(p + 0x34) = *(V3 *)(r + 0x34);
            v = p[0x15B];
            if (v != 0) {
                p[0x1B5] = v;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
                p[0x15B] = 0;
            }
            func_001E7F60(p);
            return;
        }
    }
    p[4] = 2;
    p[0x13C] = 0;
    s[0] = 1;
}

void func_0036FB20(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0036FC70(u8 *);
    extern s8 func_00175700(u8 *);
    f32 c, d, e;
    if (*(s8 *)(p + 0x151) == 2) func_001E3710(p, 0x18);
    if (*(s8 *)(p + 0x151) == 0) {
        if ((*(u8 **)(p + 0x18))[6] == 5) {
            if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) c = 26.66666603088379f;
            else c = -26.66666603088379f;
            *(f32 *)(p + 0x34) += c;
        }
        if ((*(u8 **)(p + 0x18))[6] == 6) {
            u32 t = p[5];
            p[5] = t + 1;
            func_001E3210(p, 0x26);
            *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
            *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
            if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) d = 400.0f;
            else d = -400.0f;
            e = 171.4285583496094f;
            *(f32 *)(p + 0x34) += d;
            *(f32 *)(p + 0x38) += e;
            func_001757E0(p, 0x17, 0x18);
            func_0036FC70(p);
        }
    }
    func_00175700(p);
}
