#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c042780(struct Actor *);
extern void func_0c0426c2(struct Actor *, int);
extern int func_0c0427f2(struct Actor *);
extern void func_0c0427be(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c088b9c(struct Actor *a, struct ActorSub2a4 *sub)
{
    struct Actor *child;
    int amount;
    a->b1ea = 1;
    a->b1f2 = 3;
    child = a->p1c8;
    child->b1f4 = 2;
    func_0c02a026(a);
    if (func_0c042780(child)) {
        sub->s12 += 2;
        sub->s10--;
        sub->s14--;
        func_0c0426c2(child, 16);
    }
    if (func_0c0427f2(a)) {
        sub->s12 -= 4;
        sub->s10 += 2;
        sub->s14 += 2;
        func_0c0427be(a, 10);
    }
    amount = sub->s10 >> 1;
    if (amount < 0) { sub->s10 = 0; amount = 0; }
    if (amount >= a->b142) amount = a->b142 - 1;
    a->b142 -= amount;
    if (a->b141 & 1) {
        a->b141 ^= 1;
        if ((sub->s14 -= 2) <= 0 || --sub->s18 == 0) {
            a->b7++;
            func_0c02a0c4(a, 15, 4);
        }
    }
}
