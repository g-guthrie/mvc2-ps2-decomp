#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2419bc[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c08183c(struct Actor *);

void func_0c07de0c(struct Actor *a)
{
    float vx, ax;
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6++;
        a->s28 = 24;
        vx = -15.83333302f;
        ax = 0.3125f;
        if (a->b1d2) {
            vx = 15.83333302f;
            ax = -0.3125f;
        }
        a->f92 = vx;
        a->f104 = ax;
    }
}
void func_0c07de4e(struct Actor *a)
{
    float force;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 < 0) {
        a->b6++;
        force = 0.5208333135f;
        if (a->b1d2) force = -0.5208333135f;
        a->f104 = force;
        func_0c02a0c4(a, 2, 2);
    }
}
void func_0c07decc(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c08183c(a);
    } else if (a->b141 == 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
}
void func_0c07df2c(struct Actor *a) { table_0c2419bc[a->b6](a); }
