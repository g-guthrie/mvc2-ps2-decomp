/* Initializer fallthrough, movement callback, and shared literal pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a18c(struct Actor *, int, int, int);
void func_0c12c40e(struct Actor *a, struct ActorChildReference *sub);
void func_0c12c3a4(struct Actor *a, struct ActorChildReference *sub)
{
    float shift;
    struct Actor *child;
    int zero = 0;
    a->b3f9 = zero;
    a->b3f8 = zero;
    a->b327 = zero;
    a->b328 = zero;
    a->b7++;
    child = sub->child;
    child->b236 = zero;
    a->s28 = 50;
    shift = -80.0f;
    a->f92 = -0.8333333135f;
    if (a->b1d2) {
        shift = 80.0f;
        a->f92 = -a->f92;
    }
    a->f52 += shift;
    a->f56 += 51.42857f;
    a->f96 = 1.07142853737f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c12c40e(a, sub);
}
void func_0c12c40e(struct Actor *a, struct ActorChildReference *sub)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b7++;
        a->f92 = -3.3333333f;
        if (a->b1d2)
            a->f92 = -a->f92;
        a->f96 = 12.85714245f;
        a->f108 = -1.07142853737f;
        func_0c02a18c(a, 1, 1, 4);
    }
}
