typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C04A0[4];
typedef struct { u8 pad[0x7C]; s16 h7C[1]; } S794;
extern S794 *D_004C2794;

void func_00250940(u8 *p, s32 a) {
    u8 *q;
    s32 idx;
    idx = (p[0x269] == 3) ? 3 : 0;
    p[0x1B5] = D_004C04A0[(u8)(a + (u8)idx)];
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]] += 1;
}

typedef struct { u8 pad0[7]; u8 b7; f32 f8; } S974;
extern S974 *D_004C2974;
extern void func_001757E0(void *p, s32 a, s32 b);

void func_003670F0(u8 *p) {
    p[5] = 3;
    *(s16 *)(p + 0x1E) = 0x20;
    D_004C2974->f8 = *(f32 *)(p + 0x34);
    p[0x168] = ((*(s16 *)(p + 0x140) ^ D_004C2974->b7) != 0) ? 0xA : 0xB;
    func_001757E0(p, 0x17, p[0x168]);
}

typedef struct { u8 a, b, c, d; } Q4;
extern u8 D_004C2A28;
extern u8 D_004C2A24;
extern Q4 D_004D1860[];

void func_003CE490(void) {
    s32 i;
    D_004C2A28 = 0;
    D_004C2A24 = 0;
    i = 0;
    do {
        D_004D1860[i].a = 0;
        D_004D1860[i].b = 0;
        D_004D1860[i].c = 0;
        D_004D1860[i].d = 0;
        i++;
    } while (i < 12);
    i = 12;
    do {
        D_004D1860[i].a = 0;
        D_004D1860[i].b = 0;
        D_004D1860[i].c = 0;
        D_004D1860[i].d = 0;
        i++;
    } while (i < 15);
}

extern u32 D_004C27FC;
extern void func_0014ECD0(void);
extern u8 *func_003DA750(s32 a, s32 b, s32 c);

void func_0014EC30(u8 *p, f32 x, f32 y, f32 z) {
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0014ECD0;
        *(s16 *)(o + 0xCC) = 0x3A;
        *(u32 *)(o + 0x84) = D_004C27FC;
        *(u32 *)(o + 0xD0) = 0x21;
        *(f32 *)(o + 0x34) = x;
        *(f32 *)(o + 0x38) = y;
        *(f32 *)(o + 0x3C) = z;
        *(u8 **)(o + 0x14) = p;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}

typedef struct { u16 h0; u8 pad2[2]; f32 f4; } S9AC;
extern S9AC *D_004C29AC;
extern void func_003859F0(void);
extern s32 func_00175700(void *p);

typedef struct Ent3847 Ent3847;
struct Ent3847 {
    u8 pad0[0x18]; Ent3847 *f18; u8 pad1c[2]; s16 h1E; u8 pad20[4]; u8 b24; u8 pad25[0xF];
    f32 f34; f32 f38; u8 pad3c[0x20]; f32 f5C; u8 pad60[0x108]; u16 h168;
};

void func_003847D0(Ent3847 *p) {
    if (D_004C29AC->h0 != p->f18->h168) {
        func_003859F0();
    } else {
        p->f34 = p->f18->f34;
        p->f38 = p->f18->f38;
        p->b24 = 0;
        D_004C29AC->f4 += p->f5C;
        p->f34 += D_004C29AC->f4;
        if (p->f18->h1E <= 0) {
            func_003859F0();
        } else {
            func_00175700(p);
        }
    }
}

typedef struct { u8 pad[0x1C]; u32 w1C; u8 pad20[0xA]; s8 b2A; u8 pad2B[0x19]; s8 b44; u8 pad45[0x47]; s8 b8C; u8 pad8D[2]; s8 b8F; } S840;
extern S840 *D_004C2840;

extern void func_00176160(void *p, s32 a, s32 b, s32 c);
extern void func_00175C00();

void func_0023F580(u8 *p) {
    s8 m = *(s8 *)(p + 0x2B9);
    u8 *q = p + 0x2B8;
    if (m != 0) {
        if (p[0x1E4] == 0x15 && p[0x1FD] == 3 && p[0x169] == 0x16 && p[0x168] == 0 && m != 0) {
            if (D_004C2840->w1C & 1) {
                func_00176160(p, 0, 0, 1);
            } else {
                func_00175C00(p, 1);
            }
            return;
        }
        q[1] = 0;
        func_00175C00(p, 0);
    }
}

extern u32 D_004D1778[];
extern u32 D_004D1774[];
extern u32 D_004D1780[];
extern u32 D_004D177C[];
extern void func_001740C0(void);
extern void func_001740A0(void);

void func_00172D80(u8 *p) {
    S840 *g;
    *(u32 *)(p + 0x55C) = 0;
    *(u32 *)(p + 0x558) = 0;
    *(u32 *)(p + 0x564) = 0;
    *(u32 *)(p + 0x560) = 0;
    D_004D1778[0] = 0;
    g = D_004C2840;
    D_004D1774[0] = 0;
    D_004D1780[0] = 0;
    D_004D177C[0] = 0;
    if (g->b2A != 0) {
        func_001740C0();
    } else if (g->b44 != 0 || g->b8C != 0) {
        if (g->b8F != 0) {
            func_001740C0();
        } else {
            func_001740A0();
        }
    } else {
        func_001740C0();
    }
}

typedef struct { u8 pad[3]; u8 b3; } S970;
extern S970 *D_004C2970;
extern s32 func_003657D0(void *p, void *q, s32 a);
extern void func_001E7F60(void *p);

void func_00365280(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (D_004C2970->b3 == 0) {
        if (func_003657D0(p, *(void **)(p + 0x18), 0x60) != 0) {
            u32 t = p[5];
            p[5] = t + 1;
            D_004C2970->b3 = 1;
        }
    }
    func_001E7F60(p);
}
