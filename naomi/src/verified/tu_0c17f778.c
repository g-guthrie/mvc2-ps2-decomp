/* Linked actor drop/arc states; reviewed span 0x0c17f778..0x0c17fa30. */
#include "objects.h"
#define LA struct LinkedActor
#define A(a) ((struct Actor *)(a))
struct Tail19c {
    char b19c, b19d, b19e, b19f, pad1a0, b1a1, pad1a2[0x1ac - 0x1a2];
    short w1ac;
    char pad1ae[0x1c4 - 0x1ae];
    int l1c4;
};
#define T(a) ((struct Tail19c *)(a)->pad11)
extern char func_0c02a026(LA *);
extern void func_0c037d0c(LA *);
extern void func_0c02a0c4(LA *, int, int);
extern int func_0c02887e(float *, float *);
extern float func_0c1ec2c0(int);
extern void func_0c180e44(LA *);
extern void func_0c181094(LA *);
extern void func_0c180cf8(LA *);
extern void func_0c180cbc(LA *);
extern void (*table_0c25408c[])(LA *);
extern const signed char dat_0c25409c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c17f80e(LA *);

void func_0c17f778(LA *a)
{
    LA *o = a->p24;
    float v;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    v = a->f92;
    if (!a->sdc.w130) v = -v;
    if (v > 0.0f) {
        if (A(o)->f41c > a->f56) {
            a->f56 = A(o)->f41c;
            a->f96 = 0.0f;
            a->f108 = 0.0f;
        }
        func_0c037d0c(a);
        return;
    }
    a->b6++;
    a->b7 = 0;
    func_0c17f80e(a);
}

void func_0c17f80e(LA *a)
{
    if (!a->b7) {
        float x, y;
        a->b7++;
        x = 6.66666651f;
        y = 0.41666666f;
        if (!(a->sdc.w130 ^= 1)) {
            x = -6.66666651f;
            y = -0.41666666f;
        }
        a->f92 = x;
        a->f104 = y;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 25, 20);
    } else {
        LA *o = a->p24;
        struct LinkedActorVec3 pos;
        volatile short ang;
        float d;
        register float k;
        pos.x = o->f52;
        pos.y = o->f56 + 274.28571f;
        { unsigned char r = func_0c02887e(&a->f52, (float *)&pos) << 1;
        k = 230400.0f;
        ang = ((48 - r) & 63) << 10; }
        k *= func_0c1ec2c0(ang);
        a->f96 = k * 1000.0f / 125000.0f / 256.0f * 2.1428571f;
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        d = o->f52 - a->f52;
        if (!a->sdc.w130) d = -d;
        if (0.0f > d) {
            func_0c180e44(a);
            return;
        } else {
        func_0c02a026(a);
        }
    }
    func_0c037d0c(a);
}

void func_0c17f958(LA *a)
{
    table_0c25408c[a->b4](a);
}

void func_0c17f96a(LA *a)
{
    int zero = 0;
    LA *o;
    a->b4++;
    a->b5 = zero;
    a->b6 = zero;
    o = a->p24;
    func_0c181094(a);
    a->f52 = o->f52;
    a->f56 = o->f56;
    func_0c180cf8(a);
    func_0c180cbc(a);
    T(a)->b1a1 = 19;
    T(a)->w1ac = zero;
    T(a)->b19e = zero;
    *(void **)&T(a)->l1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 25, dat_0c25409c[(unsigned char)a->b33]);
}
