#include "objects.h"

struct Vec3_0c05a254 { float x, y, z; };
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c05a254 *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0445fe(struct Actor *, struct Actor *);

void func_0c05a254(struct Actor *a)
{
    struct Actor *p;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = 42.85714f;
        a->f108 = -0.5357143f;
        func_0c02a0c4(a, 15, 43);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        p = a->p1c8;
        p->p1b4 = a;
        a->b1a1 = 83;
        p->b1a1 = 83;
        p->b1f6 = 17;
    }
}

char func_0c05a2ba(struct Actor *a)
{
    register struct ActorSub2a4 *sub = &a->sub2a4;
    if (a->b141 != 0) {
        a->b7++;
        sub->b2 = 0;
    }
    return func_0c02a026(a);
}

void func_0c05a2d6(struct Actor *a)
{
    struct Vec3_0c05a254 v;
    struct Actor *p;

    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    p = a->p1c8;
    if (p->f56 - a->f56 + -17.142857f < -68.57143f) {
        a->b7++;
        a->b1f7 = 205;
        v.x = -146.66666f;
        v.y = 171.42857f;
        func_0c1d4610(a, &v);
        func_0c0344a0(a, 5);
        func_0c02a0c4(a, 15, 29);
        func_0c0445fe(a, p);
    }
}
