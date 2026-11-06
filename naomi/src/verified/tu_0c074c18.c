#include "objects.h"

struct Glob_074c18 { unsigned char pad[0x7c]; short w7c[1]; };
struct Vec3_074c18 { float x, y, z; };

extern struct Glob_074c18 *dat_0c2f83f8;
extern int dat_0c241048[];
extern void func_0c0432ca(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_074c18 *, int);
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c241214[];

void func_0c074c18(struct Actor *a)
{
    int n;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b7++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 68;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    n = 11;
    if (a->b1f9 == 2) {
        a->f96 = 8.5714283f;
        a->f108 = -0.66964281f;
        n++;
    } else {
        func_0c0432ca(a);
    }
    func_0c0442fa(a);
    func_0c02a0c4(a, 22, n);
}

void func_0c074cb0(struct Actor *a)
{
    struct Vec3_074c18 v;
    int *p;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->b141 & 2) {
        a->b6++;
        a->b7 = 0;
        a->b141 ^= 2;
        a->s28 = 8;
        a->s30 = 0;
        p = dat_0c241048;
        if (a->b1f9 == 2)
            p += 2;
        a->f92 = (float)*p++ * 1.66666663f / 65536.0f;
        a->f96 = (float)*p * 2.1428571f / 65536.0f;
        if (a->b1d2)
            a->f92 = -a->f92;
        a->b1f9 = 2;
    } else if (a->b141 & 1) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b141 ^= 1;
        if (a->b1f9 == 2) {
            v.x = -26.666666031f;
            v.y = 171.42856f;
        } else {
            v.x = -120.0f;
            v.y = 111.42857f;
        }
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c074e06(struct Actor *a)
{
    a->b1f5 = 1;
    table_0c241214[a->b7](a);
}
