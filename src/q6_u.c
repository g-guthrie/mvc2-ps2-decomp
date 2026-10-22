typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* The only retail caller (0030E544) explicitly supplies zero in A1.
 * That reserved word is unused by this complete body. */
void func_001DC6D0(u8 *a, u32 reserved_word) {
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_001DC7F0(void);
    u8 *o;
    u8 *r;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        o[0] = 1;
        *(void **)(o + 0x10) = (void *)func_001DC7F0;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        o[0x20] = 0;
        o[0x21] = 0;
        *(s16 *)(o + 0x26) = 0x3601;
        *(u8 **)(o + 0xD0) = a;
        *(s16 *)(o + 0x1C) = 0;
    }
    if ((r = func_003DA750(o, 3, 2)) != 0) {
        r[0] = 1;
        *(void **)(r + 0x10) = (void *)func_001DC7F0;
        *(u8 **)(r + 0x18) = o;
        r[1] = o[1];
        r[0x20] = 0;
        r[0x21] = 1;
        *(s16 *)(r + 0x26) = 0x3601;
        *(u8 **)(r + 0xD0) = a;
        *(s16 *)(r + 0x1C) = 0;
    }
    if ((r = func_003DA750(0, 3, 0)) != 0) {
        r[0] = 1;
        *(void **)(r + 0x10) = (void *)func_001DC7F0;
        *(u8 **)(r + 0x18) = a;
        r[1] = a[1];
        r[0x20] = 1;
        r[0x21] = 0;
        *(s16 *)(r + 0x26) = 0x3601;
        *(u8 **)(r + 0xD0) = a;
        *(s16 *)(r + 0x1C) = 0x3C;
    }
}
