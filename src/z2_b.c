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
extern s32 D_004C0214[1], D_004C0218[1], D_004C021C[1];
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
    { u32 t = *(u8 *)(p + 0x1B5); p[0x1B5] = t; }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}

void func_0023A940(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = D_004C0214;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 10;
        *(s32 **)(p + 0x408) = D_004C0218;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 11;
        *(s32 **)(p + 0x408) = D_004C021C;
        p[0x1BB] = 2;
        break;
    }
    { u32 t = *(u8 *)(p + 0x1B5); p[0x1B5] = t; }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 10, p[0x168]);
}

typedef struct { u8 pad0[4]; s8 b4; u8 pad1; s8 b6; } G14EB20;
extern G14EB20 *D_004C2840;
extern u8 D_004F7D37[], D_004D1577[];
static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}
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

extern s32 D_004C1288[1], D_004C128C[1], D_004C1290[1];

void func_002F29B0(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = D_004C1288;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(s32 **)(p + 0x408) = D_004C128C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(s32 **)(p + 0x408) = D_004C1290;
        p[0x1BB] = 2;
        break;
    }
    { u32 t = *(u8 *)(p + 0x1B5); p[0x1B5] = t; }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}
