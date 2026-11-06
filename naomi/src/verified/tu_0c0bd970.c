#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c245bb8[], table_0c245bc0[], table_0c245bd4[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern int func_0c03916c(struct Actor *);

void func_0c0bd970(struct Actor *a)
{
    if (func_0c02a026(a) >= 0) {
        if (a->b141 == 0)
            a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    } else {
        a->b6++;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c02a0c4(a, 2, 3);
    }
}

void func_0c0bd9ee(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0bda10(struct Actor *a)
{
    table_0c245bb8[a->b6](a);
}

void func_0c0bda22(struct Actor *a)
{
    a->b6++;
    a->b12c = 1;
    func_0c02a0c4(a, 18, 0);
}

void func_0c0bda36(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}

void func_0c0bda56(struct Actor *a)
{
    if (func_0c03916c(a))
        func_0c0437b8(a);
    else
        table_0c245bc0[a->b32](a);
}

void func_0c0bda82(struct Actor *a)
{
    table_0c245bd4[a->b6](a);
}
