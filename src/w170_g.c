typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

u8 *func_003B5A40(u32 a, u8 b) {
    extern u8 *func_003DA750();
    extern void func_003B5B30();
    u8 *s0;
    u8 *o;
    if ((s0 = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(s0 + 0x10) = (void *)func_003B5B30;
        *(u32 *)(s0 + 0x18) = a;
        *(u8 **)(s0 + 0x14) = s0;
        s0[0x20] = b;
        s0[0x21] = 0;
        *(s16 *)(s0 + 0x26) = 0x3401;
    }
    if ((o = func_003DA750(s0, 1, 2)) != 0) {
        *(void **)(o + 0x10) = (void *)func_003B5B30;
        *(u32 *)(o + 0x18) = a;
        *(u8 **)(o + 0x14) = s0;
        o[0x20] = b;
        o[0x21] = 1;
        *(s16 *)(o + 0x26) = 0x3401;
    }
    if ((o = func_003DA750(s0, 1, 2)) != 0) {
        *(void **)(o + 0x10) = (void *)func_003B5B30;
        *(u32 *)(o + 0x18) = a;
        *(u8 **)(o + 0x14) = s0;
        o[0x20] = b;
        o[0x21] = 2;
        *(s16 *)(o + 0x26) = 0x3401;
    }
    return s0;
}
