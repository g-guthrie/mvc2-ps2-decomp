typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x14]; s32 f14; s8 f18; u8 pad2[0x33]; s8 f4C; u8 pad3[0x3B]; s8 f88; } G40;

extern s8 D_004F7F50[];
extern u8 D_004F7F51[], D_004F7F52[], D_004F7F53[], D_004F7F54[], D_004F7F55[], D_004F7F56[], D_004F7F57[];
extern s16 D_004F7F58[], D_004F7F5A[];
extern u8 D_004F7F5C[], D_004F7F5D[], D_004F7F5E[], D_004F7F5F[];
extern f32 D_004F7F60[], D_004F7F64[];
extern u8 D_004F7F68[], D_004F7F69[], D_004F7F6A[];
extern s16 D_004F7F7A[];
extern u8 D_004F7F4C[];
extern G40 *D_004C2840;

void func_003D35C0(void)
{
    extern void func_003D3080(s32);
    s8 *s = D_004F7F50;
    G40 *g;
    D_004F7F50[0] = 0;
    D_004F7F51[0] = 0;
    D_004F7F52[0] = 0;
    D_004F7F53[0] = 0;
    D_004F7F5C[0] = 0;
    D_004F7F5D[0] = 0;
    D_004F7F5F[0] = 0;
    D_004F7F5E[0] = 0;
    D_004F7F68[0] = 0;
    D_004F7F69[0] = 0;
    D_004F7F6A[0] = 0;
    D_004F7F7A[0] = 0;
    func_003D3080(0);
    D_004F7F54[0] = 0;
    D_004F7F58[0] = 0x4650;
    D_004F7F5A[0] = 0xA;
    D_004F7F60[0] = 80.0f;
    D_004F7F64[0] = 88.0f;
    D_004F7F55[0] = 0;
    D_004F7F56[0] = 0;
    D_004F7F57[0] = 0;
    g = D_004C2840;
    if (g->f14 == 0x60) {
        switch (g->f4C) {
        case 0:
            s[1] = g->f88;
            break;
        case 1:
        case 5:
            s[1] = 3;
            break;
        case 2:
            s[0xD] = 2;
            s[1] = D_004C2840->f18;
            D_004F7F4C[0] = 0;
            break;
        case 7:
            s[1] = g->f18;
            break;
        case 3:
        case 4:
        case 6:
        case 8:
            s[1] = 0;
            break;
        }
        if (s[1] & 1) s[4] = 1;
        if (s[1] & 2) s[5] = 1;
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H2;
extern H2 *D_004C2794;
extern u32 data_u32_004BFFB0, D_004BFFB4, D_004BFFB8, D_004BFFC8, D_004BFFCC, D_004BFFD0;

void func_00223690(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_00223130(u8 *);
    extern void func_00355BE0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s8 t;
    u8 t0;
    switch (p[0x1FC]) {
    case 0:
        p[0x169] = 0xB;
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&data_u32_004BFFB0;
        else *(u32 *)(p + 0x408) = (u32)&D_004BFFC8;
        p[0x1BB] = 0;
        func_00223130(p);
        func_00355BE0(p, 2);
        break;
    case 1:
        p[0x169] = 0xB;
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004BFFB4;
        else *(u32 *)(p + 0x408) = (u32)&D_004BFFCC;
        p[0x1BB] = 1;
        func_00223130(p);
        break;
    case 2:
        p[0x169] = 0xB;
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0) {
            p[0x168] = 5;
            p[0x1B5] = 0x41;
        } else {
            func_00223130(p);
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004BFFB8;
        else *(u32 *)(p + 0x408) = (u32)&D_004BFFD0;
        p[0x1BB] = 2;
        break;
    }
    t0 = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t0;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    func_001757E0(p, 0xB, p[0x168]);
    t = p[0x1EA];
    if ((t & 0xF) != 0) p[0x1EA] = t - 1;
}

extern u32 D_004C0AB4, D_004C0A9C, D_004C0AB8, D_004C0AA0, D_004C0ABC, D_004C0AA4;

void func_00296060(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s8 t;
    u8 t0;
    p[0x169] = 0xC;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 3;
        p[0x1B5] = 0x16;
        p[0x169] = 0x14;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004C0A9C;
        else *(u32 *)(p + 0x408) = (u32)&D_004C0AB4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x169] = 0x14;
        p[0x168] = 4;
        p[0x1B5] = 0x17;
        if ((*(u16 *)(p + 0x20E) & 0x2000) != 0) {
            p[0x169] = 0xC;
            p[0x168] = 1;
            p[0x1B5] = 0x10;
        }
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004C0AA0;
        else *(u32 *)(p + 0x408) = (u32)&D_004C0AB8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 5;
        p[0x1B5] = 0x18;
        if ((*(u16 *)(p + 0x20E) & 0x2000) != 0) {
            p[0x168] = 2;
            p[0x1B5] = 0x11;
        } else {
            p[0x169] = 0x14;
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004C0AA4;
        else *(u32 *)(p + 0x408) = (u32)&D_004C0ABC;
        p[0x1BB] = 2;
        break;
    }
    t0 = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t0;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    func_001757E0(p, p[0x169], p[0x168]);
    t = p[0x1EA];
    if ((t & 0xF0) != 0) p[0x1EA] = t - 0x10;
}

extern u32 D_004C1368, D_004C1350, D_004C136C, D_004C1354, D_004C1370, D_004C1358;

void func_002F7AD0(u8 *p)
{
    extern void func_002FA150(void);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s8 t;
    u8 t0;
    if (p[0x2CE] != 0) {
        func_002FA150();
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        p[0x169] = 0xB;
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004C1350;
        else *(u32 *)(p + 0x408) = (u32)&D_004C1368;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x169] = 0xB;
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004C1354;
        else *(u32 *)(p + 0x408) = (u32)&D_004C136C;
        p[0x1BB] = 1;
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0) {
            p[0x169] = 0x14;
            p[0x168] = 6;
            p[0x1B5] = 0x12;
        }
        break;
    case 2:
        p[0x169] = 0xB;
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        p[0x169] = 0xB;
        if (p[0x210] == 0) *(u32 *)(p + 0x408) = (u32)&D_004C1358;
        else *(u32 *)(p + 0x408) = (u32)&D_004C1370;
        p[0x1BB] = 2;
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0) {
            p[0x169] = 0x14;
            p[0x168] = 7;
            p[0x1B5] = 0x13;
        }
        break;
    }
    t0 = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t0;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    func_001757E0(p, p[0x169], p[0x168]);
    t = p[0x1EA];
    if ((t & 0xF) != 0) p[0x1EA] = t - 1;
}

