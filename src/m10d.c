typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C, D_004F1F50, D_004F1FC8, D_004F1FCC, D_004F1FD0, D_004F1FD4, D_004F1FE8;
void func_00126A40(void) {
    f32 a = D_004F1F4C;
    f32 b = D_004F1F50;
    D_004F1FCC = 320.0f + a;
    D_004F1FC8 = a - 320.0f;
    D_004F1FE8 = 98.4f + b;
    D_004F1FD0 = 224.0f + D_004F1FE8;
    D_004F1FD4 = D_004F1FE8 - 224.0f;
}
extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_003C76C0(u8 *p, u8 *q);
void func_003C7C60(u8 *p, u8 *q) {
    s8 r = func_00175700(p);
    if (r < 0) {
        f32 v;
        p[5] = 2; func_001757E0(p, 0x14, 0xF); v = 3.33333325f; *(f32 *)(p + 0x60) = 60.0f; *(u32 *)(p + 0x6C) = 0; if (*(s16 *)(p + 0x140)) v = -v; *(f32 *)(p + 0x5C) = v;
        func_003C76C0(p, q);
    }
}
