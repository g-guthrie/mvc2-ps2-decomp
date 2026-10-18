typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_0036CF80(u8 *p) {
    extern void func_0036C050();
    extern void func_0036C0B0(u8 *, s32, s32);
    extern void func_001757E0();
    f32 v;
    p[0x13C] = 1;
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(p + 0x140) != 0) v = D_004F1FC8 - 400.0f;
    else v = 400.0f + D_004F1FCC;
    *(f32 *)(p + 0x34) = v;
    *(f32 *)(p + 0x38) += 240.0f;
    *(s8 *)(p + 0x24) = 14;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x50) = 0x3FB33333;
    *(u32 *)(p + 0x54) = 0x3FB33333;
    func_0036C050(p, 0x11);
    func_0036C0B0(p, 0x13, 1);
    func_0036C0B0(p, 0x13, 0);
    func_001757E0(p, 0x17, 2);
}
