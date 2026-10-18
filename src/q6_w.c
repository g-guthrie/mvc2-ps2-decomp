typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002A01D0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_0029B130(u8 *);
    extern void func_00183920(u8 *, u32 *);
    extern void func_00183D10(u8 *);
    f32 *s0, *s1, *s2, *s3;
    f32 a, z;
    u32 v[4];
    if (func_00175700(p) < 0) {
        func_0029B130(p);
        return;
    }
    a = *(f32 *)(p + 0x5C);
    s0 = (f32 *)(p + 0x5C);
    s2 = (f32 *)(p + 0x68);
    s1 = (f32 *)(p + 0x60);
    z = 0.0f;
    *(f32 *)(p + 0x34) += a;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    s3 = (f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[0] = 0xC1F00000;
        v[1] = 0x432B6DB6;
        func_00183920(p, v);
        func_00183D10(p);
    }
    if (*(f32 *)(p + 0x5C) * a < z) {
        *s0 = z;
        *s1 = z;
        *s2 = z;
        *s3 = z;
    }
}
