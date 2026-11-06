#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24aa7c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c1b4548(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0fc938(struct Actor *);

void func_0c0fb148(struct Actor *a)
{
    float vx;
    func_0c02a026(a);
    if (!a->b141) {
        a->b6++;
        a->s28 = 16;
        vx = 17.5f;
        if (a->b1d2)
            vx = -17.5f;
        a->f92 = vx;
        a->f104 = 0;
        a->f96 = 0;
        a->f108 = 0;
        func_0c1b4548(a, 1, 1);
        func_0c0344a0(a, 33);
    }
}

void func_0c0fb1a2(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 < 0) {
        a->b6++;
        func_0c02a0c4(a, 2, 3);
    }
}

void func_0c0fb20c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0fc938(a);
}

void func_0c0fb22e(struct Actor *a)
{
    table_0c24aa7c[a->b6](a);
}
