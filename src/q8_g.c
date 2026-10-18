typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004C27A4;

s32 func_003B8080(u8 *p) {
    extern u8 *func_003DA750();
    extern void func_003B81F0();
    u8 *o;
    if (D_004C27A4 <= 2) {
        return 0;
    }
    o = func_003DA750(0, 1, 1);
    *(void **)(o + 0x10) = func_003B81F0;
    *(u8 **)(o + 0x18) = p;
    *(u8 **)(o + 0x14) = p;
    o[1] = p[1];
    *(s16 *)(o + 0x26) = 0x3502;
    o[0x20] = 0;
    o[0x21] = 0;
    o = func_003DA750(0, 1, 1);
    *(void **)(o + 0x10) = func_003B81F0;
    *(u8 **)(o + 0x18) = p;
    *(u8 **)(o + 0x14) = p;
    o[1] = p[1];
    *(s16 *)(o + 0x26) = 0x3502;
    o[0x20] = 1;
    o[0x21] = 0;
    o = func_003DA750(0, 1, 1);
    *(void **)(o + 0x10) = func_003B81F0;
    *(u8 **)(o + 0x18) = p;
    *(u8 **)(o + 0x14) = p;
    o[1] = p[1];
    *(s16 *)(o + 0x26) = 0x3502;
    o[0x20] = 1;
    o[0x21] = 1;
    return (s32)o;
}
