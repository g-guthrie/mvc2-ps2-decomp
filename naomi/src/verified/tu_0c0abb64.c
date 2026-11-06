#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2445e8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c04ae74(struct Actor *, int);
extern void func_0c1d5da8(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);

void func_0c0abb64(struct Actor *a)
{
    func_0c02a026(a);
    a->b6++;
    func_0c02a0c4(a, 21, 19);
}

void func_0c0abb82(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 == 2) {
        a->b141 = 0;
        func_0c04ae74(a, 20);
        func_0c1d5da8(a, 4);
        func_0c0344a0(a, 31);
        func_0c0346da(a, 42);
    }
}

void func_0c0abbd4(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28 <= 0)
        func_0c0437b8(a);
}

void func_0c0abbfa(struct Actor *a)
{
    table_0c2445e8[a->b6](a);
}

void func_0c0abc0c(struct Actor *a)
{
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 72;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 23);
}
