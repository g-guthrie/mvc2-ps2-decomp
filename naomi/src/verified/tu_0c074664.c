#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a18c(struct Actor *, int, int, int);
void func_0c0746c4(struct Actor *, struct ActorChildReference *);
void func_0c074664(struct Actor *a, struct ActorChildReference *reference)
{
    float offset;
    struct Actor *child;
    a->b328 = 5;
    a->b7++;
    child = reference->child;
    child->b236 = 0;
    a->s28 = 50;
    offset = -80.0f;
    a->f92 = -0.8333333135f;
    if (a->b1d2) { offset = 80.0f; a->f92 = -a->f92; }
    a->f52 += offset;
    a->f56 += 51.42857f;
    a->f96 = 1.07142854f;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0746c4(a, reference);
}
void func_0c0746c4(struct Actor *a, struct ActorChildReference *reference)
{
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b327 = 0;
        a->b328 = 0;
        a->b7++;
        a->f92 = -3.3333333f;
        if (a->b1d2) a->f92 = -a->f92;
        a->f96 = 12.85714245f;
        a->f108 = -1.07142854f;
        func_0c02a18c(a, 1, 1, 4);
    }
}
