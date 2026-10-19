typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0018A580(u8 *);

s32 func_001891F0(u8 *p, s32 a1)
{
    if (*(s8 *)(p + 0x539)) {
        if (p[0x471] == 0)
            return 0;
        if (*(s8 *)(p + 0x45C) != (u8)a1)
            return 0;
    } else if ((*(u16 *)(p + 0x35C) & 2) == 0)
        return 0;
    if (p[0x20D] == 0 || p[0x20D] == 1) {
        if (!func_0018A580(p))
            return 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        if (p[1] != 0x3A)
            p[0x20D] = 0;
        return 1;
    }
    if (p[1] != 0x23)
        return 0;
    if (p[0x20D] != 2)
        return 0;
    if (*(f32 *)(p + 0x60) < 0.0f)
        return 0;
    if (func_0018A580(p))
        return 1;
    return 0;
}
