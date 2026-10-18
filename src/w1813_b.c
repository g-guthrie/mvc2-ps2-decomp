typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern s8 D_004D193D;

void func_001802A0(void)
{
    extern void func_0011D8F8(u8 *, s32, s32);
    u8 i;
    s32 k;
    u8 *o;
    s8 *g;
    k = 0;
    for (i = 0; i < 3; i++) {
        o = D_004F20B0 + (k + 1) * 0x5B8;
        func_0011D8F8(o, 0, 0x4D0);
        o[2] = 1;
        o[0x1B8] = k + 1;
        k += 2;
        o[0x425] = i;
        o[0x426] = i;
    }
    g = (s8 *)D_004F2668;
    D_004D193D = g[0x543];
    if (g[0x539] != 0) D_004D193D = 0;
}
