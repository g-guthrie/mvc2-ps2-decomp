/* s7d_a: MW 3.0, warm after src/sf11_a.c (MWWARM_30@src/sf11_a.c), -O3 -Op -fp off -sdatathreshold 8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { s16 h[4]; } Q4;
typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3c[0x140 - 0x3C];
    s16 h140;
    u8 pad142[0x180 - 0x142];
    Q4 *q180;
    u8 pad184[0x1D4 - 0x184];
    u16 *w1d4;
} OB;

s32 func_003870C0(OB *a, OB *b)
{
    s16 *pa;
    s16 *pb;
    f32 k;
    f32 d;
    f32 e;
    f32 w;
    f32 z;
    f32 t;
    f32 u;

    pa = a->q180[a->w1d4[2]].h;
    k = 1.6666666269302368f;
    d = k * (f32)pa[0];
    pb = b->q180[b->w1d4[0]].h;
    e = k * (f32)pb[0];
    if (a->h140 != 0) d = -d;
    d += a->f34;
    if (b->h140 != 0) e = -e;
    e += b->f34;
    d -= e;
    if ((f64)d < 0.0) d = -d;
    k = 1.6666666269302368f;
    w = k * (f32)pb[1];
    if (w) {
        w += k * (f32)pa[1];
        if (d < w) {
            k = 2.142857074737549f;
            t = -(k * (f32)pa[2]);
            u = -(k * (f32)pb[2]);
            d = t + a->f38;
            e = u + b->f38;
            d -= e;
            if ((f64)d < 0.0) d = -d;
            k = 2.142857074737549f;
            z = 0.0f;
            w = k * (f32)pb[3];
            if (w != z) {
                w += k * (f32)pa[3];
                if (d < w) return 1;
            }
        }
    }
    return 0;
}
