typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[7]; u8 b7; u8 pad8[0x34 - 8];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
} A1;

void func_001F3D70(A1 *p) {
    extern s32 func_001864a0();
    extern void func_00183d50();
    extern void func_001757E0();
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_001864a0() != 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        func_00183d50(p);
        func_001757E0(p, 15, 34);
    }
}
