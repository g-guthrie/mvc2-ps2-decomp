typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x14]; u16 w14; u16 w16; } Hd;
typedef struct { s32 f0; s32 f4; Hd *f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; } Obj;
typedef struct { s32 f0, f4, f8, fC, f10, f14; s32 pad[0xC]; s32 f48; s32 f4C; } Rec;
typedef struct { s32 a, b; } Ent;
typedef struct { u8 pad[0x98]; u32 f98; } G;

extern G *D_004C2840;
extern Ent D_004B6E10[];
extern Ent D_004B6E14[];

void func_001E6670(u32 a0, u32 a1, u32 a2, u32 a3, u8 *t0) {
    extern void func_004161D0(Obj *, u32);
    extern s32 func_00416730(Obj *);
    extern void func_004167D0(Rec *, s32, s32, Rec *, s32, s32, s32, s32);
    extern void func_003DCDC0(s32, s32, s32);
    Rec sB, sA;
    Obj oA, oB;
    s32 s3, i;
    u32 v, w;
    s32 d;
    s3 = 0;
    func_004161D0(&oB, a2);
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
    v = a0 << 20;
    i = 0;
    do {
        if ((v & 0xF0000000) != 0 || s3 != 0) {
            s3 = 1;
            d = (v >> 28) & 0xF;
        } else {
            d = 10;
        }
        v <<= 4;
        func_004167D0(&sB, (i % a3) << 4, (t0[0] + i / a3) << 4, &sA, D_004B6E10[d].a, D_004B6E10[d].b, 16, 16);
        i++;
    } while (i < 3);
    w = a1;
    i = 3;
    do {
        if ((w & 0xF0000000) != 0 || s3 != 0) {
            s3 = 1;
            d = (w >> 28) & 0xF;
        } else {
            d = 10;
        }
        w <<= 4;
        func_004167D0(&sB, (i % a3) << 4, (t0[0] + i / a3) << 4, &sA, D_004B6E10[d].a, D_004B6E10[d].b, 16, 16);
        i++;
    } while (i < 10);
    d = (w >> 28) & 0xF;
    func_004167D0(&sB, (i % a3) << 4, (t0[0] + i / a3) << 4, &sA, D_004B6E10[d].a, D_004B6E14[d].a, 16, 16);
    func_003DCDC0(oB.f14, oA.f14, 0x400);
}
