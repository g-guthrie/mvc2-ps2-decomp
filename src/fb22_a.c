typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b, c, d; } Q;

typedef struct {
    u8 b0;
    u8 pad1[4];
    u8 b5;
    u8 pad6[0x34 - 6];
    f32 f34;
    f32 f38;
    u8 pad3c[0x50 - 0x3C];
    f32 f50;
    f32 f54;
    u8 pad58[0x180 - 0x58];
    Q *p180;
    u8 pad184[0x1B4 - 0x184];
    s8 s1b4;
    u8 pad1b5[0x1E6 - 0x1B5];
    u8 b1e6;
    u8 pad1e7[0x209 - 0x1E7];
    u8 b209;
    u8 pad20a[3];
    u8 b20d;
    u8 pad20e[3];
    s8 s211;
    u8 pad212[0x338 - 0x212];
    s8 s338;
    u8 pad339[0x428 - 0x339];
    s32 w428;
} PA;

void func_00181280(PA *a, PA *b)
{
    f32 v[4];
    Q *ta;
    Q *tb;
    f32 *y;
    f32 *z;
    f32 *w;
    f32 k;
    f32 h0;
    f32 h1;
    f32 h2;
    f32 h3;
    f32 h4;
    f32 d;
    s32 r;
    extern void func_00181690(f32, PA *, PA *, f32 *);
    extern void func_00181730(f32, PA *, PA *, f32 *);

    if ((a->b0 & b->b0) == 0) return;
    if (a->b5 == 1 || b->b5 == 1) return;
    if ((a->s1b4 != 0 && b->s1b4 != 0)) return;
    if (a->b209 != 0 || b->b209 != 0) return;
    ta = &a->p180[a->b20d + 252];
    tb = &b->p180[b->b20d + 252];
    k = 1.6666666f;
    h0 = k * (f32)ta->a;
    v[0] = h0 * a->f50;
    if (a->b1e6) v[0] = -v[0];
    v[0] += a->f34;
    h1 = k * (f32)tb->a;
    v[1] = h1 * b->f50;
    y = &v[1];
    if (b->b1e6) *y = -*y;
    *y += b->f34;
    z = &v[2];
    *z = v[0] - *y;
    if (*z < 0.0f) *z = -*(volatile f32 *)z;
    v[3] = k * (f32)ta->b + k * (f32)tb->b;
    w = &v[3];
    d = *w - *z;
    if (d < 0.0f) return;
    k = 2.142857074737549f;
    h2 = k * (f32)ta->c;
    *z = a->f38 + h2 * a->f54;
    *z -= b->f54 * (b->f38 + k * (f32)tb->c);
    if (*z < 0.0f) *z = -*z;
    h3 = k * (f32)ta->d;
    h4 = k * (f32)tb->d;
    *w = h3 * a->f54 + h4 * b->f54;
    if (*w < *z) return;
    if (a->b20d == 2 && b->b20d == 2) {
        func_00181690(d, a, b, v);
        return;
    }
    if ((a->s211 & (1 << a->b1e6)) && b->s338 == 0) {
        func_00181730(d, a, b, v);
        return;
    }
    if (b->s211 & (1 << b->b1e6)) {
        *z = v[0];
        func_00181730(d, b, a, y);
        return;
    }
    if (a->b20d == 2) {
        *z = v[0];
        func_00181730(d, b, a, y);
        return;
    }
    if (b->b20d == 2) {
        func_00181730(d, a, b, v);
        return;
    }
    r = a->w428 & 0x7000000;
    if (r != 0 && (b->w428 & 0x7000000) == 0) {
        func_00181730(d, a, b, v);
        return;
    }
    if (r == 0 && (b->w428 & 0x7000000) != 0) {
        *z = v[0];
        func_00181730(d, b, a, y);
        return;
    }
    func_00181690(d, a, b, v);
}
