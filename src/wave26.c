typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0014E770(void *p);
extern void func_00175670(void *p);
extern void func_001757E0(void *p, u32 b, u32 c);
extern void func_00175C00(void *p, u32 b);
extern s32 func_00175700(void *p);
extern void func_00184540(void *p);

void func_0026D260(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 9) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s8 *)(p + 0x151) = 0;
        if (p[0x20d] == 2) {
            *(u32 *)(p + 0x5c) = 0;
            *(u32 *)(p + 0x68) = 0;
            func_00184540(p);
        }
    }
}

extern s32 func_0018AA10(void *a, u32 b, void *c);
extern s32 func_0018A380(void *a, void *b, void *c, u32 d);

extern void func_0038A5A0(void *a, void *b);

void func_0038A380(u8 *a0, u8 *a1) {
    if (*(s8 *)(a1 + 0x151) != 0) {
        u32 t = a0[5];
        a0[5] = t + 1;
    } else if (a1[0x1e4] != 0x15 || a1[0x1fd] != 2) {
        u32 t = a0[4];
        a0[4] = t + 1;
        a0[0x13c] = 0;
    } else {
        func_0038A5A0(a0, a1);
    }
}

void func_00197CA0(u8 *p, u8 *owner_unused) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1c) = 0x20;
        if (p[2]) *(u32 *)(p + 0x5c) = 0x40555555;
        else *(u32 *)(p + 0x5c) = 0xc0555555;
        *(u32 *)(p + 0x68) = 0;
    }
}

extern u8 *func_003DA750(u32 a, u32 b, u32 c);
extern void func_001E0D40(void);

u8 *func_001E0CC0(u8 *a0, u32 a1) {
    u8 *o = func_003DA750(0, 3, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001E0D40;
        *(u8 **)(o + 0x18) = a0;
        *(u32 *)(o + 0xd0) = *(u16 *)(a0 + 0x168);
        o[1] = a0[1];
        *(s16 *)(o + 0x26) = 0x3a02;
        o[0x20] = a1;
        o[0x21] = a1 >> 8;
    }
    return o;
}

void func_002FDC50(u8 *p) {
    u8 *q = p + 0x2b8;
    if (p[6] == 0) {
        p[6] = p[6] + 1;
        func_001757E0(p, 0x13, 0);
        p[0x216] = 0;
        *(s16 *)(q + 4) = 0;
        func_00175C00(p, 0);
    } else {
        func_00175700(p);
    }
}

extern u8 D_004D18A0[];

extern void func_003DAA40();

void func_0015F370(u8 *p) {
    s16 t = *(s16 *)(p + 0x1e) - 1;
    *(s16 *)(p + 0x1e) = t;
    if (t != 0) {
        *(f32 *)(p + 0x50) += 0.25f;
        *(f32 *)(p + 0x54) -= 0.25f;
    } else {
        func_003DAA40();
    }
}

extern void func_00186A60(void *p, u32 b);

void func_00203170(u8 *p) {
    s8 m;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    m = *(s8 *)(p + 0x4dd);
    switch (m) {
    case 0:
        p[0x1fd] = 2;
        p[0x1b7] = 1;
        break;
    case 1:
        p[0x1fd] = 1;
        p[0x1b7] = 1;
        break;
    case 2:
        p[0x1fd] = 1;
        p[0x1b7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}

extern void func_001E7F60(u8 *);
extern s32 func_001745B0(void *p);
extern void func_003B56B0(void *p, u32 b);

void func_003B5560(u8 *a0, u32 a1) {
    if (a0[0x22] == 0) func_001E7F60(a0);
    func_00175700(a0);
    a0[0x13c] = func_001745B0(a0);
    func_003B56B0(a0, a1);
}

extern void func_00176160(void *p, u32 b, s32 c, u32 d);

void func_002F3AA0(u8 *p) {
    s32 s;
    func_00175700(p);
    s = *(s8 *)(p + 0x151);
    if (s > 0) {
        func_00176160(p, 0, (s8)s + p[0x25] * 4, 1);
        *(s8 *)(p + 0x151) = 0;
    } else if (s < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00175C00(p, 0);
    }
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void func_0035F430();

extern void func_00126400();

void func_002D5C20(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    *(u32 *)(p + 0x60) = 0x41bc9249;
    *(u32 *)(p + 0x6c) = 0xbf700000;
    if (p[0x1e6]) *(u32 *)(p + 0x5c) = 0xc0855555;
    else *(u32 *)(p + 0x5c) = 0x40855555;
    p[0x20d] = 2;
    func_00126400();
    func_001757E0(p, 0xf, 3);
}

extern void (*D_00463DF0[])(void *, void *, void *);

void func_0036FF60(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    D_00463DF0[p[5]](p, q, p + 0x88);
    if (q[0x1e4] != 0x1d || q[0x1fd] != 9) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13c] = 0;
    }
}

extern void func_001DB410(void);

void func_001DB390(u8 *a0, u32 a1) {
    u8 *o = func_003DA750(0, 3, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001DB410;
        *(u32 *)(o + 0x18) = *(u32 *)(a0 + 0x18);
        o[1] = a0[1];
        o[0x20] = a1;
        o[0x21] = a0[0x21];
        *(s16 *)(o + 0x26) = 0x3501;
        *(f32 *)(o + 0x34) = *(f32 *)(a0 + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(a0 + 0x38);
    }
}

void func_0013C510(u8 *p) {
    f32 t;
    *(u32 *)(p + 0xd0) |= 0x800000;
    *(s32 *)(p + 0x44) -= 0x100;
    *(u32 *)(p + 0x44) = *(u16 *)(p + 0x44);
    *(f32 *)(p + 0x50) += 0.05f;
    *(f32 *)(p + 0x54) += 0.05f;
    t = *(f32 *)(p + 0x74) - 0.05f;
    *(f32 *)(p + 0x74) = t;
    if (t <= 0.0f) {
        u32 c = p[4];
        p[4] = c + 1;
        *(f32 *)(p + 0x74) = 0.0f;
        p[0x13c] = 0;
        *(s16 *)(p + 0x1c) = 0x3c;
    }
}

extern void func_00183D50(u8 *);

void func_002DA510(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6c);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 c = p[5];
        p[5] = c + 1;
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x64);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
    }
}

