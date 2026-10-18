typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001CFB90();

void func_001CFA60(u8 *p) {
    extern u8 *func_003DA750();
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001CFB90;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x2701;
        o[0x20] = 0;
    }
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001CFB90;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x2701;
        o[0x20] = 1;
    }
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001CFB90;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x2701;
        o[0x20] = 2;
    }
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001CFB90;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x2701;
        o[0x20] = 3;
    }
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001CFB90;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x2701;
        o[0x20] = 4;
    }
}
