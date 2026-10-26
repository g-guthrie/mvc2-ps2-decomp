typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 pad0[4]; s8 f4; u8 pad5[3]; s16 f8; } S2840;
extern S2840 *D_004C2840;
extern u8 *D_004C2920;
extern u8 D_00583B9B[];
extern s32 func_0032C180(s32 a);
extern void func_0013BEF0(u8 *a);

void func_0032C5D0(void) {
    if (func_0032C180(0) == 0) {
        D_004C2840->f8 = D_004C2840->f8 - 1;
        if (D_004C2840->f8 <= 0) {
            D_004C2840->f4 = D_004C2840->f4 + 1;
            D_00583B9B[0] = 0;
            func_0013BEF0(D_004C2920);
        }
    }
}

extern void (*D_004BF348[2])(u8 *a0, u8 *a1);
extern void func_00132A50(u8 *a, u8 *b);
extern void func_00132B00(u8 *a, u8 *b);

void func_00132810(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 0x18);
    if ((*(u32 *)(a1 + 0x428) & 0x7000000) == 0) {
        D_004BF348[a0[4]](a0, a1);
    }
    func_00132A50(a0, *(u8 **)(a0 + 0x18));
    func_00132B00(a0, *(u8 **)(a0 + 0x18));
}

extern s32 func_00175700(u8 *);
extern int func_00174470(const void *);
extern void func_001E1FC0(u8 *a, u8 *b);
void func_001E1B00(u8 *a0, u8 *a1) {
    func_00175700(a0);
    *(f32 *)(a0 + 0x34) += *(f32 *)(a0 + 0x5C);
    *(f32 *)(a0 + 0x5C) += *(f32 *)(a0 + 0x68);
    if (func_00174470(a0) == 0) func_001E1FC0(a0, a1);
}

extern s32 D_004CD1D8[];
extern u8 D_004CD1E6[];
extern u8 *D_004C287C;
extern void func_0012DA40(s32 a, u8 *b, s32 c);
extern s32 func_001E5870(u8 *a, s32 b);
extern void func_003DCD40(u8 *a, s32 b, s32 c);
void func_001E22C0(void) {
    u8 *p = D_004C287C;
    if (D_004CD1D8[0] != 0x3E) {
        func_0012DA40(0x3E, p, 1);
        D_004CD1D8[0] = 0x3E;
        D_004CD1E6[0] = func_001E5870(p, 5);
        func_003DCD40(D_004C287C, 0, 4);
    }
}

void func_0013A350(u8 *a0) {
    if (a0[0x20] != 0) {
        *(s32 *)(a0 + 0x48) += 0x200;
        if (*(s32 *)(a0 + 0x48) >= 0x2000) {
            u32 t = a0[4];
            a0[4] = t + 1;
            a0[0x13C] = 0;
        }
    } else {
        *(s32 *)(a0 + 0x48) -= 0x200;
        if (*(s32 *)(a0 + 0x48) < -0x1FFF) {
            u32 t = a0[4];
            a0[4] = t + 1;
            a0[0x13C] = 0;
        }
    }
}

extern f32 D_004F1FD0[];
void func_0034B500(u8 *a0) {
    *(f32 *)(a0 + 0x34) += *(f32 *)(a0 + 0x5C);
    *(f32 *)(a0 + 0x5C) += *(f32 *)(a0 + 0x68);
    *(f32 *)(a0 + 0x38) += *(f32 *)(a0 + 0x60);
    *(f32 *)(a0 + 0x60) += *(f32 *)(a0 + 0x6C);
    if (*(f32 *)(a0 + 0x38) > D_004F1FD0[0]) {
        u32 t = a0[4];
        a0[4] = t + 1;
    }
}

