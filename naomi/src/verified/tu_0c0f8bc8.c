#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24a76c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);

void func_0c0f8bc8(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) <= 0) {
        a->b6++;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f92 = a->b1d2 ? 6.66666651f : -6.66666651f;
        func_0c02a0c4(a, 2, 2);
    }
}

void func_0c0f8c54(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6++;
        a->b141 = 0;
    }
}

void func_0c0f8cb2(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0f8d0c(struct Actor *a)
{
    table_0c24a76c[a->b6](a);
}
