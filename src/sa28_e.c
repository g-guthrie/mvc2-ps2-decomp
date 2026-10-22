typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00448800[];

u8 func_00188110(u8 *p) {
    extern s32 func_0018AA50(u8 *, s32, u8 *, s32);
    extern s32 func_0018A580(u8 *);
    extern s32 func_00186CE0(u8 *, s32);
    u8 tmp[8];
    u32 t;
    if ((*(u8 **)(p + 0x220))[0x249] != 0) {
        return 0;
    }
    if (p[0x20D] != 2) {
        return 0;
    }
    if (p[5] != 0) {
        return 0;
    }
    if (*(s8 *)(p + 0x1E9) != 0) {
        return 0;
    }
    t = p[0x1E4];
    if (t == 0x1A) {
        return 0;
    }
    if (t == 0x13) {
        return 0;
    }
    if (t == 0x1B) {
        return 0;
    }
    if (p[0x215] == 0) {
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430) + 2.142857074737549f * (f32)D_00448800[p[1]] / 256.0f) {
            return 0;
        }
    }
    if (func_0018AA50(p, 0x300, tmp + 6, 0) == 0) {
        return 0;
    }
    if ((p[0x15A] & 0xE0) != 0 && p[0x215] != 0) {
        return 0;
    }
    if (func_0018A580(p) == 0) {
        return 0;
    }
    p[0x22] = (*(u16 *)(p + 0x35E) & 0x3C00) >> 10;
    if (p[0x215] == 0) {
        t = *(s8 *)(p + 0x1E9);
        p[0x1E9] = t + 1;
    }
    return func_00186CE0(p, 0x1A);
}
