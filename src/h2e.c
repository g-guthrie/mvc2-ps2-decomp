typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;

s32 func_001895E0(u8 *a, u8 *b, u8 *c) {
    extern s32 func_0018AA10(u8 *, u32, u16 *);
    extern s32 func_0018A380(u8 *, u8 *, u8 *, u32);
    u16 t;
    c[0] = 0;
    return func_0018AA10(a, *(u16 *)((u8 *)(c[2] * 2) + (u32)b + 8), &t) ? func_0018A380(a, b, c, t) : 0;
}
