#include "objects.h"
extern signed char func_0c02a026(struct Actor *);
extern void func_0c037688(struct Actor *);

void func_0c140a14(struct Actor *a, struct Actor *b)
{
    char *p = (char *)&b->sub2a4;
    struct Actor *q = a->p20;
    q->b12c = 1;
    if (q->b19f)
        *(char *)((int)a->b35 + (int)(p + 1)) |= -128;
    a->b4 = 2;
    a->b12c = 0;
}

void func_0c140a46(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4 = 3;
        a->b12c = 0;
    }
}

void func_0c140a66(struct Actor *a, struct Actor *b)
{
    char *base = (char *)b + 0x2a4;
    *(char *)((int)a->b35 + (int)(base + 1)) &= -3;
    a->b4 = 3;
    a->b12c = 0;
}

void func_0c140a88(struct Actor *a)
{
    func_0c037688(a);
}
