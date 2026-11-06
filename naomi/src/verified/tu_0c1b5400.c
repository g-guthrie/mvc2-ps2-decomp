#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c037688(struct Actor *);

void func_0c1b5400(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->b12c = 0;
    }
}

void func_0c1b5422(struct Actor *a)
{
    struct Actor *p = a->p12;
    int i;
    for (i = 0; i < 12; i++) {
        func_0c037688(p);
        p = p->p12;
    }
    func_0c037688(a);
}

void func_0c1b5450(struct Actor *a)
{
    struct Actor *b;
    float dx;
    float dy;

    if (!a->b35)
        b = a->p20;
    else
        b = a->p8;

    a->w130 = a->b33;
    a->b12c = b->b12c;
    a->l144 = b->l144;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&b->f52;
    dx = 51.666664124f;
    dy = -34.2857132f;
    if (a->b32) {
        dx = -51.666664124f;
        dy = 34.2857132f;
    }
    if (a->w130)
        dx = -dx;
    a->f52 += dx;
    a->f56 += dy;
}
