typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct { u128 q[4]; } M64;
typedef struct { f32 x, y, z, w; } V4M;

typedef struct {
    u8 pad0[0x10];
    u32 w10;
    u8 pad14[0xC];
    f32 f20, f24, f28, f2C;
    u8 pad30[0x80];
    V4M q[2];
    f32 fD0, fD4, fD8, fDC;
} O7;
typedef struct { u8 pad[0x28]; f32 f28; } Z7;
typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x20]; Z7 *p40; } A7;

extern u32 D_004C2AC0;
extern u32 D_004C2ABC;
extern f32 D_004C2AC8;
extern f32 D_004C2ACC;
extern u8 D_0061BEE0[];
extern u8 D_0061C720[];
extern u8 D_0061BE20[];
extern u8 D_0061BDE0[];
extern u8 D_0061BDA0[];
extern f32 D_0061B324[], D_0061B328[], D_0061B32C[];
extern f32 D_0061B388[], D_0061B38C[], D_0061B390[];
extern f32 D_0061B3EC[], D_0061B3F0[], D_0061B3F4[];
extern f32 D_0061B2F4[], D_0061B2F8[], D_0061B2FC[], D_0061B300[];
extern f32 D_0061B358[], D_0061B35C[], D_0061B360[], D_0061B364[];
extern f32 D_0061B3BC[], D_0061B3C0[], D_0061B3C4[], D_0061B3C8[];
extern f32 D_0061B314[], D_0061B318[], D_0061B31C[];
extern f32 D_0061B378[], D_0061B37C[], D_0061B380[];
extern f32 D_0061B3DC[], D_0061B3E0[], D_0061B3E4[];
extern f32 D_0061BF50[], D_0061BF54[], D_0061BF58[], D_0061BF5C[];

O7 *func_003E4050(A7 *a, u8 *b) {
    extern s32 func_003DD030(s32);
    extern O7 *func_003DD160(s32, s32);
    extern void func_003DBA30(O7 *, s32, s32, s32, s32);
    extern void func_003DBB60(u8 *, s32, s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DBB20(u8 *, u8 *);
    u8 mat[0x40];
    s32 s3;
    O7 *s0;
    s32 i;
    s3 = func_003DD030(a->w1C);
    s0 = func_003DD160(0xF0, 0x10);
    func_003DBA30(s0, 0xE, s3, 0, 0);
    func_003DBB60((u8 *)s0 + 0x10, 0xC, 0);
    s0->w10 = 0x13000000;
    s0->f20 = ((f32)((D_004C2AC0 >> 16) & 0xFF) / 255.0f) * a->p40->f28;
    s0->f24 = ((f32)((D_004C2AC0 >> 8) & 0xFF) / 255.0f) * a->p40->f28;
    s0->f28 = ((f32)(u8)D_004C2AC0 / 255.0f) * a->p40->f28;
    s0->f2C = 0.5f * (f32)((D_004C2AC0 >> 24) & 0xFF);
    func_003DE160(mat, D_0061BEE0, D_0061C720);
    func_003DE160((u8 *)s0 + 0x30, mat, D_0061BE20);
    func_003DE160((u8 *)s0 + 0x70, mat, D_0061BDE0);
    i = 0;
    do {
        s0->q[i].x = ((V4M *)D_0061BEE0)[i + 4].x;
        s0->q[i].y = ((V4M *)D_0061BEE0)[i + 4].y;
        s0->q[i].z = ((V4M *)D_0061BEE0)[i + 4].z;
        s0->q[i].w = ((V4M *)D_0061BEE0)[i + 4].w;
        i++;
    } while (i < 2);
    s0->fD0 = D_0061BF50[0];
    s0->fD4 = D_0061BF54[0];
    s0->fD8 = D_0061BF58[0];
    s0->fDC = D_0061BF5C[0];
    func_003DBB20((u8 *)s0 + 0xE0, b);
    return s0;
}
