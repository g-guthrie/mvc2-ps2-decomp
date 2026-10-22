typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0; s32 f4; u8 pad0[0xC]; u16 w14; u16 w16; } Hd;
typedef struct { s32 f0; s32 f4; Hd *f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; } Obj;
typedef struct { s32 f0, f4, f8, fC, f10, f14; s32 pad[0xC]; s32 f48; s32 f4C; } Rec;
typedef struct { u8 pad[0x98]; u32 f98; u8 pad2[0x15]; s8 fB1; } G;
typedef struct { s8 b0; u8 b1[6]; s8 b7; u8 b8[8]; s32 f10; s32 f14; } Row;

extern G *D_004C2840;
extern u8 D_004B7060[];
extern u32 D_004B6D10[];
extern u8 *D_0044F1FC[];
extern Row D_004D1570[];
extern Row D_004D1370[];
extern Row D_004F7D30[];
extern u8 D_004B6DC0[];

void func_001E6D80(u32 a0, s32 a1) {
    extern void func_00416290(Obj *, u32, s32, s32, s32);
    extern void func_004161D0(Obj *, u32);
    extern s32 func_00416730(Obj *);
    extern void func_004167D0(Rec *, s32, s32, Rec *, s32, s32, s32, s32);
    extern void func_003DCDC0(s32, s32, s32);
    extern u32 func_001E6920(u8, s32);
    extern void func_001E6670(s32, s32, u32, s32, u8 *);
    Rec sB, sA;
    Obj oA, oB, oC;
    s32 j;
    s32 n;
    s32 z;
    Row *r;
    s32 y2;
    s32 w;
    u32 v;
    u8 *tbl;
    u32 base;
    s32 y;

    base = D_004C2840->f98 + 0x20000;
    func_00416290(&oB, base, 0x100, 0x80, 8);
    func_004161D0(&oB, base);
    func_004161D0(&oA, D_004C2840->f98);
    sA.f0 = 0;
    sA.f4 = oA.f8->w14;
    sA.f8 = oA.f8->w16;
    sA.f10 = oA.f10;
    sA.fC = func_00416730(&oA);
    sA.f14 = 1;
    sA.f48 = oA.f14;
    sB.f0 = 0;
    sB.f4 = oB.f8->w14;
    sB.f8 = oB.f8->w16;
    sB.f10 = oB.f10;
    sB.fC = func_00416730(&oB);
    sB.f14 = 1;
    sB.f48 = oB.f14;
    func_003DCDC0(oB.f14, oA.f14, oA.f8->f4);
    if ((s32)a0 < 0) {
        a0 = func_001E6920(10, 1);
        j = 0;
        z = 0;
        do {
            y2 = a1 << 4;
            func_004167D0(&sB, z, y2, &sA, a0 & 0xFF, a0 >> 8, 16, 16);
            j++;
            z += 16;
        } while (j < 16);
        func_00416290(&oB, base + 0x10000, 0x100, 0x80, 8);
        func_004161D0(&oB, base + 0x10000);
        func_004161D0(&oA, D_004C2840->f98);
        sA.f0 = 0;
        sA.f4 = oA.f8->w14;
        sA.f8 = oA.f8->w16;
        sA.f10 = oA.f10;
        sA.fC = func_00416730(&oA);
        sA.f14 = 1;
        sA.f48 = oA.f14;
        sB.f0 = 0;
        sB.f4 = oB.f8->w14;
        sB.f8 = oB.f8->w16;
        sB.f10 = oB.f10;
        sB.fC = func_00416730(&oB);
        sB.f14 = 1;
        sB.f48 = oB.f14;
        a0 = func_001E6920(10, 1);
        j = 0;
        do {
            func_004167D0(&sB, j << 4, y2, &sA, a0 & 0xFF, a0 >> 8, 16, 16);
            j++;
        } while (j < 16);
        func_003DCDC0(oB.f14, oA.f14, oA.f8->f4);
        return;
    }
    switch (D_004C2840->fB1) {
    case 0:
        r = D_004D1570 + a0;
        break;
    case 1:
        r = D_004D1370 + a0;
        break;
    case 2:
        r = D_004F7D30 + a0;
        break;
    }
    tbl = D_0044F1FC[r->b0];
    j = 0;
    w = 0;
    do {
        v = func_001E6920(tbl[j], 0);
        y = a1 << 4;
        func_004167D0(&sB, w, y, &sA, v & 0xFF, v >> 8, 16, 16);
        j++;
        w += 16;
    } while (j < 4);
    for (z = j << 4; j < 7; j++, z += 16) {
        v = D_004B6D10[r->b8[j]];
        func_004167D0(&sB, z, y, &sA, v & 0xFF, v >> 8, 16, 16);
    }
    if (r->b7 != 0) v = func_001E6920(0x1B, 1);
    else v = func_001E6920(10, 1);
    func_004167D0(&sB, j << 4, y, &sA, v & 0xFF, v >> 8, 16, 16);
    n = r->b8[0] / 10;
    if (n == 0) n = 10;
    v = func_001E6920(n, 1);
    func_004167D0(&sB, (j + 1) << 4, y, &sA, v & 0xFF, v >> 8, 16, 16);
    v = func_001E6920(r->b8[0] % 10, 1);
    func_004167D0(&sB, (j + 2) << 4, y, &sA, v & 0xFF, v >> 8, 16, 16);
    j += 3;
    for (w = j << 4; j < 13; j++, w += 16) {
        v = func_001E6920(D_004B7060[j - 10], 2);
        func_004167D0(&sB, w, y, &sA, v & 0xFF, v >> 8, 16, 16);
    }
    if (r->b8[0] > 1) {
        v = func_001E6920(0x53, 2);
        func_004167D0(&sB, j << 4, y, &sA, v & 0xFF, v >> 8, 16, 16);
    } else {
        v = func_001E6920(10, 1);
        func_004167D0(&sB, j << 4, y, &sA, v & 0xFF, v >> 8, 16, 16);
    }
    base = D_004C2840->f98 + 0x20000;
    if (D_004C2840->fB1 != 1) {
        func_00416290(&oC, base + 0x10000, 0x100, 0x80, 8);
        func_001E6670(r->f14, r->f10, base + 0x10000, 0x10, D_004B6DC0 + a1);
    }
}
