#include "objects.h"

extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *, int, int);

void func_0c19741c(struct LinkedActor *a)
{
    struct LinkedActor *b = a->p24;
    a->b4++;
    a->sdc = b->sdc;
    a->sdc.b12c = 1;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->v80.x = b->v80.x;
    a->v80.y = b->v80.y;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b48 = b->b48;
    a->v80 = b->v80;
    a->b36 = b->b36;
    a->b36 = 0;
    *(struct LinkedActorVec3 *)&a->f52 =
        *(struct LinkedActorVec3 *)&b->f52;
    func_0c02a0c4(a, 23, 9);
}

void func_0c19748e(struct LinkedActor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4 = a->b4 + 1;
        a->sdc.b12c = 0;
    }
}

void func_0c1974b0(struct LinkedActor *a)
{
    func_0c037688(a);
}
