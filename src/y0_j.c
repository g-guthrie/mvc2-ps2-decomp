typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C2670;
extern f32 D_004F7FD0[];
extern f32 D_004F7FD4[];

void func_0016BF80(u8 a, f32 x, f32 y)
{
    extern u8 *func_003DA750();
    extern void func_0016C060();
    u8 *o;
    if ((o = func_003DA750(0, 7, 1)) != 0) {
        o[0x13C] = 0;
        o[0x20] = a;
        *(u32 *)(o + 0x10) = (u32)func_0016C060;
        *(u32 *)(o + 0xEC) = D_004C2670 + 0x912;
        *(f32 *)(o + 0xF0) = x;
        *(u32 *)(o + 0xF4) = 0x43F80000;
        *(f32 *)(o + 0xF0) += D_004F7FD0[0];
        *(f32 *)(o + 0xF4) += D_004F7FD4[0];
        *(u32 *)(o + 0xF8) = 0x3F8CCCCD;
        *(u32 *)(o + 0xFC) = 0x3E000000;
        *(u32 *)(o + 0x100) = 0x3E800000;
        *(u32 *)(o + 0x114) = 0;
        *(u32 *)(o + 0x118) = 0x3F800000;
        *(u32 *)(o + 0x11C) = 2;
        *(u32 *)(o + 0x120) = 5;
        *(f32 *)(o + 0x60) = y;
        return;
    }
}
