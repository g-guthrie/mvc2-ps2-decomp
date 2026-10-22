typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa19_e.c "-O3 -Op -sdatathreshold 8" */
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G_e;
extern G_e *D_004C2794;
extern f32 D_004535E0[];

void func_00259F90(u8 *p) {
    extern void func_002555E0(u8 *);
    extern void func_0025A130(void);
    extern void func_00183D10(u8 *);
    extern void func_00175700(u8 *);
    f32 z = 0.0f;
    func_002555E0(p);
    if (*(s8 *)(p + 0x151) == 3) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0025A130();
    }
    if (*(s8 *)(p + 0x151) == 2) {
        f32 *tb;
        *(s8 *)(p + 0x151) = 0;
        tb = D_004535E0;
        tb += *(s16 *)(p + 0x1C);
        *(f32 *)(p + 0x5C) = tb[0];
        *(f32 *)(p + 0x68) = tb[1];
        *(f32 *)(p + 0x5C) = p[0x1E6] ? -*(f32 *)(p + 0x5C) : *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = p[0x1E6] ? -*(f32 *)(p + 0x68) : *(f32 *)(p + 0x68);
        p[0x1B5] = *(s16 *)(p + 0x1C) / 2 + 0x37;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 2;
        func_00183D10(p);
    }
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else {
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x60) = z;
        *(f32 *)(p + 0x68) = z;
        *(f32 *)(p + 0x6C) = z;
    }
    func_00175700(p);
}

typedef struct { s8 b0; s8 b1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7; } S_e;
extern S_e *D_004C29C0, *D_004C29C4;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_0038EC30(u8 *p) {
    extern void func_0038EAB0(void);
    extern void func_0038E740(u8 *);
    extern void func_001E7F60(u8 *);
    S_e *g;
    s32 a;
    s32 b;
    u8 n;
    if (*(*(u8 **)(p + 0x18) + 4) >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        func_0038EAB0();
        return;
    }
    if (D_004D18DC[0] & (1 << D_004D18DB[0])) return;
    D_004C29C4->b1 = 1;
    p[0x13C] = 1;
    a = D_004C29C0->b2;
    g = D_004C29C4;
    b = g->b6;
    if (a < b) {
        p[0x13C] = 0;
        return;
    }
    if (a == b) {
        g->b1 = 2;
        D_004C29C4->b0 = -1;
        p[0x13C] = 1;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        s8 v;
        D_004C29C4->b1 = 1;
        D_004C29C4->b0 = -1;
        D_004C29C0->b7 = 0xFF;
        v = *(s8 *)(p + 0x1B4) - 1;
        *(s8 *)(p + 0x1B4) = v;
        if (v == 0) {
            u32 c = D_004C29C4->b5;
            D_004C29C4->b5 = c + 1;
            n = 0x56;
            if (!((u8)(c + 1) < 3)) {
                n = 0x55;
                D_004C29C4->b5 = 0;
            }
            p[0x1B5] = n;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    func_0038E740(p);
    if (D_004C29C0->b7 == 0) {
        func_001E7F60(p);
    }
}
