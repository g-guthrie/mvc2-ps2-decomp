#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c133b88(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern int func_0c047b98(struct Actor *), func_0c047bbe(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2400f8[])(struct Actor *);

void func_0c061d88(struct Actor *a)
{
    struct ActorSubGuard18 *sub = (struct ActorSubGuard18 *)&a->sub2a4;
    int zero;
    a->b3f8 = 2;
    a->b328 = 5;
    sub->b18 = 6;
    func_0c02a026(a);
    zero = 0;
    if (a->b141 == 1) {
        a->b141 = zero;
        func_0c133b88(a);
        func_0c0346da(a, 72);
    }
    if (--a->s28 == 0) {
        a->b3f9 = zero;
        a->b3f8 = zero;
        a->b327 = zero;
        a->b328 = zero;
        a->b6++;
        func_0c02a0c4(a, 22, 28);
        return;
    }
    sub->b19 = zero;
    if (!a->b525) {
        if (func_0c047b98(a))
            sub->b19 = -1;
        if (func_0c047bbe(a) && sub->b20) {
            sub->b20--;
            a->s28++;
        }
    }
}

void func_0c061e44(struct Actor *a)
{
    struct ActorSubGuard18 *sub = (struct ActorSubGuard18 *)&a->sub2a4;
    sub->b18 = 6;
    if (func_0c02a026(a) < 0) {
        sub->b12 = 0;
        func_0c0437b8(a);
    }
}

void func_0c061e7a(struct Actor *a) { table_0c2400f8[a->b6](a); }
