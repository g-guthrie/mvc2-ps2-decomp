#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24d5e0[], table_0c24d5ec[], table_0c24d5f4[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c122dc8(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b7)
        return;
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (a->f664 > 53.3333321f)
        return;
    a->b7++;
    func_0c02a0c4(a, 19, 1);
}

void func_0c122e1a(struct Actor *a)
{
    table_0c24d5e0[a->b33](a);
}

void func_0c122e2e(struct Actor *a)
{
    table_0c24d5ec[a->b6](a);
}

void func_0c122e40(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else {
        func_0c02a026(a);
    }
}

void func_0c122e5a(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 0);
    } else {
        func_0c02a026(a);
    }
}

void func_0c122e74(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else {
        func_0c02a026(a);
    }
}

void func_0c122e8e(struct Actor *a)
{
    if (func_0c03916c(a)) {
        if (a->b1f9 == 2)
            func_0c0438de(a);
        else
            func_0c0437b8(a);
    } else {
        table_0c24d5f4[a->b32](a);
    }
}
