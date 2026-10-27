typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x29]; s8 f29; u8 pad1[0x5E]; s8 f88; s8 f89; u8 pad2[0xE]; s32 f98; } G6F;
extern G6F *D_004C2840;
extern s32 D_004C28BC;
extern s32 D_004C28B8;
extern s32 D_004C28AC;
extern s32 D_004C28B0;

void func_0016F640(void) {
    extern void func_00176230();
    extern void *func_0011D740(void *, const void *, unsigned int);
    extern void func_0012DA40();
    G6F *g;
    D_004C2840->f98 = D_004C28BC;
    g = D_004C2840;
    switch (g->f88) {
    case 0:
        if (g->f89 == 1) break;
    case 1:
        g->f98 = D_004C28BC + 0x3F0000;
        break;
    }
    func_00176230(D_004C28B8, D_004C2840->f98);
    func_0011D740((void *)D_004C28AC, (const void *)(D_004C28B8 + 0x185000), 0x4A000);
    func_0012DA40(0x346, D_004C28B8, 2);
    if (D_004C2840->f29 != 0) {
        func_0012DA40(0x98, D_004C28B0, 2);
    } else {
        func_0012DA40(0x97, D_004C28B0, 2);
    }
}

typedef struct { u8 pad0[0x7C]; s16 f7c[16]; } G94;
extern G94 *D_004C2794;

void func_001EA5C0(u8 *p) {
    extern s32 func_00175700();
    extern void func_00184540();
    switch (p[0x1FC]) {
    case 0:
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        }
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x1B5] = 0x16;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    }
}

typedef struct { f32 x, y, z; } V3g;
extern u8 *D_004C283C;
extern u8 D_004C27D0;
extern V3g D_0045E380[];
extern V3g D_0045E3B0[];

void func_0032ED60(s32 n) {
    extern u8 *func_003DA750();
    extern void func_0032EE50();
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0032EE50;
        if (n < 2) {
            *(s16 *)(o + 0xCC) = 2;
            *(u8 **)(o + 0x84) = D_004C283C;
        } else {
            *(s16 *)(o + 0xCC) = 0xD;
            *(u8 **)(o + 0x84) = D_004C283C;
        }
        *(s32 *)(o + 0xD0) = 0x805;
        if (D_004C27D0 == 0) {
            *(V3g *)(o + 0x34) = D_0045E380[n];
        } else {
            *(V3g *)(o + 0x34) = D_0045E3B0[n];
        }
    }
}

extern void (*D_0045DD10[])();

void func_00321D50(u8 *p) {
    extern s32 func_00175700();
    extern void func_00184540();
    extern s32 func_00182E20();
    extern s32 func_00182D30();
    extern void func_001757E0();
    u8 *s0, *s1;
    s1 = *(u8 **)(p + 0x1DC);
    s0 = p + 0x2B8;
    if ((s8)func_00175700(p) < 0 && *(s8 *)(s0 + 0xC) <= 0) {
        *(s8 *)(p + 0x1B1) = -0x80;
        p[0x201] = 0;
        func_00184540(p);
        return;
    }
    if (*(s8 *)(s0 + 0xC) > 0) {
        s16 h;
        if (func_00182E20(p) != 0) p[0x152] = 1;
        h = *(s16 *)(s1 + 0x270) - 1;
        *(s16 *)(s1 + 0x270) = h;
        if (func_00182D30(s1) != 0) {
            *(s8 *)(s0 + 0xC) = -1;
            func_001757E0(p, 0xF, 5);
        }
    }
    D_0045DD10[*(s8 *)(p + 0x151) >> 1](p, s1);
}

typedef struct { V3g a; f32 pad[6]; } E36;
extern E36 D_00440920[];
extern E36 D_00440AD0[];
extern u8 *D_004C2818;
extern u8 *D_004C27D8;

void func_00140020(s32 n) {
    extern u8 *func_003DA750();
    extern void func_00140110();
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00140110;
        if (n < 6) {
            *(s16 *)(o + 0xCC) = n + 0xB;
            *(u8 **)(o + 0x84) = D_004C2818;
        } else {
            *(s16 *)(o + 0xCC) = n - 5;
            *(u8 **)(o + 0x84) = D_004C27D8;
        }
        *(s32 *)(o + 0xD0) = 0x800C11;
        o[0x20] = n;
        *(V3g *)(o + 0x34) = D_00440920[n].a;
        *(V3g *)(o + 0x50) = D_00440AD0[n].a;
        *(u32 *)(o + 0x78) = 0x3F4CCCCD;
        *(u32 *)(o + 0x7C) = 0x3F4CCCCD;
        *(u32 *)(o + 0x80) = 0x3F4CCCCD;
    }
}
