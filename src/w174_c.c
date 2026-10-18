typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F7FD0;
extern f32 D_004F7FD4;
extern void func_0016C3B0(void);

u8 *func_0016C280(s32 a, u8 b, f32 x, f32 y, f32 z, f32 w) {
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *o;
    if ((o = func_003DA750(0, 7, 1)) == 0) return 0;
    o[0x13C] = 0;
    o[0x21] = b;
    *(void **)(o + 0x10) = (void *)func_0016C3B0;
    *(s32 *)(o + 0xEC) = a;
    *(f32 *)(o + 0xF0) = x;
    *(f32 *)(o + 0xF4) = y;
    *(f32 *)(o + 0xF0) += D_004F7FD0;
    *(f32 *)(o + 0xF4) += D_004F7FD4;
    *(u32 *)(o + 0xF8) = 0x3F8CCCCD;
    *(f32 *)(o + 0xFC) = z;
    *(f32 *)(o + 0x100) = w;
    *(s32 *)(o + 0x114) = 0;
    *(s32 *)(o + 0x11C) = 2;
    *(s32 *)(o + 0x120) = 0x1005;
    return o;
}
