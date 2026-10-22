typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0, f4, f8, fC, f10, f14; s32 pad[0xC]; s32 f48; } Rec;
typedef struct { s32 f0, f4, f8, fC, f10, f14; } Obj;
typedef struct { u8 pad[0x98]; u32 f98; } G;
typedef struct { s8 f0; u8 pad[0x5B7]; } Ch;

extern G *D_004C2840;
extern s8 D_0057F58C[];
extern s32 D_0057FB70[];
extern Ch D_004F25F0[];
extern s32 D_004B6DF0[];

void func_001E6490(u32 a)
{
    extern void func_0011D8F8();
    extern s32 func_003E9580();
    extern s32 func_003E95E0();
    extern s32 func_00416A00();
    extern void func_004161D0();
    extern void func_003DCDC0(s32, s32, s32);
    extern void func_003EA070();
    extern void func_003EA0D0();
    extern void func_003EA660();
    Rec r1, r2, r3;
    Obj o;
    u32 v;
    s32 t;
    s32 s0;
    v = D_0057FB70[D_0057F58C[a & 1]];
    s0 = D_004F25F0[a].f0;
    if (s0 >= 0x1B) s0 -= 3;
    func_0011D8F8(&r1, 0, 0x4C);
    func_0011D8F8(&r2, 0, 0x4C);
    func_003E9580(0, v & 0xFFFF, (Rec *)((s32)&r1), 3);
    func_004161D0(&o, func_00416A00(D_004C2840->f98, s0 + 0x17));
    func_003DCDC0(r1.f10, t = o.f10, (D_004B6DF0[r1.f14] * (r1.f4 * r1.f8)) >> 3);
    func_003EA070(v & 0xFFFF);
    func_003E95E0(0, (v & 0xFFFF0000) >> 16, &r3, 3);
    func_003DCDC0(r3.f10, t = o.f14, (D_004B6DF0[r3.f14] * (r3.f4 * r3.f8)) >> 3);
    func_003EA0D0((v & 0xFFFF0000) >> 16);
    func_003EA660(1, &v);
}
