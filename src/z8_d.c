typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x38]; f32 f38; u8 p1[0x140 - 0x3C]; s16 f140; } A16;
typedef struct { u8 p0[2]; s16 h2; u8 p1[2]; s16 h6; } B16;
typedef struct { u8 p0[4]; s16 h4; s16 h6; } C16;

s32 func_0016AFE0(A16 *a, A16 *b, B16 *c, C16 *d) {
    f32 k = 2.142857074737549f;
    f32 x, y, z;
    s16 w = c->h2;
    if (w == 0) return 1;
    x = a->f38 + k * (f32)c->h6;
    y = k * (f32)(-d->h4);
    if (b->f140 & 2) y = -y;
    y += b->f38;
    z = x - y;
    if (z < 0.0f) z = -z;
    return z < k * (f32)d->h6 + k * (f32)w;
}

extern f32 D_004F1FC8;
extern f32 D_004F1FD4;
typedef struct { s16 h0, h2; } H2;

void func_003C27B0(u8 *p) {
    extern s32 func_00118FA8(f32);
    H2 *h = (H2 *)(p + 0xD0);
    *(f32 *)(p + 0x34) = 320.0f + D_004F1FC8;
    h->h2 = func_00118FA8(D_004F1FD4 - 274.2857055664f);
    h->h0 = func_00118FA8((f32)h->h0 + *(f32 *)(p + 0x60));
    *(f32 *)(p + 0x38) = (f32)(h->h0 + h->h2);
    if (!((f32)h->h0 < 257.1428527832f)) {
        u32 t;
        h->h0 = 0x101;
        *(f32 *)(p + 0x38) = (f32)(h->h0 + h->h2);
        t = p[5];
        p[5] = t + 1;
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B38E0;

void func_0014F740(u8 *p, s32 a, u32 b) {
    extern u8 *func_003DA750();
    extern void func_00150520(u8 *, f32, f32, f32);
    extern void func_0014F850();
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0014F850;
        *(s32 *)(o + 0xD0) = 0x431;
        *(s16 *)(o + 0x1E) = a;
        o[0x23] = b;
        if (b != 0) *(u32 *)(o + 0x34) = 0x41000000;
        else *(u32 *)(o + 0x34) = 0x410A147B;
        *(u32 *)(o + 0x38) = 0xBF7D70A4;
        *(u32 *)(o + 0x3C) = 0x3D8F5C29;
        *(V3 *)(o + 0x50) = D_004B38E0;
        func_00150520(o, 1.0f, 0.37439998984336853f, 0.6825000047683716f);
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}
