typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0021C0F0(u8 *p, u8 *q) {
    extern void func_00126400();
    extern void func_001E3710();
    extern void func_001E3210();
    extern void func_001548D0();
    extern void func_001E3A40();
    u32 v[4];
    func_00126400(p);
    p[0x151] = 0x10;
    *(u32 *)(p + 0x5C) = 0x41555555;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(u8 **)(q + 0x1C8) = p;
    q[0x20A] = 2;
    q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
    q[0x1B5] = 0x22;
    func_001E3710(p, 2);
    func_001E3210(p, 4);
    v[0] = 0xC2D55555;
    v[1] = 0x42092492;
    func_001548D0(p, v, 2);
    func_001E3A40(p);
}
