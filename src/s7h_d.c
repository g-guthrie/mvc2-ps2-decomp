typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

s32 func_001C5200(u8 *a, u8 *b)
{
    f32 d;
    f32 t;
    f32 z;
    s16 *e;
    d = *(f32 *)(a + 0x34);
    z = 0.0f;
    e = (s16 *)(*(u8 **)(b + 0x180) + (*(u16 *)(*(u8 **)(b + 0x1D4) + 0xC) << 3));
    t = 1.6666666269302368f * (f32)e[0];
    if (*(s16 *)(b + 0x140) != 0) t = -t;
    t += *(f32 *)(b + 0x34);
    d -= t;
    if ((double)d < 0.0) d = -d;
    t = 1.6666666269302368f * (f32)e[1];
    if (t && d < t) {
        d = *(f32 *)(a + 0x38);
        d -= -(2.142857074737549f * (f32)e[2]) + *(f32 *)(b + 0x38);
        if ((double)d < 0.0) d = -d;
        t = 2.142857074737549f * (f32)e[3];
        if (t && d < t) return 1;
    }
    return 0;
}
