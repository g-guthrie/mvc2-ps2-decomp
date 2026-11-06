#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c07f534(struct Actor *a)
{
    struct Actor *target;
    float velocity;
    float offset_or_acceleration;
    int animation;

    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (!a->b141) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (!a->b19e) {
        if ((a->s28 = a->s28 - 1) == 0)
            goto zero;
        return;
    }
    target = a->p1b0;
    if (!func_0c0447bc(a))
        goto zero;
    a->b6++;
    velocity = -3.3333333f;
    offset_or_acceleration = 106.666664124f;
    if (a->b1d2) {
        velocity = 3.3333333f;
        offset_or_acceleration = -106.666664124f;
    }
    a->f92 = velocity;
    a->f104 = 0.0f;
    target->b1f9 = 0;
    target->f56 = a->f41c;
    target->f52 = a->f52 - offset_or_acceleration;
    animation = 3;
    goto call;
zero:
    a->b6 = 6;
    velocity = -16.666666031f;
    offset_or_acceleration = 0.5208333135f;
    if (a->b1d2) {
        velocity = 16.666666031f;
        offset_or_acceleration = -0.5208333135f;
    }
    a->f92 = velocity;
    a->f104 = offset_or_acceleration;
    animation = 2;
call:
    func_0c02a0c4(a, 22, animation);
}
