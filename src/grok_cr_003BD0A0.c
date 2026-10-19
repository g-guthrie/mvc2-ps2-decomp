typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern f32 func_00417440(s16);

void func_003BD0A0(u8 *p)
{
    u8 t;
    s16 ang;
    f32 s;
    t = p[0x22] + 1;
    p[0x22] = t;
    t = p[0x22];
    p[0x22] = ((s8)t) & 0x1F;
    ang = (s16)(((0x28 - p[0x22]) & 0x1F) << 11);
    s = func_00417440(ang);
    *(f32 *)(p + 0x38) += 2.142857074737549f * ((38400.0f * (1000.0f * s)) / 125000.0f / 256.0f);
}
