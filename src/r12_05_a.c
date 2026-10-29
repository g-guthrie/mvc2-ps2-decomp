/* func_0033A760: model frame-blend callback (passed to func_00170E60 by func_0033A700).
 * Build: MW 3.0.3 (./try.sh) or 3.0, "-O3,p -sdatathreshold 0". */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3c;
typedef struct { u8 pad[0x1C]; s32 f1C; u8 pad2[0x170 - 0x20]; } Ec;
extern Ec D_005BF2F0[];
typedef struct { s32 id; s32 f4; s32 f8; s32 fC; } Ac;
typedef struct { s32 *d; s32 a; s32 b; f32 t; } Bc;
typedef struct { u16 s, c; } Rc;

void func_0033A760(s32 x, s32 a0, Bc *b)
{
    extern void *func_003DD030(s32);
    extern void func_0041BAD0(Ac *);
    extern void func_0041BB30(Ac *);
    u8 *dst;
    Rc *rng;
    u16 *ix;
    Ac *a;
    s32 *d;
    s32 m;
    s32 ka, kb, n, i; u16 k; s32 j; u16 c;
    V3c *v, *p, *q, *o;
    f32 t, vx, vy, vz;

    a = (Ac *)a0;
    t = b->t;
    d = b->d;
    ka = b->a;
    kb = b->b;
    m = a->id - 1;
    dst = func_003DD030(*(s32 *)((s32)&D_005BF2F0[m] + 0x1C));
    rng = func_003DD030(a->f8);
    ix = func_003DD030(a->fC);
    n = *d;
    v = (V3c *)(d + n + 2);
    func_0041BAD0(a);
    i = 0;
    if (0 < n) do {
        p = &v[i + ka * n];
        q = &v[i + kb * n];
        vx = p->x + t * (q->x - p->x);
        vy = p->y + t * (q->y - p->y);
        vz = p->z + t * (q->z - p->z);
        k = rng[i].s;
        c = rng[i].c;
        for (j = 0; j < c; j++, k++) {
            o = (V3c *)(dst + ix[k]);
            o->x = vx;
            o->y = vy;
            o->z = vz;
        }
        i++;
    } while (i < n);
    func_0041BB30(a);
}
