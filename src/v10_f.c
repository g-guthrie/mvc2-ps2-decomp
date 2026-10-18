typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

extern s32 D_004C283C;
void func_0033E6E0(s32 n) {
    extern u8 *func_003DA750();
    extern void func_0033E7A0();
    extern void func_00170DF0();
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033E7A0;
        *(s16 *)(o + 0xCC) = n * 2 + 9;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0xC01;
        o[0x20] = n;
        *(s32 *)(o + 0x78) = 0;
        *(s32 *)(o + 0x7C) = 0;
        *(s32 *)(o + 0x80) = 0;
        *(s16 *)(o + 0x1C) = 0xB4 - (n * 360) / 6;
        func_00170DF0(*(s32 *)(o + 0x84));
    }
}
