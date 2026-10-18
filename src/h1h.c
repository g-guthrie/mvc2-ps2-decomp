typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_001BA380();
extern u16 *D_004C26F0;
u8 *func_001BA2F0(u8 *p, s32 b) {
    u8 *o = func_003DA750(0, 3, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_001BA380;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = b;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        *(s16 *)(o + 0x26) = 0x1700;
        D_004C26F0 = (u16 *)(o + 0xD0);
        *D_004C26F0 = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
        return o;
    }
    return 0;
}
