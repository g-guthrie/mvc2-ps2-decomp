typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_003F6908(s32, s32, s16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);

s32 func_003F6A18(u8 *p, s32 a, s32 b)
{
    s16 v;
    u8 *q1;
    u8 *q2;
    u8 *q3;
    u8 *q4;
    q1 = p + 0xE;
    q2 = p + 0xF;
    q3 = p + 0x10;
    q4 = p + 0xD;
    *(s16 *)(p + 2) = 1;
    if (func_003F6908(a, b, &v, p + 0xC, q4, q2, q1, p + 0x14, p + 0x18, q3) < 0) return 0;
    *(s32 *)(p + 0x34) = 0;
    *(s32 *)(p + 0x30) = 0;
    *(s32 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x28) = 0;
    *(s32 *)(p + 0x20) = 0;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x26) = 0;
    *(s16 *)(p + 0x24) = 0;
    *(s32 *)(p + 0x50) = *(s8 *)q1;
    *(s32 *)(p + 0x54) = *(s8 *)q2;
    *(s32 *)(p + 0x5C) = *(s32 *)(p + 0x3C);
    *(s32 *)(p + 0x58) = *(s32 *)q3;
    *(s32 *)(p + 0x60) = *(s32 *)(p + 0x40);
    *(s32 *)(p + 0x64) = *(s32 *)(p + 0x44);
    *(s16 *)(p + 0x98) = 3;
    *(s32 *)(p + 0x8C) = 0;
    *(s32 *)(p + 0x88) = 0;
    if (*(s8 *)q4 == 8) *(s16 *)(p + 0x9A) = 1;
    else *(s16 *)(p + 0x9A) = 0;
    return v;
}
