#include "objects.h"
extern void func_0c042018(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c044cbc(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c240db8[])(struct Actor *, struct ActorSub2a4 *);

void func_0c06eb54(struct Actor *a)
{
    if (a->b1f9 == 2) {
        func_0c042018(a);
        if (a->f56 < a->f41c) a->f56 = a->f41c;
    }
    table_0c240db8[a->b6](a, &a->sub2a4);
}

void func_0c06eb94(struct Actor *a, struct ActorSub2a4 *sub)
{
    int zero;
    int twelve;
    a->b6++;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c048bb0(a, 5);
    twelve = 12;
    zero = 0;
    if (a->b1f9 == 2) {
        a->f92 /= 16.0f;
        a->f96 /= 8.0f;
        a->f108 /= 64.0f;
        a->f104 = 0.0f;
        a->s28 = 10;
        sub->b0 = twelve;
        a->b1a1 = 52;
        a->w1ac = zero;
        a->b19e = zero;
        *(unsigned int *)&a->p1c4 = zero;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 21, 3);
    } else {
    func_0c044cbc(a);
    func_0c0432ca(a);
    a->b1f9 = zero;
    {
        char v = a->b1a3 + 49;
        if (a->b255 == 3) v = 65;
        a->b1a1 = v;
    }
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3 << 1);
    if (!a->b1a3) {
        sub->b0 = twelve;
        a->s28 = twelve;
    } else {
        sub->b0 = 14;
        a->s28 = 10;
    }
}
}
