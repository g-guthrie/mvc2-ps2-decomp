typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x10];
    u32 w10;
    u8 pad14[0xC];
    f32 f20, f24, f28, f2C;
    f32 f30, f34, f38, f3C;
    u8 pad40[0x80];
    f32 fC0, fC4;
    u32 wC8, wCC;
} O6;
typedef struct { u8 pad[0x28]; f32 f28; } Z6;
typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x20]; Z6 *p40; } A6;

extern u32 D_004C2AC0;
extern u32 D_004C2ABC;
extern f32 D_004C2AC8;
extern f32 D_004C2ACC;
extern u8 D_0061BEE0[];
extern u8 D_0061C720[];
extern u8 D_0061BE20[];
extern u8 D_0061BDE0[];

O6 *func_003E5FF0(A6 *a, u8 *b) {
    extern s32 func_003DD030(s32);
    extern O6 *func_003DD160(s32, s32);
    extern void func_003DBA30(O6 *, s32, s32, s32, s32);
    extern void func_003DBB60(u8 *, s32, s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DBB20(u8 *, u8 *);
    s32 s3;
    O6 *s0;
    u8 mat[0x40];
    s3 = func_003DD030(a->w1C);
    s0 = func_003DD160(0xE0, 0x10);
    func_003DBA30(s0, 0xD, s3, 0, 0);
    func_003DBB60((u8 *)s0 + 0x10, 0xB, 0);
    s0->w10 = 0x13000000;
    s0->f20 = ((f32)((D_004C2AC0 >> 16) & 0xFF) / 255.0f) * a->p40->f28;
    s0->f24 = ((f32)((D_004C2AC0 >> 8) & 0xFF) / 255.0f) * a->p40->f28;
    s0->f28 = ((f32)(u8)D_004C2AC0 / 255.0f) * a->p40->f28;
    s0->f2C = 0.5f * (f32)((D_004C2AC0 >> 24) & 0xFF);
    s0->f30 = (f32)((D_004C2ABC >> 16) & 0xFF) / 255.0f;
    s0->f34 = (f32)((D_004C2ABC >> 8) & 0xFF) / 255.0f;
    s0->f38 = (f32)(u8)D_004C2ABC / 255.0f;
    s0->f3C = (f32)((D_004C2ABC >> 24) & 0xFF) / 255.0f;
    func_003DE160(mat, D_0061BEE0, D_0061C720);
    func_003DE160((u8 *)s0 + 0x40, mat, D_0061BE20);
    func_003DE160((u8 *)s0 + 0x80, mat, D_0061BDE0);
    s0->fC0 = D_004C2AC8;
    s0->fC4 = 1.0f / (D_004C2AC8 - D_004C2ACC);
    s0->wC8 = 0;
    s0->wCC = 0;
    func_003DBB20((u8 *)s0 + 0xD0, b);
    return s0;
}
