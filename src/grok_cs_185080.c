typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00169CE0(u8 *, s32, s32);

s32 func_00185080(u8 *p)
{
    s16 t = *(s16 *)(p + 0x28C) - 1;
    *(s16 *)(p + 0x28C) = t;
    if (t <= 0) {
        *(s16 *)(p + 0x28C) = 0;
        p[7] = 2;
    }
    if (p[0x20B] & 0x40)
        return 0;
    if (*(s8 *)(p + 0x539)) {
        if (func_00169CE0(p, 0x1E, 2) != 0) {
            p[7] = 4;
            *(s16 *)(p + 0x28C) = 0xA;
            return 0;
        }
        *(s16 *)(p + 0x28C) = 0;
        p[7] = 2;
    }
    if (*(u16 *)(p + 0x35E) & 0xC00) {
        if (*(u16 *)(p + 0x362) & 0x120) {
            p[7] = 4;
            *(s16 *)(p + 0x28C) = 10;
        }
    }
    return 0;
}
