typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0; s32 f4; u8 pad0[0xC]; u16 w14; u16 w16; } Hd;
typedef struct { s32 f0; s32 f4; Hd *f8; s32 fC; s32 f10; s32 f14; s32 f18; } Obj;
typedef struct { s32 f0, f4, f8, fC, f10, f14; s32 pad[0xC]; s32 f48; } Rec;
typedef struct { u8 pad[0x29]; s8 f29; u8 pad2[0x6E]; u32 f98; } G;
typedef struct { s8 b0; u8 pad[0x5B7]; } Pl;

extern G *D_004C2840;
extern s8 D_0057F580[];
extern s8 D_004BFAE8[8];
extern Pl D_004F25F0[];
extern s32 D_0057FB70[];
extern s8 D_004B6C50[];
extern s8 D_004B6CD0[];
extern s8 D_004B6C90[];

void func_001E60B0(s32 a0)
{
    extern void func_0011D8F8(void *, s32, s32);
    extern void func_003E9580(s32, s32, void *, s32);
    extern s32 func_00416A00(u32, s32);
    extern void func_004161D0(Obj *, s32);
    extern void func_00416490(Obj *);
    extern void func_00416670(Obj *);
    extern s32 func_00416730(Obj *);
    extern void func_004167D0(Rec *, s32, s32, Rec *, s32, s32, s32, s32);
    extern void func_003EA070(s32);
    Rec sA, sB;
    Obj o;
    s32 s0, s1, s2, s3;
    Pl *pl;
    s32 t;

    t = D_0057F580[a0 & 1];
    s0 = D_0057FB70[t];
    pl = &D_004F25F0[a0];
    s2 = D_004B6C50[pl->b0];
    s3 = D_004BFAE8[a0];
    func_0011D8F8(&sA, 0, 0x4C);
    func_0011D8F8(&sB, 0, 0x4C);
    func_003E9580(0, s0, &sA, 3);
    func_0011D8F8(&o, 0, 0x1C);
    func_004161D0(&o, func_00416A00(D_004C2840->f98, s2 >> 2));
    func_00416490(&o);
    func_00416670(&o);
    sB.f0 = 0;
    sB.f4 = o.f8->w14;
    sB.f8 = o.f8->w16;
    sB.f10 = o.f10;
    sB.fC = func_00416730(&o);
    sB.f14 = 1;
    sB.f48 = o.f14;
    func_004167D0(&sA, (s3 & 3) << 6, 0, &sB, (s2 & 3) << 6, 0, 0x40, 0x100);
    func_0011D8F8(&sB, 0, 0x4C);
    func_0011D8F8(&o, 0, 0x1C);
    if (D_004C2840->f29 != 0) {
        s1 = D_004B6CD0[pl->b0];
    } else {
        s1 = D_004B6C90[pl->b0];
    }
    func_004161D0(&o, func_00416A00(D_004C2840->f98, (s1 >> 3) + 0xF));
    func_00416490(&o);
    func_00416670(&o);
    sB.f0 = 0;
    sB.f4 = o.f8->w14;
    sB.f8 = o.f8->w16;
    sB.f10 = o.f10;
    sB.fC = func_00416730(&o);
    sB.f14 = 1;
    sB.f48 = o.f14;
    func_004167D0(&sA, 0, 0, &sB, (s1 & 7) << 5, 0, 0x20, 0x100);
    func_003EA070(s0);
}
