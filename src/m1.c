typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s32 *)(q + 0xDC) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 0x1E) = *(s16 *)(q + 0x1E);
        } else {
            *(s16 *)(p + 0x1E) = *(s16 *)(q + 0x1E);
        }
    }
}

void func_00150C00(u8 *p) {
    func_0014E770(p);
    *(s8 *)(p + 0x13C) = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}

typedef struct { f32 x, y, z; } V3;

void func_00141540(V3 *out, V3 *a, V3 *b, f32 s) {
    V3 t;
    t.x = (a->x - b->x) / s;
    t.y = (a->y - b->y) / s;
    t.z = (a->z - b->z) / s;
    *out = t;
}

extern void func_001B0FA0(void *, s32);
extern void func_00175670(void *);
extern s16 D_004D1802;

s16 func_00280D10(void) {
    s16 v, r;
    v = D_004D1802 - 0x14;
    if (v < 0) v = 0;
    if (v > 11) v = 11;
    r = (v >> 2) % 3;
    return (u8)r;
}

void func_001B2BC0(u8 *p) {
    if (*(u8 *)(*(u8 **)(p + 0x18) + 0x1E4) != 0x16) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            func_001B0FA0(p, 7);
        }
        if (*(s8 *)(p + 0x153) >= 0) {
            func_00175670(p);
        }
    }
}

extern void func_00186A60(void *, s32);
extern void func_003AE8A0(void *);

void func_00294AB0(u8 *p) {
    u8 *q = p + 0x2B8;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 0;
        p[0x20D] = 0;
        q[2] = 2;
        break;
    case 1:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 0;
        p[0x20D] = 0;
        q[2] = 2;
        break;
    }
    func_00186A60(p, 0x15);
}

extern void func_0018ED20();
extern s32 func_00175700();
extern void func_0018EB00();
extern void func_001757E0(void *, s32, s32);
extern void func_001843A0();

void func_00299B50(u8 *p) {
    if (p[6] == 0) {
        p[6] = p[6] + 1;
        func_001757E0(p, 0x14, 6);
        *(s16 *)(p + 0x1C) = 0x3C;
    } else {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            func_001843A0();
        } else {
            func_00175700();
        }
    }
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0019DFD0();

void func_0019DF50(u8 *p, s32 a, s32 b) {
    u8 *o = func_003DA750(0, 3, 1);
    if (o != 0) {
        *(void **)(o + 0x10) = func_0019DFD0;
        *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[0x20] = a;
        o[0x21] = b;
        *(s16 *)(o + 0x26) = 0xB00;
        o[0x13C] = 0;
    }
}

extern void func_001AC3F0(void *, void *);

void func_001AA570(u8 *p, u8 *q) {
    if (q[0x1E4] == 0x1D && q[0x1FD] == 4) {
        *(u32 *)(p + 0xD0) = p[6];
        *(u32 *)(p + 0xD4) = p[7];
        p[6] = 0x11;
        p[7] = 0;
    } else {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_001AC3F0(p, q);
        }
    }
}

extern int func_00174470(const void *);
extern void func_00350FD0(void *);
extern void func_001E7F60(void *);

void func_00350790(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00174470(p) == 0) {
        func_00350FD0(p);
    } else {
        func_001E7F60(p);
    }
}

extern void func_0035DEF0(u8 *, u8, u8);
extern void func_0035E730(u8 *, void *);

void func_0035E0E0(u8 *p, void *q) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        *(s16 *)(p + 0x1C) = 3;
        func_0035DEF0(p, 1, p[0x1E]);
    }
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        func_0035E730(p, q);
    }
}

extern void func_0039C3F0();
extern void func_0039C4D0(void *, void *, void *);
extern u8 D_004B8700[][10];

void func_0039C050(u8 *p) {
    u8 *q;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    func_0039C3F0();
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        func_0039C4D0(p, q, D_004B8700[p[0x1B7] + p[0x20] * 2]);
        *(s16 *)(p + 0x1E) = 0x18;
    }
}

void func_0017D0C0(u8 *p) {
    if (p[6] == 0) {
        p[6] = p[6] + 1;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x28;
        func_001757E0(p, 0x18, 4);
    } else {
        s16 v;
        func_00175700();
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            p[0x26A] = 2;
            p[7] = 0;
            p[6] = 0;
            p[0x201] = 2;
        }
    }
}

extern void func_00176160(void *, s32, s32, s32);
extern void func_00175C00(void *, s32);

void func_00214620(u8 *p) {
    if (p[6] == 0) {
        p[6] = p[6] + 1;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_00176160(p, 1, 0x19, 1);
        func_001757E0(p, 0x13, 4);
    } else {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_00175C00(p, 0);
            func_001843A0(p);
        }
    }
}
