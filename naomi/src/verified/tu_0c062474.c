/* Actor landing/jump state handler and its literal pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c134db0(struct Actor *, int);
extern void func_0c044548(struct Actor *, struct Actor *);

void func_0c062474(struct Actor *a)
{
    struct ActorSubMoveBytes *sub = (struct ActorSubMoveBytes *)&a->sub2a4;
    float zero;
    int none;
    func_0c02a026(a);
    zero = 0;
    a->f52 += a->f92;
    a->f92 += a->f104;
    none = 0;
    if (a->b19e < 0) {
        sub->b28 = none;
        func_0c0344a0(a, 43);
        if (!(a->b19e & 127) && func_0c0447bc(a)) {
            a->b6++;
            a->b7 = none;
            func_0c025900(a, 5, 5);
            a->f56 = a->f41c;
            *(struct Actor **)sub = a->p1b0;
            sub->b13 = none;
            sub->b22 = none;
            func_0c134db0(a, 0);
            func_0c02a0c4(a, 22, 15);
            a->b1f7 = 0xc5;
            func_0c044548(a, a->p1b0);
            return;
        }
        a->f56 = a->f41c;
        a->b7 = 1;
        a->f92 = 3.3333333f;
        a->f104 = zero;
        a->f96 = 17.142857f;
        a->f108 = -0.80357140303f;
        if (a->w130) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        func_0c02a0c4(a, 22, 11);
    } else if (--a->s28 == 0) {
        sub->b28 = none;
        func_0c0344a0(a, 43);
        a->b6 = 3;
        a->b7 = none;
        a->f96 = zero;
        a->f108 = zero;
        a->f92 /= 2.0f;
        func_0c02a0c4(a, 22, 10);
    }
}
