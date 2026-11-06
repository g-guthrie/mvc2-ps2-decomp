#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c0aca40(struct Actor *a)
{
    struct Actor *c;
    struct Vec3_tu5_03 v;
    a->b6++;
    func_0c02a026(a);
    a->b140 = 0;
    a->s28 = 24;
    a->p1c8 = a->p1b0;
    c = a->p1c8;

    v = *(struct Vec3_tu5_03 *)&c->f52;
    func_0c03edcc(a, c);
    c->f92 = (c->f52 - v.x) / 24.0f;
    c->f104 = 0.0f;
    c->f108 = -1.07142854f;
    c->f96 = (c->f56 - v.y) / 24.0f - c->f108 * 24.0f / 2.0f;
    *(struct Vec3_tu5_03 *)&c->f52 = v;
    c->s134 = 0;
    c->s136 = 102;
}
void func_0c0acae4(struct Actor *a)
{
    struct Actor *c = a->p1c8;
    c->i72 += 0x2000;
    c->f80 -= 0.04166667f;
    c->f84 -= 0.04166667f;
    a->p1c8->f52 += a->p1c8->f92;
    a->p1c8->f92 += a->p1c8->f104;
    a->p1c8->f56 += a->p1c8->f96;
    a->p1c8->f96 += a->p1c8->f108;
    func_0c02a026(a);
    if (--a->s28 <= 0) {
        a->b6++;
        c->b12c = 0;
        c->b149 = 0xff;
        func_0c02a0c4(a, 21, 15);
    }
}
