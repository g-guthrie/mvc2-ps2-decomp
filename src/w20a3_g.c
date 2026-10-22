typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c, d; } V4;
typedef struct {
    u8 pad0[0x10];
    u32 w10;
    u8 pad14[0xC];
    f32 f20, f24, f28, f2C;
    u8 pad30[0x80];
    V4 v[2];
    f32 fD0, fD4, fD8, fDC, fE0, fE4;
    u32 wE8, wEC;
} O5;
typedef struct { u8 pad[0x28]; f32 f28; } Z5;
typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x20]; Z5 *p40; } A5;

extern u32 D_004C2AC0;
extern f32 D_004C2AC8;
extern f32 D_004C2ACC;
extern V4 D_0061BEE0[];
extern u8 D_0061C720[];
extern u8 D_0061BE20[];
extern u8 D_0061BDE0[];
extern f32 D_0061BF50[];
extern f32 D_0061BF54[];
extern f32 D_0061BF58[];
extern f32 D_0061BF5C[];

O5 *func_003E4850(A5 *a, u8 *b) {
    extern s32 func_003DD030(s32);
    extern O5 *func_003DD160(s32, s32);
    extern void func_003DBA30(O5 *, s32, s32, s32, s32);
    extern void func_003DBB60(u8 *, s32, s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DBB20(u8 *, u8 *);
    s32 s3;
    O5 *s0;
    s32 i;
    u8 mat[0x40];
    s3 = func_003DD030(a->w1C);
    s0 = func_003DD160(0x100, 0x10);
    func_003DBA30(s0, 0xF, s3, 0, 0);
    func_003DBB60((u8 *)s0 + 0x10, 0xD, 0);
    s0->w10 = 0x13000000;
    s0->f20 = ((f32)((D_004C2AC0 >> 16) & 0xFF) / 255.0f) * a->p40->f28;
    s0->f24 = ((f32)((D_004C2AC0 >> 8) & 0xFF) / 255.0f) * a->p40->f28;
    s0->f28 = ((f32)(u8)D_004C2AC0 / 255.0f) * a->p40->f28;
    s0->f2C = 0.5f * (f32)((D_004C2AC0 >> 24) & 0xFF);
    func_003DE160(mat, (u8 *)D_0061BEE0, D_0061C720);
    func_003DE160((u8 *)s0 + 0x30, mat, D_0061BE20);
    func_003DE160((u8 *)s0 + 0x70, mat, D_0061BDE0);
    i = 0;
    do {
        s0->v[i].a = D_0061BEE0[4 + i].a;
        s0->v[i].b = D_0061BEE0[4 + i].b;
        s0->v[i].c = D_0061BEE0[4 + i].c;
        s0->v[i].d = D_0061BEE0[4 + i].d;
        i++;
    } while (i < 2);
    s0->fD0 = D_0061BF50[0];
    s0->fD4 = D_0061BF54[0];
    s0->fD8 = D_0061BF58[0];
    s0->fDC = D_0061BF5C[0];
    s0->fE0 = D_004C2AC8;
    s0->fE4 = 1.0f / (D_004C2AC8 - D_004C2ACC);
    s0->wE8 = 0;
    s0->wEC = 0;
    func_003DBB20((u8 *)s0 + 0xF0, b);
    return s0;
}
