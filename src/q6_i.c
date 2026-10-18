typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001A0E40(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    u8 t = p[5];
    if (t == 0) {
        if (q[0x15B] != 0) {
            p[5] = t + 1;
            func_00175700(p);
        }
    } else {
        f32 a, z = 0.0f;
        func_00175700(p);
        a = *(f32 *)(p + 0x34);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        a -= *(f32 *)(p + 0x34);
        if (a < z) a = -a;
        if (!(a < 0.44921875f)) {
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
            *(f32 *)(p + 0x5C) = 2.0f * *(f32 *)(p + 0x68);
        }
    }
}
