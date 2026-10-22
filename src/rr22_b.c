typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[0x34];
    f32 f34;
    f32 f38;
    u8 p3c[0x50 - 0x3C];
    f32 f50;
    f32 f54;
    u8 p58[0x140 - 0x58];
    s16 h140;
    u8 p142[0x180 - 0x142];
    s16 (*tab)[4];
} O1E8310;

s32 func_001E8310(O1E8310 *a, O1E8310 *b, s16 i, s16 j) {
    f32 x, y, d, e, g, z;
    s16 *ta = (s16 *)((u8 *)a->tab + i * 8);
    s16 *tb = (s16 *)((u8 *)b->tab + j * 8);
    z = 0.0f;
    x = 1.6666666269302368f * (f32)ta[0] * a->f50;
    if (a->h140 != 0) x = -x;
    x += a->f34;
    y = 1.6666666269302368f * (f32)tb[0] * b->f50;
    if (b->h140 != 0) y = -y;
    y += b->f34;
    d = x;
    d -= y;
    if (d < z) d = -d;
    e = 1.6666666269302368f * (f32)ta[1] * a->f50;
    if (e == z) return 0;
    e += 1.6666666269302368f * (f32)tb[1] * b->f50;
    if (!(d <= e)) return 0;

    x = a->f38 - 2.142857074737549f * (f32)ta[2] * a->f54;
    y = b->f38 - 2.142857074737549f * (f32)tb[2] * b->f54;
    d = x;
    d -= y;
    if (d < z) d = -d;
    g = 2.142857074737549f * (f32)ta[3] * a->f54;
    if (g == z) return 0;
    g += 2.142857074737549f * (f32)tb[3] * b->f54;
    return !(d > g);
}
