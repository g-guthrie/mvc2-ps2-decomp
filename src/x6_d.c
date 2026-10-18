typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2830;
void func_001380A0(void);
void func_00137FD0(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = *(s8 *)(p + 0x538);
        o[0x21] = *(s8 *)(p + 0x1E);
        *(void **)(o + 0x10) = func_001380A0;
        *(s16 *)(o + 0xCC) = o[0x20] + 4;
        *(s32 *)(o + 0x84) = D_004C2830;
        if (*(s8 *)(p + 0x538) != 0) {
            *(u32 *)(o + 0x34) = 0x43120000;
            *(s32 *)(o + 0x48) = 0x11C7;
        } else {
            *(u32 *)(o + 0x34) = 0xC3120000;
            *(s32 *)(o + 0x48) = 0xEE3A;
        }
        *(u32 *)(o + 0x38) = 0x42100000;
        *(u32 *)(o + 0x3C) = 0x43820000;
        *(s32 *)(o + 0x40) = 0xD556;
        *(s32 *)(o + 0x44) = 0;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(s32 *)(o + 0xD0) = 0x81B;
    }
}
