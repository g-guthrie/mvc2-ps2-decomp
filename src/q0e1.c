typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_003F7BE8(u8 *p, s32 *a, s32 *b, s32 *c) {
    s32 r = *(s32 *)(p + 0x3C);
    *a = *(s32 *)(p + 0x8C);
    *b = *(s32 *)(p + 0x40) - *(s32 *)(p + 0x8C);
    *c = *(s32 *)(p + 0x18) - *(s32 *)(p + 0x88);
    return r;
}

extern s32 D_0043B400;
extern s32 func_00110138();
s32 func_00110260(s32 a, s32 b, s32 c) {
    s32 r = func_00110138(a, b, c, 0x40);
    if (r == 0) D_0043B400 = 11;
    return r;
}
