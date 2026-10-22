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
} O6;
typedef struct { u8 pad[0x28]; f32 f28; } Z6;
typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x20]; Z6 *p40; } A6;

extern u32 D_004C2AC0;
extern u8 D_0061BEE0[];
extern u8 D_0061C720[];
extern u8 D_0061BE20[];
extern u8 D_0061BDE0[];

O6 *func_003E4B20(A6 *a, u8 *b) {
    extern s32 func_003DD030(s32);
    extern O6 *func_003DD160(s32, s32);
    extern void func_003DBA30(O6 *, s32, s32, s32, s32);
    extern void func_003DBB60(u8 *, s32, s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DE3A0(u8 *, u8 *);
    extern void func_003DBB20(u8 *, u8 *);
    s32 s3;
    O6 *s0;
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
    func_003DE160(mat, D_0061BEE0, D_0061C720);
    func_003DE3A0((u8 *)s0 + 0x30, mat);
    func_003DE160((u8 *)s0 + 0x70, mat, D_0061BE20);
    func_003DE160((u8 *)s0 + 0xB0, mat, D_0061BDE0);
    func_003DBB20((u8 *)s0 + 0xF0, b);
    return s0;
}
