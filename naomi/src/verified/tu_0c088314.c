#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void (*table_0c2424ac[])(struct Actor *, struct ActorSub2a4 *);
void func_0c088314(struct Actor *a)
{
    if (a->b1f9 != 2) {
        if (func_0c02a026(a) < 0)
            func_0c0437b8(a);
        return;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->f56 = a->f41c;
        a->b1f9 = 0;
        func_0c044f1c(a);
        return;
    }
    else {
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
    if (a->b141 & 1) {
        a->b141 = 0;
        a->f96 += 0.80357140303f;
        a->f108 = -0.80357140303f;
    }
    }
}
void func_0c0883d2(struct Actor *a)
{
    table_0c2424ac[a->b6](a, &a->sub2a4);
}
