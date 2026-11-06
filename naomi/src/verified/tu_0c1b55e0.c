#include "objects.h"

extern signed char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c037688(struct Actor *);

void func_0c1b55e0(struct Actor *a, struct Actor *b)
{
    struct Actor *p;
    float dx;

    if (b->b5)
        goto fail;
    if (b->b1d0 != 29)
        goto fail;
    if (b->b1e9 != 3)
        goto fail;
    if (b->b19e && !(b->b19e & 1) && !a->b35) {
        a->b12c = 1;
        p = b->p1b0;
        dx = 26.666666031f;
        if (a->b32)
            dx = -26.666666031f;
        a->f52 = p->f52 + dx;
        a->f56 = p->f56 + 68.57143f;
    }
    if (!a->b12c)
        return;
    if (!a->b5) {
        if (func_0c02a026(a) < 0 && !b->b1a0) {
            if (a->b33)
                goto fail;
            a->b5++;
            func_0c02a0c4(a, 23, 23);
            return;
        }
    } else if (func_0c02a026(a) < 0) {
        goto fail;
    }
    return;
fail:
    a->b4++;
    a->b12c = 0;
}

void func_0c1b56a8(struct Actor *a)
{
    func_0c037688(a);
}