extern u8 D_004BFEF0[8];
extern void func_001757E0(u8 *a, s32 b, u8 c);
extern void func_001E3210(u8 *a, s32 b);
void func_00219490(u8 *a0) {
    s32 v;
    a0[0x1E6] = D_004BFEF0[a0[0x22]];
    *(u16 *)(a0 + 0x140) = a0[0x1E6];
    v = a0[0x22];
    if (v >= 5) v = -(v - 8);
    func_001757E0(a0, 0x15, v * 2 + 10);
    func_001E3210(a0, 0x20);
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0035DF70();
void func_0035DEF0(u8 *a0, u8 a1, u8 a2) {
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        *(void **)(p + 0x10) = func_0035DF70;
        *(s16 *)(p + 0x26) = 0xD02;
        *(u32 *)(p + 0x18) = *(u32 *)(a0 + 0x18);
        *(u8 **)(p + 0x14) = a0;
        p[0x20] = a1;
        p[0x21] = a2;
        p[1] = a0[1];
    }
}

typedef struct { u8 a[6]; } E6;
extern E6 D_0044C0E0[];
extern void func_00175580(u8 *a, s32 b, u8 c, s8 d);
void func_001BD140(u8 *a0, u8 *a1) {
    *(s16 *)(a0 + 0x140) = *(s16 *)(a1 + 0x140);
    *(V3 *)(a0 + 0x34) = *(V3 *)(a1 + 0x34);
    if (*(s8 *)(a1 + 0x151) == 0) {
        u32 t = a0[5];
        a0[5] = t + 1;
    } else {
        {
            E6 *e = &D_0044C0E0[a0[0x20]];
            u8 *q = e->a;
            func_00175580(a0, 0x1B, q[5], *(s8 *)(a1 + 0x150));
        }
    }
}

extern void func_001548D0(u8 *a, u32 *b, s32 c);
extern void func_001E3710(u8 *a, s32 b);
void func_0025E030(u8 *a0) {
    u32 v[3];
    if (*(s8 *)(a0 + 0x151) == 1) {
        a0[0x151] = 0;
        v[0] = 0x42A00000;
        v[1] = 0x42092492;
        func_001548D0(a0, v, 2);
        func_001E3710(a0, 2);
    }
    if ((s8)func_00175700(a0) < 0) {
        u32 t = a0[5];
        a0[5] = t + 1;
    }
}

extern void func_00183D50(u8 *a);
void func_0021FC30(u8 *a0) {
    func_00175700(a0);
    if (*(f32 *)(a0 + 0x430) > *(f32 *)(a0 + 0x38)) {
        u32 t = a0[6];
        a0[6] = t + 1;
        *(f32 *)(a0 + 0x38) = *(f32 *)(a0 + 0x430);
        a0[0x210] = 0;
        func_001E3710(a0, 0x34);
        a0[0x20D] = 0;
        *(u32 *)(a0 + 0x5C) = 0;
        *(u32 *)(a0 + 0x60) = 0;
        *(u32 *)(a0 + 0x68) = 0;
        *(u32 *)(a0 + 0x6C) = 0;
        func_001757E0(a0, 0x15, 0xE);
        func_00183D50(a0);
    }
}

typedef struct { s16 v; s16 pad; } S16x2;
extern S16x2 D_00445440[];
extern f32 D_004453B0[];
extern u32 D_004C2838;
extern void func_003DAA40(u8 *a);
void func_0015E060(u8 *a0) {
    s32 v = *(s16 *)(a0 + 0x1C);
    if (v < 9) {
        *(s16 *)(a0 + 0x1C) = v + 1;
    } else {
        s32 w = *(s16 *)(a0 + 0x1E);
        if (w > 10) {
            func_003DAA40(a0);
        } else {
            *(s16 *)(a0 + 0xCC) = D_00445440[w].v;
            *(u32 *)(a0 + 0x84) = D_004C2838;
            *(f32 *)(a0 + 0x74) = D_004453B0[*(s16 *)(a0 + 0x1E)];
            *(s16 *)(a0 + 0x1E) = *(s16 *)(a0 + 0x1E) + 1;
        }
    }
}
