#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned char dat_0c2d9260[];
extern void func_0c03489c(struct Actor *);
extern void func_0c1d357a(struct Vec3 *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c04b02a(struct Actor *);

struct Vec3 {
    float x, y, z;
};

void func_0c059f00(struct Actor *a)
{
    struct ActorSub2a4 *s;

    s = &a->sub2a4;
    goto call;
call:
    if (func_0c02a026(a) < 0) {
        a->b7++;
        s->b2 = 0;
        a->w130 ^= 1;
        a->b1d2 = *(unsigned char *)&a->w130;
        func_0c02a0c4(a, 15, 58);
    }
}

void func_0c059f4e(struct Actor *a)
{
    unsigned char *p;
    unsigned char one;
    struct Actor *other;
    struct Vec3 v;

    if (func_0c02a026(a) < 0) {
        a->b7++;
        if (a->w130)
            a->f52 += 160.0f;
        else
            a->f52 -= 160.0f;
        func_0c02a0c4(a, 15, 59);
        return;
    }
    if (!a->b141)
        return;
    a->b141 = 0;
    p = dat_0c2d9260;
    one = 1;
    p[5] = one;
    p[6] = one;
    func_0c03489c(a);
    other = a->p1c8;
    other->p1b4 = a;
    one = 81;
    a->b1a1 = one;
    other->b1a1 = one;
    v.x = other->f52;
    v.y = a->f41c;
    func_0c1d357a(&v, 1);
    func_0c0346da(a, 73);
    func_0c04b02a(a);
}
