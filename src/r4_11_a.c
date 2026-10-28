/* func_0015B730: MW 3.0.3 "-O3 -Op -fp off -sdatathreshold 8", warm after src/q6_ad.c (MWWARM) */
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;typedef float f32;
extern u8 *D_004D18B8[];
extern void (*D_004BF458[2])(u8 *, u8 *);
void func_0015B730(u8 *p)
{
    u8 *d = D_004D18B8[0];
    p[0x13C] = 0;
    if (*(s8 *)(*(u8 **)(p + 0x14) + 0x13C) == 0) {
        *(s16 *)(p + 0x1C) = (*(s16 *)(d + 0x140) != 0) ? 0 : -0xB4;
        *(u32 *)(p + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0) & 0xFFFF;
    } else {
        D_004BF458[p[4]](p, d);
    }
}
