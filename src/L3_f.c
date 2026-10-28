typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *(*D_004C2B0C)(s32);
extern s32 func_00119098(f32);

/* MW 3.0.3 -O3,p -sdatathreshold 8. The static helpers below are copies of
 * the real retail callees (credited in src/w2_f.c, src/grok_w3_003f.c,
 * src/fb16_a.c, src/w2_g.c, src/fb69_c.c, src/s5b_a.c, src/fb15_a.c,
 * src/fb14_a.c, src/fb1_b.c and src/fb13_c.c); each compiles exact at its
 * own retail address under this file's flags. Retail compiled the caller
 * after these leaves, so it keeps values in $t registers across the calls.
 * func_003F2350 uses an explicit integer address for its indexed load, which
 * this compiler needs to keep retail's separate +4. */
static u32 *func_003F1F90(u32 *p, u32 key)
{
    u32 *e = p;
    u32 i;
    if (p[0] & key) {
        e += 3;
        for (i = 0; i < p[1]; i++) {
            if (e[0] == key) return e;
            e = (u32 *)((u8 *)e + e[2]);
        }
    }
    return 0;
}

static s32 func_003F1FF0(void *p)
{
    s32 *r = (s32 *)func_003F1F90(p, 0x100);
    if (r == 0)
        return -1;
    return r[1];
}

static s32 func_003F2030(void *p)
{
    s32 *r = (s32 *)func_003F1F90(p, 0x800);
    if (r != 0)
        return r[1];
    return -1;
}

static s32 func_003F2060(u32 *a, s32 idx)
{
    u32 *r = func_003F1F90(a, 0x400);
    if (r == 0) return -1;
    return *(s32 *)((s32)r + 0xC + idx * 4);
}

static s32 func_003F20A0(u8 *p, s32 n)
{
    u8 *q;
    s32 i;
    u32 sz;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        q += 12;
        for (i = 0; i <= n; i++) {
            sz = *(u32 *)q & 0x7FFFFFFF;
            q += sz * 4 + 4;
        }
        return sz;
    }
    return -1;
}

static s32 func_003F21F0(u8 *p, s32 n)
{
    u8 *q;
    s32 i;
    u32 sz;
    u32 f;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        q += 12;
        for (i = 0; i <= n; i++) {
            sz = *(u32 *)q;
            f = sz & 0x80000000;
            q += (sz & 0x7FFFFFFF) * 4 + 4;
        }
        return f != 0;
    }
    return -1;
}

static s32 func_003F2350(u8 *p, s32 n, s32 k)
{
    u8 *q;
    u8 *t;
    s32 i;
    s32 r, sz;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        t = q + 12;
        for (i = 0; i < n; i++) {
            t += (*(u32 *)t & 0x7FFFFFFF) * 4 + 4;
        }
        sz = *(u32 *)t & 0x7FFFFFFF;
        if (k >= sz) r = -1; else r = *(s32 *)((u32)(t + 4) + k * 4);
        return r;
    }
    return -1;
}

typedef struct { s32 a, b, c; } E12;
static u8 *func_003F24D0(u8 *a, s32 n)
{
    u8 *r;
    E12 *q;
    r = (u8 *)func_003F1F90((u32 *)a, 0x800);
    q = (E12 *)(r + 12);
    if (r == 0) return 0;
    return (u8 *)&q[n];
}

static u32 *func_003F2510(u32 *p, u32 n) {
    u32 *e = func_003F1F90(p, 0x1000);
    u32 *b = e + 3;
    u32 *r;
    if (e == 0) r = 0; else r = (u32 *)((u8 *)b + n * 12);
    return r;
}

static u8 *func_003F2550(u32 *p, s32 i) {
    u8 *r = (u8 *)func_003F1F90(p, 0x4000);
    if (r == 0) {
        return 0;
    }
    return (u8 *)((s32)r + 0xC) + i * 8;
}

static u8 *func_003F2590(u32 *p, s32 a1)
{
    u32 *r = func_003F1F90(p, 0x8000);
    if (r == 0) return 0;
    return (u8 *)((u32)r + 0xC + (a1 << 4));
}

extern s32 func_003F3700(s32 *);

s32 func_003F2EB0(u8 *p, u8 *src) {
    s32 i;
    u16 *w;
    s32 n;
    s32 sum;
    s32 j;
    s32 cnt;
    s32 sz;
    f32 *c;
    s32 k;
    u8 *r;
    f32 *v;
    s32 m;
    u8 *q;
    *(u32 *)p = 0x21000;
    *(s32 *)(p + 4) = func_003F1FF0(src);
    if (func_003F3700((s32 *)src) == 1) *(u32 *)p |= 0x400000;
    sum = 0;
    for (i = 0; i < *(s32 *)(p + 4); i++) sum += func_003F20A0(src, i);
    cnt = *(s32 *)(p + 4);
    sz = (cnt + sum) * 2;
    if (*(u32 *)p & 0x400000) sz += cnt * 2;
    r = D_004C2B0C(sz);
    *(u8 **)(p + 8) = r;
    if (r == 0) return 0;
    *(s32 *)(p + 0x1C) = sz;
    w = *(u16 **)(p + 8);
    for (j = 0; j < *(s32 *)(p + 4); j++) {
        n = func_003F20A0(src, j);
        *w = n;
        if (func_003F21F0(src, j)) *w |= 0x8000;
        else *w |= 0x4000;
        w++;
        if (*(u32 *)p & 0x400000) {
            *w = func_003F2060((u32 *)src, j);
            w++;
        }
        if (*(u32 *)p & 0x1000) {
            for (k = 0; k < n; k++) {
                *w = func_003F2350(src, j, k);
                w++;
            }
        }
    }
    *(s32 *)(p + 0xC) = 0x35;
    *(s32 *)(p + 0x14) = func_003F2030(src);
    sz = *(s32 *)(p + 0x14) * 36;
    r = D_004C2B0C(sz);
    *(u8 **)(p + 0x10) = r;
    if (r == 0) return 0;
    *(s32 *)(p + 0x18) = sz;
    q = *(u8 **)(p + 0x10);
    for (m = 0; m < *(s32 *)(p + 0x14); m++) {
        v = (f32 *)func_003F24D0(src, m);
        *(f32 *)(q + 0) = v[0];
        *(f32 *)(q + 4) = v[1];
        *(f32 *)(q + 8) = v[2];
        v = (f32 *)func_003F2510((u32 *)src, m);
        *(f32 *)(q + 0xC) = v[0];
        *(f32 *)(q + 0x10) = v[1];
        *(f32 *)(q + 0x14) = v[2];
        v = (f32 *)func_003F2550((u32 *)src, m);
        *(f32 *)(q + 0x1C) = v[0];
        *(f32 *)(q + 0x20) = v[1];
        c = (f32 *)func_003F2590((u32 *)src, m);
        *(u32 *)(q + 0x18) = (func_00119098(c[3]) << 24) | (func_00119098(c[0]) << 16) | (func_00119098(c[1]) << 8) | func_00119098(c[2]);
        q += 0x24;
    }
    return 1;
}
