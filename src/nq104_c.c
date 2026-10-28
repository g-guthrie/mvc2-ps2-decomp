typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0, f4, f8, fC, f10, f14; u8 pad[0x38]; } S50;
typedef struct { u8 pad[0x10]; s32 f10, f14; u8 pad2[4]; } Q1C;

extern s8 D_0057ED70[];
extern u32 D_0057FB70[];
extern s32 D_004B6DD0[];

s32 func_001E5F40(s32 i, s32 arg) {
    extern void func_003DCD40(void *, s32, s32);
    extern s32 func_004161D0(Q1C *, s32);
    extern void func_003E9580(s32, s32, void *, s32);
    extern void func_003E95E0(s32, s32, S50 *, s32);
    extern void func_00416570(Q1C *);
    extern void func_00416640(Q1C *);
    extern void func_003DCDC0(s32, u32, s32);
    extern void func_003EA070(s32);
    extern void func_003EA0D0(s32);
    extern void func_003EA660(s32, u32 *);
    S50 a;
    S50 b;
    S50 c;
    Q1C q;
    u32 v;
    v = D_0057FB70[D_0057ED70[i]];
    func_003DCD40(&a, 0, 0x48);
    func_003DCD40(&b, 0, 0x48);
    if (func_004161D0(&q, arg) == 0) return 0;
    func_003E9580(0, v & 0xFFFF, &a, 3);
    func_00416570(&q);
    func_00416640(&q);
    func_003DCDC0(a.f10, q.f10, (D_004B6DD0[a.f14] * (a.f4 * a.f8)) >> 3);
    func_003EA070(v & 0xFFFF);
    func_003E95E0(0, (v & 0xFFFF0000) >> 16, &c, 3);
    func_003DCDC0(c.f10, q.f14, (D_004B6DD0[c.f14] * (c.f4 * c.f8)) >> 3);
    func_003EA0D0((v & 0xFFFF0000) >> 16);
    func_003EA660(1, &v);
    return 1;
}
