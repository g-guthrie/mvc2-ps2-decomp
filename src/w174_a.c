struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } GA;
extern GA *D_004C2794;

void func_002B71E0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00397580(u8 *, s32);
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        if (p[0x1B7] == 0) {
            p[0x1b5] = 0x4F;
            p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
            *(s32 *)(p + 0x1d8) = 0;
            D_004C2794->f7c[p[2]]++;
        } else {
            p[0x1b5] = 0x4F;
            p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
            *(s32 *)(p + 0x1d8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        func_00397580(p, 2);
    }
}

static inline void reset_command(u8 *p, u8 command) {
    *(volatile u8 *)(p + 0x1b5) = command;
    p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
    *(s32 *)(p + 0x1d8) = 0;
    D_004C2794->f7c[p[2]]++;
}

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
typedef struct { u8 pad[0x1C]; s32 f1c; } GB;
extern GB *D_004C2840;
typedef struct { f32 x, y, z; } V3;

void func_00353E90(u8 *p) {
    extern void func_00354000(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    u8 *d, *q, *s;

    d = p + 0x88;
    q = *(u8 **)(p + 0x14);
    s = q + 0x88;
    *(s8 *)(p + 0x13C) = *(s8 *)(q + 0x13C);
    if (q[4] >= 2) {
        p[4]++;
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (q[0x20] != 0) {
        *(s8 *)(d + 0) = *(s8 *)(s + 0);
        d[1] = s[1];
        *(u16 *)(d + 0xA) = *(u16 *)(s + 0xA);
        *(u16 *)(d + 0xC) = *(u16 *)(s + 0xC);
        func_00354000(p);
    } else {
        if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
            s32 u = 1 - (D_004C2840->f1c & 1);
            func_00175910(p, 0x16, 2, u * 19);
        }
        p[0x13C] = 1;
    }
}

extern u8 D_004BFD78[2];
extern u8 D_004BFD7C[2];
extern u8 data_s8_004BFD80[2];

void func_00203DB0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(void **)(p + 0x408) = D_004BFD78;
        p[0x1BB] = 0;
        p[0x2B6] = 1;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(void **)(p + 0x408) = D_004BFD7C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        func_001E3710(p, 0x16);
        *(void **)(p + 0x408) = data_s8_004BFD80;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    reset_command(p, p[0x1B5]);
    func_001757E0(p, 7, p[0x168]);
}

extern s16 D_004C27A4[1];
extern void func_003C81C0(void);

u8 *func_003C80C0(u8 *a, s32 b, s32 c) {
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *o = 0;
    if (D_004C27A4[0] > 13) {
        o = func_003DA750(0, 2, 0);
        *(void **)(o + 0x10) = (void *)func_003C81C0;
        o[0x20] = 0;
        o[0x21] = c;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(u16 *)(o + 0x26) = o[0x20] | 0x3800;
        o = func_003DA750(0, 2, 0);
        *(void **)(o + 0x10) = (void *)func_003C81C0;
        o[0x20] = 1;
        o[0x21] = c;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(u16 *)(o + 0x26) = o[0x20] | 0x3800;
        o = func_003DA750(0, 2, 0);
        *(void **)(o + 0x10) = (void *)func_003C81C0;
        o[0x20] = 2;
        o[0x21] = c;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(u16 *)(o + 0x26) = o[0x20] | 0x3800;
        a[0x2BC] = 0;
    }
    return o;
}

void func_00311050(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001DD8A0(u8 *, s32, s32);
    extern void func_001843A0(u8 *);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 2) {
        *(s8 *)(p + 0x151) &= ~2;
        func_001DD8A0(p, 9, 0);
    }
    if (*(s8 *)(p + 0x151) & 4) {
        *(s8 *)(p + 0x151) &= ~4;
        func_001DD8A0(p, 9, 1);
    }
    if (*(s8 *)(p + 0x151) & 8) {
        *(s8 *)(p + 0x151) &= ~8;
        p[0x1b5] = 0x1A;
        p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
        *(s32 *)(p + 0x1d8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    if (*(f32 *)(p + 0x430) >= *(f32 *)(p + 0x38)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}

void func_0030B5C0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_003BA230(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            *(s16 *)(p + 0x1E) = 4;
            if (p[0x20D] != 2) {
                func_003BA230(p, 0xA, 0);
            } else {
                func_003BA230(p, 0xB, 0);
            }
        }
    } else {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6]++;
        if (p[0x20D] == 2) {
            func_001757E0(p, 0x16, 0x10);
        } else {
            func_001757E0(p, 0x16, 0xE);
        }
    }
}

extern u8 D_0045AE20[];
extern u8 D_0045AFD0[];

void func_003B6230(u8 *p, u8 *q) {
    extern void func_003B60A0(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *r;
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    r = p + 0x88;
    if (*(s8 *)(p + 0x1B2) != 0) {
        p[4] = 2;
        p[5] = 0;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[4] = 2;
        p[5] = 0;
    }
    if (*(s8 *)(r + 0x24) == 0) {
        if ((*(u16 *)(q + 0x362) & 0x20) != 0) {
            r[0x24] = 1;
        }
    } else if (*(s16 *)(p + 0x1C) < 0x3D) {
        func_003B60A0(p);
        return;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        func_003B60A0(p);
    } else {
        func_00175700(p);
        func_001E7F60(p);
    }
}

extern s32 D_004F1CDC[];
extern s32 D_004C283C;

void func_003451F0(u8 *p) {
    extern void func_003DAA40(struct Object *);
    extern s32 func_00417A40(void);
    s16 v;
    if (D_004F1CDC[0] > 0) {
        func_003DAA40((struct Object *)p);
    }
    switch (p[4]) {
    case 0:
        p[0x13C] = 1;
        *(s16 *)(p + 0xCC) = *(s16 *)(p + 0x1C) / 2 + (p[0x20] * 4 + 0x4E);
        *(s32 *)(p + 0x84) = D_004C283C;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 8) {
            *(s16 *)(p + 0x1C) = 0;
            *(s16 *)(p + 0x1E) = func_00417A40() % 30 + 30;
            p[4]++;
        }
        break;
    case 1:
        p[0x13C] = 0;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= *(s16 *)(p + 0x1E)) {
            *(s16 *)(p + 0x1C) = 0;
            p[4] = 0;
        }
        break;
    default:
        break;
    }
}

