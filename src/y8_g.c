typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern f32 D_004F1FD0;
extern f32 D_004643BC[];
extern void (*D_00455458[])(u8 *);
extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);

typedef struct { f32 x, y; } V2_3D190;
void func_0033D190(u8 *p, u8 *q, u8 *r) {
    extern void func_0041BAD0();
    extern s32 func_0041BBB0();
    extern void func_0041BB30();
    f32 v[12];
    func_0041BAD0(q);
    if (func_0041BBB0(p)) do {
        (*(void (**)())(p + 0x18))(p, *(u16 *)(p + 0x10), v);
        v[0] -= 0.20000000298023224f * v[1] * ((f32)*(s16 *)(r + 0x1C) / 400.0f);
        (*(void (**)())(q + 0x1C))(q, *(u16 *)(q + 0x10), v);
    } while (func_0041BBB0(p));
    *(s16 *)(p + 0x12) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s16 *)(q + 0x12) = 0;
    *(s16 *)(q + 0x10) = 0;
    func_0041BB30(q);
}
