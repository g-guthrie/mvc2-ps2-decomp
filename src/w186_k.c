typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18EC[];

s32 func_00164B10(u8 *p) {
    u8 *q;
    s32 sh;
    s32 k;
    u32 flags;
    s32 m;
    s8 cnt;
    f32 y, x, a, b, d;
    u32 r;
    if (p[0x1E4] != *(s8 *)(p + 0x4B7)) goto fail;
    cnt = *(s8 *)(p + 0x4B6) - 1;
    *(s8 *)(p + 0x4B6) = cnt;
    if (cnt == 0) goto fail;
    if (D_004D18EC[0] != 0) goto fail;
    sh = 2 >> p[0x1E6];
    flags = *(u32 *)(p + 0x468);
    k = *(s8 *)(p + 0x211);
    if (flags & 0x400) sh ^= 3;
    m = k & sh;
    if (k != 0 && m != 0) goto fail;
    q = *(u8 **)(p + 0x220);
    y = *(f32 *)(p + 0x460);
    if (q[0x1E6] == 0) y = -y;
    y += *(f32 *)(q + 0x34);
    x = *(f32 *)(p + 0x34);
    a = x;
    if (*(u32 *)(p + 0x46C) != 0) {
        a = y;
        y = x;
    }
    d = a - y;
    if (d < 0.0f) goto fail;
    d = *(f32 *)(q + 0x38) - *(f32 *)(p + 0x464) - *(f32 *)(p + 0x38);
    r = 0;
    if (d < -51.42857f) r = 0x2000;
    if (!(d <= 51.42857f)) r = 0x1000;
    *(u16 *)(p + 0x4F0) = flags | r;
    return 0;
fail:
    {
        u32 t = p[0x451];
        p[0x451] = t - 1;
        *(u16 *)(p + 0x4F0) = 0;
        return 1;
    }
}
