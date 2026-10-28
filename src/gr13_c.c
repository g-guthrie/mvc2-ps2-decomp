typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 v[4]; } E18;
typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x10];
    f32 f50;
    f32 f54;
    u8 pad58[0x140 - 0x58];
    s16 h140;
    u8 pad142[0x180 - 0x142];
    E18 *tab;
    u8 pad184[0x1BC - 0x184];
    u16 h1BC;
    u16 h1BE;
} O18;

static void func_0018D6F0(O18 *p, O18 *x, f32 *out) {
    E18 *a;
    E18 *b;
    f32 ax, bx;
    a = (E18 *)((u8 *)x->tab + x->h1BC * 8);
    b = (E18 *)((u8 *)p->tab + p->h1BE * 8);
    ax = 1.6666666f * a->v[0] * x->f50;
    bx = 1.6666666f * b->v[0] * p->f50;
    if (x->h140) ax = -ax;
    if (p->h140) bx = -bx;
    ax += x->f34;
    bx += p->f34;
    if (ax > bx) {
        ax -= 1.6666666f * a->v[1] * x->f50;
        bx += 1.6666666f * b->v[1] * p->f50;
    } else {
        ax += 1.6666666f * a->v[1] * x->f50;
        bx -= 1.6666666f * b->v[1] * p->f50;
    }
    out[0] = (ax + bx) / 2.0f;
    ax = x->f38 + 2.142857074737549f * -(f32)a->v[2] * x->f54;
    bx = p->f38 + 2.142857074737549f * -(f32)b->v[2] * p->f54;
    if (ax > bx) {
        ax -= 2.142857074737549f * a->v[3] * x->f54;
        bx += 2.142857074737549f * b->v[3] * p->f54;
    } else {
        ax += 2.142857074737549f * a->v[3] * x->f54;
        bx -= 2.142857074737549f * b->v[3] * p->f54;
    }
    out[1] = (ax + bx) / 2.0f;
    out[2] = p->f3C;
}

void func_0018D9A0(u8 *p) {
    extern void func_00154790(f32 *buf, s32 a, u32 b, s32 c);
    extern void func_00156E80(f32 *src, s32 unused);
    u8 *x = *(u8 **)(p + 0x1C8);
    u8 *q;
    if (x == 0) return;
    if (x[3] != 0 && x[3] != 1) return;
    *(u8 **)(p + 0x1D0) = *(u8 **)(x + 0x184) + (p[0x1B6] & 0x7F) * 28;
    q = *(u8 **)(p + 0x1D0);
    if (q == 0) return;
    if (*(s8 *)(q + 0xB) >= 0) {
        f32 buf[4];
        u32 c;
        func_0018D6F0((O18 *)p, (O18 *)x, buf);
        c = q[8];
        if (p[0x1BA] != 0) {
            c = (32 - (s8)c) & 0x1F;
        }
        func_00154790(buf, *(s16 *)(p + 0x140), q[0xB], c);
        if (q[0x12] & 0x40) {
            func_00156E80(buf, 0);
        }
    }
}
