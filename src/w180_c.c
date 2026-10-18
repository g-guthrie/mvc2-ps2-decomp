typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001864A0(u8 *p) {
    f32 lim = 0.0f;
    f32 g;
    if (p[0x1E4] == 0x14 && *(s8 *)(p + 0x1B2) == 0 && (*(u8 **)(p + 0x220))[0x225] == 0) {
        lim = -42.857139587402344f;
    }
    g = *(f32 *)(p + 0x430);
    lim += g;
    if (!(*(f32 *)(p + 0x38) <= lim)) {
        p[0x20D] = 2;
        return 0;
    }
    *(f32 *)(p + 0x38) = g;
    if (p[0x215] != 0) {
        return 0;
    }
    p[0x210] = 0;
    p[0x224] = 0;
    p[0x20D] = 0;
    return 1;
}