extern void func_001266A0(void *p, u32 b, u32 c);
extern void func_0015D010(void *p, void *v);
extern void func_0018C6E0(void *);
extern void func_0019CD70(void *p);

void func_00225960(u8 *p) {
    u32 v[4];
    func_001266A0(p, 6, 6);
    v[0] = 0xc2960000;
    v[1] = 0x4331db6d;
    func_0015D010(p, v);
    p[0x1b4] = 0xa;
    *(u32 *)(p + 0x5c) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6c) = 0;
    func_0018C6E0(p);
    func_001757E0(p, 0xf, 2);
    func_0019CD70(p);
}

extern void func_00185490(void *p);
extern void func_00175910(void *p, u32 b, u32 c, u32 d);

void func_002207B0(u8 *p) {
    u32 t = p[6];
    p[6] = t + 2;
    func_00185490(p);
    if (p[0x1e6]) {
        *(u32 *)(p + 0x5c) = 0xc0200000;
        *(u32 *)(p + 0x68) = 0x3cd55555;
    } else {
        *(u32 *)(p + 0x5c) = 0x40200000;
        *(u32 *)(p + 0x68) = 0xbcd55555;
    }
    *(u32 *)(p + 0x60) = 0x41892492;
    *(u32 *)(p + 0x6c) = 0xbf4db6db;
    func_00175910(p, 1, 2, 1);
}

extern void func_00241430(void *p);
extern void func_001A6BE0(void *p, u32 b);

void func_002412D0(u8 *p) {
    u8 *q;
    p[0x1fe] = 1;
    func_00241430(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x206] = 1;
        q = *(u8 **)(p + 0x1dc);
        *(u8 **)(q + 0x1c8) = p;
        q[0x20a] = 1;
        q[0x1e6] = p[0x1e6];
        q[0x20d] = 2;
        q[0x1b5] = 0x23;
        q[6] = 0;
        q[0x211] = 0;
        func_00126400();
        func_001A6BE0(p, 0);
    }
}

extern s32 func_00189310(void *p, void *g, void *c);
extern void func_0018A990(void *p, void *c);
extern u8 D_00458750[];

s32 func_002A73E0(u8 *p) {
    if (!func_00189310(p, D_00458750, p + 0x390)) return 0;
    func_0018A990(p, p + 0x390);
    if (((s8 *)p)[0x1e8] && p[0x210] == 0) return 0;
    *(s8 *)(p + 0x1e8) = *(s8 *)(p + 0x1e8) + 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1fd] = 6;
    func_00186A60(p, 0x15);
    return 1;
}

extern void func_001830D0(void *p, void *v);
extern void func_0036BFF0(void *p, u32 b, u32 c, u32 d);

typedef struct { f32 x, y, z; } V3;
extern u8 *D_004D18B8;
extern f32 D_004F1F50;
extern s32 func_00174810(void *p);

void func_0015BAC0(u8 *p) {
    u8 *q = D_004D18B8;
    p[0x13c] = 0;
    if (D_004D18A0[0] > 3) {
        if (!func_00174810(q)) p[0x13c] = 1;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(f32 *)(p + 0x38) = D_004F1F50 - 50.0f;
    *(f32 *)(p + 0x3c) += 4.0f;
}

extern s32 D_00472CF0[][2];

void func_003A48D0(u8 *p) {
    s32 *e = D_00472CF0[p[0x20]];
    f32 a = 1.6666666f * (f32)e[0] / 65536.0f;
    f32 b;
    if (*(s16 *)(p + 0x140) != 0) a = -a;
    *(f32 *)(p + 0x5c) = a;
    *(u32 *)(p + 0x68) = 0;
    b = 2.1428571f * (f32)e[1] / 65536.0f;
    *(f32 *)(p + 0x60) = b;
    *(u32 *)(p + 0x6c) = 0xbf9a4924;
}

