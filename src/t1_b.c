typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;

extern f32 func_00417440(s16 a);

extern void func_001BB8D0(u8 *p, u8 *q);
extern s32 func_00175670(u8 *p);
extern void func_0037D1B0(u8 *q);

void func_001BB020(u8 *p, u8 *q) {
    if (*(s8 *)(p + 0x151) == 3) {
        *(f32 *)(p + 0x118) += 0.016f;
    }
    if (p[1] != q[1]) {
        func_001BB8D0(p, q);
    } else {
        if ((s8)func_00175670(p) < 0) {
            func_0037D1B0(q);
            p[4] = 2;
        }
        return;
    }
}

extern void func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);

void func_00351270(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[5];
            p[5] = t + 1;
            func_001757E0(p, 0x15, (u8)(p[0x20] + 0x21));
        }
    }
}

extern void func_001865B0(u8 *p);

void func_0031E660(u8 *p) {
    s32 *a, *b, *c, *d;
    a = (s32 *)(p + 0x5C);
    c = (s32 *)(p + 0x68);
    b = (s32 *)(p + 0x60);
    d = (s32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001865B0(p);
    } else {
        func_00175700(p);
    }
}

extern void func_00134710(u8 *p, u8 *q);
extern s32 func_00134230(u8 *p, u8 *q);
extern s32 func_001342D0(u8 *p, u8 *q);
extern s32 func_001341B0(u8 *p, u8 *q);
extern s32 func_00134370(u8 *p, u8 *q);

void func_00311FA0(u8 *p) {
    f32 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = 205.7142792f + *(f32 *)(p + 0x430);
    if (!(v < *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = v;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        *(s16 *)(p + 0x1C) = 0x40;
    }
}

extern s8 D_00473B80[];
extern s8 D_00473B81[];

extern void func_001B3D90(u8 *a, u8 *b);
extern s32 func_00175670(u8 *a);
extern u8 *func_001B3E30(u8 *, int, int);

void func_001B3760(u8 *p) {
    u8 *s = *(u8 **)(p + 0x18);
    if (p[0xD0] != s[0x168] || *(s8 *)(s + 0x151) == 0) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[0x13C] = 0;
        return;
    }
    func_001B3D90(s, p);
    *(s8 *)(p + 0x24) = *(s8 *)(s + 0x24);
    *(s8 *)(p + 0x31) = -1;
    if (*(s8 *)(s + 0x1B4) == 0) func_00175670(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_001B3E30(s, (u8)(p[0x21] + 6), 1);
    }
}

extern s32 func_00189310(u8 *p, void *t, u8 *q);
extern void func_0018A990(u8 *p, u8 *q);
extern void func_00186A60(u8 *p, s32 a);
extern u8 D_0044FB68[];

extern s32 func_0019B710(u8 *p, s32 a);
extern void func_0019B740(u8 *p);

void func_0019B580(u8 *p) {
    s32 r;
    if (p[5] == 0) {
        r = func_0019B710(p, 0x17);
        r |= func_0019B710(p, 0x13);
        r |= func_0019B710(p, 0x14);
        if (r == 0) {
            func_0019B740(p);
            return;
        }
    }
    if ((s8)func_00175670(p) < 0) {
        func_0019B740(p);
    } else {
        *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    }
}

extern void func_00186A20(u8 *p);
extern f32 D_00459490[];
extern f32 D_00459494[];

void func_002BAAA0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_00186A20(p);
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? D_00459490[p[0x1B7] * 2] : -D_00459490[p[0x1B7] * 2];
        *(s32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x60) = D_00459494[p[0x1B7] * 2];
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}

extern void func_00175580(u8 *p, s32 a, s32 b);

extern void func_00185490(u8 *p);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_002BF040(u8 *p) {
    s32 *a, *b, *c, *d;

    if (*(s8 *)(p + 0x151) == 0)
        func_00175700(p);
    a = (s32 *)(p + 0x5C);
    c = (s32 *)(p + 0x68);
    b = (s32 *)(p + 0x60);
    d = (s32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        if (*(s8 *)(p + 0x151) != 0) {
            u32 t = p[6];
            p[6] = t + 1;
            p[0x151] = 0;
            *a = 0;
            *b = 0;
            *c = 0;
            *d = 0;
        }
    }
}

void func_002BF110(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *o;
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x20A] = 3;
        o[0x1B5] = 0x21;
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? 3.33333325f : -3.33333325f;
        *(s32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_00185490(p);
        D_004F1F45 = 2;
        D_004F1F46 = 1;
    }
}

void func_00239090(u8 *p) {
    s32 *a, *b, *c, *d;
    func_00175700(p);
    a = (s32 *)(p + 0x5C);
    c = (s32 *)(p + 0x68);
    b = (s32 *)(p + 0x60);
    d = (s32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001757E0(p, 0x15, 0x1D);
    }
}
