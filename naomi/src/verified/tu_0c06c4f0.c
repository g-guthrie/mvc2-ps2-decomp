#include "objects.h"

typedef void (*ActorHandler)(struct Actor *, struct ActorSub2a4 *);
extern ActorHandler table_0c240958[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c137500(struct Actor *, int);

void func_0c06c4f0(struct Actor *a)
{
    a->b6++;
    a->b1a1 = 72;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 4);
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 50);
}

void func_0c06c55e(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    } else if (a->b141) {
        a->b141 = 0;
        func_0c137500(a, 4);
    }
}

void func_0c06c596(struct Actor *a)
{
    table_0c240958[a->b6](a, &a->sub2a4);
}

void func_0c06c5ac(struct Actor *a)
{
    a->b6++;
    a->b1a1 = 72;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 4);
    func_0c0442fa(a);
    if (a->b1f9 != 2) {
        a->f56 = a->f41c;
        a->b1f9 = 1;
        func_0c0432ca(a);
    }
    func_0c02a0c4(a, 21, a->b1f9 == 2 ? 52 : 51);
}
