#include "objects.h"
extern struct LinkedActor *func_0c189810(struct LinkedActor *, int);
extern void func_0c037688(struct LinkedActor *);

void func_0c18b380(struct LinkedActor *a)
{
    struct LinkedActor *gate = a->p24;
    struct LinkedActor *created;
    register struct LinkedActor *previous;

    if (gate->b5 != 0 || gate->b1d0 != 29)
        goto tail;
    if (!(created = func_0c189810(gate, a->s30)))
        return;
    previous = a->p20;
    if (previous != 0) {
        float delta = 53.3333321f;
        if (created->sdc.w130 != 0)
            delta = -53.3333321f;
        created->f52 = previous->f52 + delta;
    }
    a->p20 = created;
    if (--a->s30 >= 0)
        return;
tail:
    func_0c037688(a);
}
