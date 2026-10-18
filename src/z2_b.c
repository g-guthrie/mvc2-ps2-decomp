typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[5]; u8 b5; u8 pad1[0x16]; s16 s1c; u8 pad2[0x16]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; u8 pad5[0xCC]; u8 b13c; } P351470;
extern u8 *D_004C2960;
void func_00351470(P351470 *p)
{
    extern s32 func_00174240();
    extern void func_00175700();
    extern void func_001E7F60();
    extern void func_001757E0(P351470 *, s32, u8);
    s16 v;
    p->b13c = 1;
    v = p->s1c - 1;
    p->s1c = v;
    if (v != 0) {
        if (func_00174240(p)) {
            p->f34 += p->f5c;
        }
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        func_00175700(p);
        func_001E7F60(p);
    } else {
        { u32 t = p->b5; p->b5 = t + 1; }
        p->b13c = 0;
        func_001757E0(p, 0x16, *D_004C2960 + 0x12);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G305690;
extern G305690 *D_004C2794;
extern s32 D_004C1508[1], D_004C150C[1], D_004C1510[1];
void func_00305690(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = D_004C1508;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(s32 **)(p + 0x408) = D_004C150C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(s32 **)(p + 0x408) = D_004C1510;
        p[0x1BB] = 2;
        break;
    }
    { u32 t = *(volatile u8 *)(p + 0x1B5); p[0x1B5] = t; }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}

extern s32 D_004C2870, D_004C2848, D_004C284C;
extern u8 D_004D17C2[];
extern u8 D_004F4480[], D_004F4494[];
void func_00170C30(void)
{
    extern s32 func_003EC160(s32, s32);
    extern void func_0012F4C0(), func_00170BF0(), func_003D6B70(), func_0012F460(), func_0016ECC0();
    extern void func_0012F3E0(u8 *), func_003D7630(), func_0012F450(), func_0016EE50(), func_00417FB0();
    extern void func_0012F440(), func_001E42A0(), func_003D6FF0(), func_00170D30(), func_003D7400();
    extern void func_003D7640(), func_0012DD90(), func_00170D70(), func_003ECD00(s32);
    {
        s32 r;
        do {
            r = func_003EC160(0x280, 0x1E0);
            asm { nop; nop; nop; nop }
        } while (r == 0);
    }
    func_0012F4C0();
    func_00170BF0();
    func_003D6B70();
    for (;;) {
        func_0012F460();
        func_0016ECC0();
        func_0012F3E0(D_004F4480);
        func_0012F3E0(D_004F4494);
        func_003D7630();
        func_0012F450();
        if (D_004C2870 == 1 && D_004D17C2[0] != 1) {
            func_0016EE50();
            func_00417FB0();
            func_0012F440();
            D_004C2870 = 0;
        }
        func_001E42A0();
        D_004C2848 = 0;
        D_004C284C = 0;
        func_003D6FF0();
        func_00170D30();
        func_003D7400();
        func_003D7640();
        func_0012DD90();
        func_00170D70();
        func_003ECD00(0);
    }
}

typedef struct { u8 pad0[4]; s8 b4; u8 pad1; s8 b6; } G14EB20;
extern G14EB20 *D_004C2840;
extern u8 D_004F7D37[], D_004D1577[];
static void func_0014E770(u8 *p) { p[5] = 0; }
void func_0014EB20(u8 *p)
{
    if (D_004C2840->b6 + *(s16 *)(p + 0x1E) == 0) {
        *(u32 *)(p + 0x78) = 0x3F800000;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x80) = 0;
    } else {
        *(u32 *)(p + 0x78) = 0x3F800000;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x80) = 0x3F800000;
    }
    func_0014E770(p);
    if (D_004C2840->b4 == 0) {
        if (*(s8 *)(D_004F7D37 + (D_004C2840->b6 + *(s16 *)(p + 0x1E)) * 24) != 0) {
            p[0x13C] = 1;
            p[0x13C] = (*(s8 **)(p + 0x18))[0x13C];
        } else {
            p[0x13C] = 0;
        }
    } else {
        if (*(s8 *)(D_004D1577 + (D_004C2840->b6 + *(s16 *)(p + 0x1E)) * 24) != 0) {
            p[0x13C] = 1;
            p[0x13C] = (*(s8 **)(p + 0x18))[0x13C];
        } else {
            p[0x13C] = 0;
        }
    }
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}

