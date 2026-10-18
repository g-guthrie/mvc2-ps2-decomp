typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0014E8E0(u8 *a, s16 b, s32 c) {
    extern u8 *func_003DA750();
    extern void func_0014E9B0();
    extern void func_0014EC30(u8 *o, f32 x, f32 y, f32 z);
    extern f32 D_00444300[];
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0014E9B0;
        *(s32 *)(o + 0xD0) = 0x21;
        *(f32 *)(o + 0x34) = D_00444300[c];
        *(u32 *)(o + 0x38) = 0x3EAE147B;
        *(u32 *)(o + 0x3C) = 0x3D8F5C00;
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(s16 *)(o + 0x1E) = b;
        o[0x21] = c;
        *(u8 **)(o + 0x18) = a;
        func_0014EC30(o, -1.600000023841858f, -0.09000000357627869f, 0.0f);
    }
}
