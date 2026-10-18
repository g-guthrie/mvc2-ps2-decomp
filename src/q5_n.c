typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



void func_0022E910(u8 *a) {
    extern s32 func_00118FA8(f32);
    extern void func_001757E0();
    extern void func_0019F3F0();
    u8 *s1;
    s32 v, w;
    s1 = a + 0x2B8;
    *(s16 *)(s1 + 8) = func_00118FA8(*(f32 *)(a + 0x34));
    *(s16 *)(s1 + 0xA) = func_00118FA8(*(f32 *)(a + 0x38));
    *(f32 *)(a + 0x38) += 171.428558f;
    v = 0xFFB06000;
    if (a[2] != 0) v = 0x4FA000;
    *(f32 *)(a + 0x34) += 1.66666663f * (f32)v / 65536.0f;
    w = 0x68000;
    if (a[2] != 0) w = 0xFFF98000;
    *(f32 *)(a + 0x5C) = 1.66666663f * (f32)w / 65536.0f;
    *(u32 *)(a + 0x60) = 0xBF4DB6DB;
    *(s32 *)(a + 0x68) = 0;
    *(s32 *)(a + 0x6C) = 0;
    func_001757E0(a, 0x12, 3);
    func_0019F3F0(a, 0, 0);
    {
        u32 t = a[7];
        a[7] = t + 1;
    }
}
