/* Fading child handler and its owner-linked dispatcher. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c14fb9c(struct Actor *);
extern struct ActorFlags *dat_0c2d6f84;
extern void (*const table_0c250324[])(struct Actor *, struct Actor *, void *);
void func_0c14d2e0(struct Actor *a);
void func_0c14d376(struct Actor *a);

void func_0c14d2e0(struct Actor *a)
{
    struct Actor *o = (struct Actor *)((struct LinkedActor *)a)->p24;
    struct ActorSub2a4 *s;
    func_0c02a026(a);
    if (a->f264) a->f264 -= 0.06f;
    a->f80 -= 0.08f;
    if (a->f80 <= 0.0f) a->f80 = 0.02f;
    a->f84 += 0.200000003f;
    if (a->f84 >= 2.0f) {
        a->b4++;
        a->f84 = 0.0f;
        s = &o->sub2a4;
        s->b20 = 0;
    }
    a->f80 = 1.0f;
    if (!(dat_0c2d6f84->flags & 1)) a->f80 = 0.800000012f;
}

void func_0c14d376(struct Actor *a)
{
    struct Actor *o = (struct Actor *)((struct LinkedActor *)a)->p24;
    float *v = &a->f136;
    table_0c250324[a->b5](a, o, v);
    if (a->b1 != ((struct LinkedActor *)a)->p24->b1) func_0c14fb9c(a);
}
