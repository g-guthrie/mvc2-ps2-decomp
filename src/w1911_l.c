typedef unsigned char u8;
typedef short s16;
typedef float f32;
typedef int s32;
void func_00222730(u8 *p, s32 n, f32 *o1, f32 *o2) {
    extern f32 func_00417500(s16);
    extern f32 func_00417440(s16);
    f32 c = 256.0f * (f32)n;
    s16 idx = ((40 - p[0x22]) & 0x1F) << 11;
    f32 r;
    r = func_00417500(idx);
    *o1 = *(f32 *)(p + 0x68) + 1.6666666269302368f * (((c * (1000.0f * r)) / 100000.0f) / 256.0f);
    r = func_00417440(idx);
    *o2 = *(f32 *)(p + 0x6C) + 2.142857074737549f * (((c * (1000.0f * r)) / 125000.0f) / 256.0f);
}
