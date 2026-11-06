#include "objects.h"

struct Vec3_0c075ae8 { float x, y, z; };
extern void func_0c1d4610(struct Actor *, struct Vec3_0c075ae8 *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c04b02a(struct Actor *);
extern void func_0c1cea66(struct Actor *, struct Vec3_0c075ae8 *, int);
extern void func_0c0346da(struct Actor *, int);

void func_0c075ae8(struct Actor *a)
{
    struct Vec3_0c075ae8 v;

    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if ((a->s28 = a->s28 - 1) >= 0)
        return;
    a->b142 = 1;
    v.x = 26.666666031f;
    v.y = 68.57143f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c025900(a, 1, 1);
}

void func_0c075b68(struct Actor *a, struct Actor *b)
{
    func_0c025900(a, 5, 5);
    a->f56 = a->f41c;
    func_0c03edcc(a, b);
}

void func_0c075b92(struct Actor *a, struct Actor *p)
{
    struct Vec3_0c075ae8 v;
    struct ActorSub2a4 *s = &a->sub2a4;

    a->b141 = 0;
    ((unsigned char *)s)[12] = 1;
    func_0c03edcc(a, p);
    p->p1b4 = a;
    p->b1a1 = 33;
    func_0c04b02a(a);
    v.x = 80.0f;
    v.y = 34.2857132f;
    func_0c1cea66(a, &v, 2);
    func_0c0346da(a, 5);
}