extern f32 D_0044FC4C[], D_0044FC54[];
extern u32 D_004BFC54, D_004BFC58, D_004BFC5C;

void func_001F7DC0(u8 *p)
{
    extern s32 func_00184110(f32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t0;
    switch (p[0x1FC]) {
    case 0:
        if (func_00184110(D_0044FC4C[0]) != 0) {
            p[0x168] = 3;
            p[0x1B5] = 0x45;
        } else {
            p[0x168] = 0;
            p[0x1B5] = 3;
        }
        if (*(u16 *)(p + 0x20E) == 0x400) {
            p[0x168] = 8;
            p[0x1FC] = 0x61;
            p[0x1B5] = 0x14;
        }
        func_001E3710(p, 0x14);
        *(u32 *)(p + 0x408) = (u32)&D_004BFC54;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 4;
        p[0x1B5] = 0x46;
        func_001E3710(p, 0x15);
        *(u32 *)(p + 0x408) = (u32)&D_004BFC58;
        p[0x1BB] = 1;
        break;
    case 2:
        if (func_00184110(D_0044FC54[0]) != 0) {
            p[0x168] = 5;
            p[0x1B5] = 0x47;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 5;
        }
        if (*(u16 *)(p + 0x20E) == 0x400) {
            p[0x168] = 6;
            p[0x1FC] = 0x60;
            p[0x1B5] = 0x13;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
        }
        if (*(u16 *)(p + 0x20E) == 0x800) {
            p[0x168] = 7;
            p[0x1B5] = 0x15;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
        }
        func_001E3710(p, 0x16);
        *(u32 *)(p + 0x408) = (u32)&D_004BFC5C;
        p[0x1BB] = 2;
        break;
    }
    t0 = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t0;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    func_001757E0(p, 8, p[0x168]);
}
