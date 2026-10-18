typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



void func_0019F690(u8 *a) {
    extern void func_001757E0();
    f32 *q;
    u8 *o;
    s32 x;
    s32 y;
    s32 z;
    o = *(u8 **)(a + 0x14);
    q = (f32 *)(a + 0x88);
    a[0x13C] = 0;
    a[0x31] = 4;
    x = a[0x21] << 22;
    if (*(s16 *)(a + 0x140) == 0) x = -x;
    *(f32 *)(a + 0x34) = *(f32 *)(o + 0x34) + 1.66666663f * (f32)x / 65536.0f;
    y = 0x800 - (s16)(a[0x21] << 11);
    *(f32 *)(a + 0x38) = *(f32 *)(o + 0x38) + 2.14285707f * (f32)y / 256.0f;
    z = a[0x21] - 1;
    if (z < 0) z = 0;
    *q = 1.66666663f * (f32)(z << 22) / 65536.0f;
    *(s16 *)(a + 0x1C) = 0;
    func_001757E0(a, 0x17, 0);
}
