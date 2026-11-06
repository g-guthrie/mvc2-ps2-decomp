#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c244a88[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);

void func_0c0b0e1c(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->s30-- == 0) {
        a->b6++;
        a->f104 = a->b1d2 ? -1.66666663f : 1.66666663f;
        func_0c02a0c4(a, 2, 2);
    }
}

void func_0c0b0e9c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0b0ef6(struct Actor *a)
{
    table_0c244a88[a->b6](a);
}
