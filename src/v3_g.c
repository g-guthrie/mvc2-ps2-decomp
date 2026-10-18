typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

u8 *func_0013AEA0(u8 *a) {
    extern u8 *func_003DA750();
    extern void func_00137140();
    extern void func_0013AF90();
    extern u8 D_004B1221[];
    extern s32 D_004C2830;
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) == 0) return o;
    o[0x13C] = 1;
    *(void **)(o + 0x10) = func_0013AF90;
    *(u8 **)(o + 0x18) = a;
    *(u8 **)(o + 0xC8) = a + 0x88;
    o[0x21] = a[0x21];
    *(s16 *)(o + 0xCC) = D_004B1221[a[0x21] * 2] + 0x79;
    *(s32 *)(o + 0x84) = D_004C2830;
    *(s32 *)(o + 0x34) = 0;
    *(s32 *)(o + 0x38) = 0;
    *(s32 *)(o + 0x3C) = 0;
    func_00137140(o, o[0x21]);
    *(s32 *)(o + 0xD0) = 0x805;
    return o;
}
