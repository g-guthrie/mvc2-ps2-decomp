typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } Float3;
extern s32 D_004C2838;
extern s32 D_004BF440[2];
extern Float3 D_00444ED8;
extern Float3 D_00444EF0[];

void func_0015A0D0(const Float3 *pos, s32 idx)
{
    extern u8 *func_003DA750(void *, s32, s32);
    extern void func_0015A020(u8 *);
    u8 *p = func_003DA750(0, 8, 1);
    if (p) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_0015A020;
        *(s16 *)(p + 0xCC) = 0xD;
        *(s32 *)(p + 0x84) = D_004C2838;
        *(Float3 *)(p + 0x34) = *pos;
        *(s32 *)(p + 0x44) = D_004BF440[idx];
        *(Float3 *)(p + 0x50) = D_00444ED8;
        *(Float3 *)(p + 0x5C) = D_00444EF0[idx];
        *(s32 *)(p + 0xD0) = 0x800515;
    }
}

typedef struct {
    u8 p0[2]; s8 f2; s8 f3; s8 f4; s8 f5; s8 f6; s8 f7; s16 f8;
    u8 p1[0x88 - 0xA]; s8 f88; s8 f89; u8 p2[0x90 - 0x8A]; s8 f90; s8 f91; s8 f92;
    u8 p3[0x9E - 0x93]; s8 f9E;
} G2840;
extern G2840 *D_004C2840;
extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern u8 D_00583BC8[];

void func_0032C780(void)
{
    extern void func_0032D730(u8 *);
    extern void func_0032DF00(void);
    extern void func_001E40E0(void);
    extern void func_001E4150(void);
    G2840 *g;
    D_004C2840->f2++;
    D_004C2840->f3 = 0;
    D_004C2840->f4 = 0;
    D_004C2840->f5 = 0;
    D_004C2840->f6 = 0;
    D_004C2840->f7 = 0;
    D_004C2840->f8 = 0;
    if (((D_004C2840->f89 | D_004C2840->f88) & 1) != 0)
        func_0032D730(D_004F20B0);
    if (((D_004C2840->f89 | D_004C2840->f88) & 2) != 0)
        func_0032D730(D_004F2668);
    g = D_004C2840;
    g->f88 = g->f88 | g->f89;
    D_004C2840->f89 = 0;
    D_004C2840->f91 = 0;
    D_004C2840->f92 = 0;
    D_004C2840->f90 = 0;
    D_00583BC8[0] = 0;
    func_0032DF00();
    D_004C2840->f9E = 1;
    func_001E40E0();
    func_001E4150();
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2794;
extern G2794 *D_004C2794;

void func_0023FF50(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        break;
    case 1:
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            p[0x1B5] = 0x19;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 2:
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            p[0x1B5] = 0x1A;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    default:
        break;
    }
}

extern s32 D_004BFF98;
extern s32 D_004BFF9C;
extern s32 D_004BFFA0;

void func_00223210(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00223130(u8 *);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(s32 *)(p + 0x408) = (s32)&D_004BFF98;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(s32 *)(p + 0x408) = (s32)&D_004BFF9C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        func_001E3710(p, 0x16);
        *(s32 *)(p + 0x408) = (s32)&D_004BFFA0;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
    func_00223130(p);
}

extern Float3 D_004B38E0;

void func_0014F1D0(u8 *owner, s32 a, s32 flag)
{
    extern u8 *func_003DA750(void *, s32, s32);
    extern void func_0014F2D0(u8 *);
    extern void func_00150520(u8 *, f32, f32, f32);
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        f32 one;
        o[0x13C] = 1;
        *(void (**)(u8 *))(o + 0x10) = func_0014F2D0;
        *(s32 *)(o + 0xD0) = 0x431;
        *(s16 *)(o + 0x1E) = a;
        o[0x23] = flag;
        if (flag != 0)
            *(u32 *)(o + 0x34) = 0x40CDC28F;
        else
            *(u32 *)(o + 0x34) = 0x40E33333;
        *(u32 *)(o + 0x38) = 0x3EC28F5C;
        *(u32 *)(o + 0x3C) = 0x3D8F5C29;
        *(Float3 *)(o + 0x50) = D_004B38E0;
        one = 1.0f;
        func_00150520(o, 0.0f, one, one);
        *(u8 **)(o + 0xC8) = owner + 0x88;
        *(u8 **)(o + 0x18) = owner;
    }
}


void func_0034B890(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    *(s16 *)(p + 0x1C) = 0x60;
    *(u32 *)(p + 0x34) = 0x43200000;
    *(u32 *)(p + 0x38) = 0x434DB6DB;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0x40855555;
    *(u32 *)(p + 0x60) = 0xC02B6DB6;
    if (p[0x20] != 1) {
        *(u32 *)(p + 0x5C) = 0x41055555;
        *(u32 *)(p + 0x60) = 0xC0892492;
    }
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) == 0) {
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    p[0x1B5] = *(s8 *)(p + 0x20) + 0x3F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x16, (u8)(p[0x20] + 0xA));
}

extern s32 D_004C2834;
extern Float3 D_0043DF10[2][3];
extern u8 D_004F24D5[];

void func_00132210(u8 *owner, s32 idx)
{
    extern u8 *func_003DA750(void *, s32, s32);
    extern void func_00132FB0(u8 *);
    u8 *o;
    if ((o = func_003DA750(0, 0xE, 1)) != 0) {
        o[0x13C] = 0;
        *(void (**)(u8 *))(o + 0x10) = func_00132FB0;
        *(s16 *)(o + 0xCC) = 0x4F;
        *(s32 *)(o + 0x84) = D_004C2834;
        *(Float3 *)(o + 0x34) = D_0043DF10[idx & 1][idx >> 1];
        *(s32 *)(o + 0xD0) = 0x10811;
        *(u32 *)(o + 0x50) = 0x40A00000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        o[0x20] = idx;
        o[0x21] = D_004F24D5[idx * 0x5B8];
        *(u8 **)(o + 0x18) = D_004F20B0 + idx * 0x5B8;
        *(u8 **)(o + 0xC8) = owner + 0x88;
    }
}
