/* Four linked-actor callbacks and their shared pool. The first copies a
 * 12-byte position when wcc matches the parent's w158, then advances state
 * after a failed callback. */
#include "objects.h"
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);

void func_0c1918ec(struct LinkedActor *a, struct LinkedActor *b)
{
    if (a->wcc.short_value == b->sdc.w158.short_value) {
        *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&b->f52;
        a->f56 += a->f96;
        if (func_0c029fc4(a) >= 0)
            return;
    }
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c191938(struct LinkedActor *a)
{
    if (func_0c029fc4(a) < 0) {
        a->b4 = a->b4 + 1;
        a->sdc.b12c = 0;
    }
}

void func_0c19195a(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c191968(struct LinkedActor *a)
{
    func_0c037688(a);
}
