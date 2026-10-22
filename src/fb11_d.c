typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00449280[];
extern f32 func_00417500(u32);
extern f32 func_00417440(u32);

void func_001928E0(u8 *p, s32 a, s32 b) {
    s32 s0, t;
    s16 ang;
    f32 k;
    s0 = D_00449280[p[0x22]];
    if (p[0x1E6] != 0) {
        s0 = (u8)(0x20 - (s8)s0) & 0x1F;
    }
    k = 256.0f * (f32)a;
    ang = ((0x28 - (u8)s0) & 0x1F) << 11;
    *(f32 *)(p + 0x5C) = 1.6666666269302368f * (k * (1000.0f * func_00417500(ang)) / 100000.0f / 256.0f);
    *(f32 *)(p + 0x60) = 2.142857074737549f * (k * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
    t = (s0 + 0x10) & 0x1F;
    k = 256.0f * (f32)b;
    ang = ((0x28 - t) & 0x1F) << 11;
    *(f32 *)(p + 0x68) = 1.6666666269302368f * (k * (1000.0f * func_00417500(ang)) / 100000.0f / 256.0f);
    *(f32 *)(p + 0x6C) = 2.142857074737549f * (k * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
}
