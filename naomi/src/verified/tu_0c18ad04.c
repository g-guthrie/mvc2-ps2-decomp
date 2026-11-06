#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1899e8(struct Actor *, struct Actor *, int);

void func_0c18ad04(struct Actor *a, struct Actor *owner)
{
    if (!a->b6) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c02a026(a);
        if (a->f56 < owner->f41c)
            func_0c1899e8(a, owner, 16);
    }
}

void func_0c18ad78(struct Actor *a, struct Actor *owner)
{
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < owner->f41c) {
        a->f56 = owner->f41c;
        a->b140 = 0;
        if (--a->s28 <= 0)
            func_0c1899e8(a, owner, 10);
    }
    if (!a->b140)
        func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        a->f96 = 8.5714283f;
        a->f108 = -0.80357140303f;
    }
}

void func_0c18adf8(struct Actor *a, struct Actor *owner)
{
    func_0c02a026(a);
    if (--a->s28 <= 0)
        func_0c1899e8(a, owner, 11);
}
