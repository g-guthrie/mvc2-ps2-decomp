#include "objects.h"

struct Vec3_0c07ca84 { float x, y, z; };
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c07ca84 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c192b38(struct Actor *);
extern void (*table_0c241770[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);

void func_0c07ca84(struct Actor *a)
{
    struct Vec3_0c07ca84 v;
    func_0c025900(a, 6, 6);
    v.x = -75.0f;
    v.y = 177.857132f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 2);
    func_0c192b38(a);
}

void func_0c07cae0(struct Actor *a)
{
    a->b1ea = 1;
    table_0c241770[a->b1f7 & 63](a);
}

void func_0c07cafe(struct Actor *a)
{
    struct Actor *p;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        p = a->p1c8;
        p->p1b4 = a;
        p->b1f6 = 4;
        p->b1f9 = 2;
        func_0c025900(a, 0, 0);
        p->b1a1 = 32;
        p->b1d2 = a->b1d2 ^ 1;
        func_0c0344a0(a, 32);
        a->f56 = a->f41c;
    }
}
