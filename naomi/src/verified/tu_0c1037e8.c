/* Exact 372-byte actor setup and dispatch unit: six routines and one pool. */
#include "objects.h"

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c2f6830;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern int func_0c16fb90(struct LinkedActor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern void (*table_0c24b2a0[])(struct Actor *, struct ActorSub2a4 *);
extern void (*table_0c24b2a8[])(struct Actor *);

void func_0c1037e8(struct Actor *a)
{
    int zero = 0;
    int forty_eight = 48;

    a->b6++;
    a->b1f9 = zero;
    a->f56 = a->f41c;
    a->b1fc = zero;
    a->b1a1 = forty_eight;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c02a39a(a, 0);
    func_0c02a0c4(a, 21, a->b1a3);
}

void func_0c10384e(struct Actor *a)
{
    table_0c24b2a0[a->b7](a, &a->sub2a4);
}

void func_0c103864(struct Actor *a, struct ActorSub2a4 *sub)
{
    func_0c02a026(a);
    if (a->b141) {
        if (dat_0c2f6830 > 6) {
            a->b7++;
            sub->b2 = 0;
            ((unsigned char *)sub)[4] = 6;
            func_0c16fb90((struct LinkedActor *)a);
            return;
        }
        a->b6 = 2;
    }
}

void func_0c1038b2(struct Actor *a, struct ActorSub2a4 *sub)
{
    if ((signed char)sub->b2 >= 0) {
        if ((signed char)sub->b2 != '?')
            return;
        sub->b3 = 1;
        func_0c048bb0(a, 5);
        func_0c0344a0(a, 32);
    }
    a->b6++;
    a->b7 = 0;
}

void func_0c1038e8(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c10390a(struct Actor *a)
{
    table_0c24b2a8[a->b6](a);
}
