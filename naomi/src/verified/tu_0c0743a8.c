#include "objects.h"

typedef void (*LinkHandler)(struct Actor *, struct ActorSub2a4Link *);
extern LinkHandler table_0c2411d4[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);

void func_0c0743a8(struct Actor *a)
{
    table_0c2411d4[a->b7](a, (struct ActorSub2a4Link *)&a->sub2a4);
}

void func_0c0743be(struct Actor *a, struct ActorSub2a4Link *s)
{
    struct Actor *c;
    float x;
    float zero;

    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    if (a->b1fd && *(signed char *)&a->b1fd != 1 << a->b1d2) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        a->b7 = 0;
        func_0c02a0c4(a, 22, 3);
        return;
    }
    if (!a->b19e)
        return;
    zero = 0.0f;
    if (func_0c0447bc(a)) {
        c = a->p1b0;
        a->b7++;
        s->target = c;
        s->s8 = 0;
        x = -100.0f;
        if (a->b1d2)
            x = 100.0f;
        c->f52 = a->f52 + x;
        c->f56 = a->f56;
        c->b1f9 = 0;
        a->f92 = zero;
        a->f104 = zero;
        func_0c025900(a, 8, 8);
        func_0c02a0c4(a, 22, 1);
    } else {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        a->b7 = 0;
        a->f92 = zero;
        a->f96 = zero;
        a->f104 = zero;
        a->f108 = zero;
        func_0c02a0c4(a, 22, 4);
    }
}
