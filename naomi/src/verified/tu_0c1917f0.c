#include "objects.h"

extern void func_0c029fc4(struct Actor *);

void func_0c1917f0(struct Actor *a)
{
    struct Actor *p;
    char *q;
    a->b12c = 0;
    p = a->p20;
    if (p->b3 != 1 || p->w38 != 0x0601 || p->b4 >= 2) {
        a->b4++;
        return;
    }
    q = (char *)p + 0x88;
    {
        if (q[42]) {
            *(struct LinkedActorVec3 *)&a->f52 =
                *(struct LinkedActorVec3 *)(q + 16);
            func_0c029fc4(a);
            a->b12c = 1;
        }
        return;
    }
}

void func_0c191854(struct Actor *a, struct Actor *b)
{
    struct Actor *p;
    char *q;
    a->b12c = 0;
    p = a->p20;
    q = (char *)p + 0x88;
    if (p->b3 != 1 || p->w38 != 0x0601 || p->b4 >= 2) {
        a->b4++;
        return;
    }
    {
        *(struct LinkedActorVec3 *)&a->f52 =
            *(struct LinkedActorVec3 *)(q + 28);
        if (b->b1f7 == 5) {
            float dx = 53.3333321f;
            if (b->w130)
                dx = -53.3333321f;
            a->f52 += dx;
        }
        func_0c029fc4(a);
        a->b12c = 1;
        return;
    }
}
