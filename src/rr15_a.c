typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00364130(u8 *p, u8 *q) {
    extern void func_00364E70();
    extern void func_00364270();
    extern s32 func_00182C90();
    extern void func_001843A0();
    extern void func_001845F0();
    u8 *o;
    s16 h;
    u32 t;
    s32 w;
    o = *(u8 **)(p + 0xD4);
    if (*(u8 **)(*(u8 **)(p + 0x1E0) + 0x1E0) == p && o[5] == 2 && (*(s8 *)(o + 0x1B3) == 0 || o[5] != 3)) {
        func_00364E70(p, q);
        func_00364270(p, q);
        if (func_00182C90(o) != 0) {
            *(s16 *)(p + 0x1C) -= 3;
        }
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h >= 0) {
            w = 1;
            goto st;
        }
        o[0x20A] = 0;
        o[0x203] = 8;
        if (*(s16 *)(o + 0x434) == 0) {
            o[0x20A] = 7;
        } else if (o[0x20D] != 2) {
            func_001843A0(o);
        } else {
            func_001845F0(o);
        }
    }
    t = p[4];
    p[4] = t + 1;
    p[0x13C] = 0;
    w = *(s32 *)(q + 0x2F8);
    if (w != 0) {
        *(s32 *)(q + 0x2F8) = w - 1;
    }
    return;
st:
    *(s32 *)(q + 0x2F8) = w;
}
