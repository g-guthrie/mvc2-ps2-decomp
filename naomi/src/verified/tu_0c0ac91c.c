#include "objects.h"
extern void (*table_0c244688[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c0ac91c(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c)
        return;
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c043324(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 15, 2);
}

void func_0c0ac9aa(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0ac9cc(struct Actor *a)
{
    struct Actor *child;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b14b) {
        a->b14b = 0;
        child = a->p1c8;
        child->p1b4 = a;
        child->b1d2 = a->b1d2;
        child->b1a1 = 33;
        child->b1f6 = 16;
    }
}

void func_0c0aca12(struct Actor *a)
{
    table_0c244688[a->b6](a);
}
