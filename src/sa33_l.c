typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
s32 func_00167C70(u8 *p)
{
    extern s32 func_0016A320(u8 *);
    u32 t;
    s32 a;
    s32 r;
    s32 v;
    if (p[0x425] != 0 || (p[0x1E4] != 0x12 && p[0x1E4] != 0x13)) {
        t = p[0x451];
        p[0x451] = t - 1;
        return 1;
    }
    if (p[0x473] == 1) {
        p[0x471] = 1;
        p[0x45C] = 0x7D;
        p[0x4BF] = 0;
        p[0x4BE] = 0;
        *(s16 *)(p + 0x4C0) = 0;
    } else if (*(s8 *)(p + 0x4BB) == 1) {
        a = 0;
        if ((*(u32 *)(p + 0x428) & 0x30000000) != 0) {
            t = p[1];
            if (t == 0x1C) a = p[0x2B9];
            if (t == 0x1D) a = p[0x2B9];
        }
        if (a == 0) {
            *(s8 *)(p + 0x1F1) = -1;
            p[0x4BB] = 0;
            p[0x368] = 0;
            p[0x369] = 0;
            p[0x36A] = 0;
            p[0x36B] = 0;
            p[0x36C] = 0;
            p[0x36D] = 0;
            *(s16 *)(p + 0x36E) = 0;
        }
    }
    r = *(s32 *)(p + 0x460) - 1;
    *(s32 *)(p + 0x460) = r;
    if (r == 0) return 0;
    v = func_0016A320(p);
    if (v != 0) {
        if (p[0x20D] == 2 || (v & 2) != 0) *(s32 *)(p + 0x464) &= ~0x1000;
        if (p[0x20D] == 1 || (v & 4) != 0 || p[0x454] == 0x3C) *(s32 *)(p + 0x464) |= 0x1000;
    }
    *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x464);
    return 0;
}
