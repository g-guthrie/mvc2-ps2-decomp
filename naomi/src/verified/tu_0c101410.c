#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *), func_0c02a39a(struct Actor *, int), func_0c02a0c4(struct Actor *, int, int);
extern void func_0c16ed4c(struct Actor *, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c10148e(struct Actor *a);

void func_0c101410(register struct Actor *a)
{
    register void *zero;
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    func_0c0432ca(a);
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    zero = 0;
    a->b1a1 = 52;
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    a->p1c4 = (int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->f56 = a->f41c;
    a->b1f9 = (int)zero;
    func_0c02a0c4(a, 22, (int)zero);
    a->b6++;
    func_0c10148e(a);
}

void func_0c10148e(struct Actor *a)
{
    struct LinkedActorVec3 v;
    int zero;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    zero = 0;
    if (func_0c02a026(a) < 0) {
        a->s28 = 24;
        a->s30 = zero;
        func_0c02a0c4(a, 22, 1);
        a->b6++;
        func_0c16ed4c(a, 0);
    } else if (a->b141) {
        a->b3f0 = zero;
        a->b3f1 = zero;
        a->b141 = zero;
        v.x = -41.666664124f;
        v.y = 216.42856f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    }
}
