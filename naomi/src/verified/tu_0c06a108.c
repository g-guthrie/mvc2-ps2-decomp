#include "objects.h"

typedef void (*ActorHandler_0c06a174)(struct Actor *);
extern ActorHandler_0c06a174 table_0c240800[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);

void func_0c06a108(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28)
        return;
    a->b6++;
    func_0c02a0c4(a, 21, ((unsigned char)a->b1a3 << 1) + 6);
}

void func_0c06a140(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c06a162(struct Actor *a)
{
    table_0c240800[a->b6](a);
}

void func_0c06a174(struct Actor *a)
{
    a->b6++;
    a->b1a1 = a->b1a3 ? 59 : 57;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 8);
    func_0c0442fa(a);
    a->f96 = 0;
    a->f108 = 0;
    a->f56 = a->f41c;
    a->b1f9 = 1;
    func_0c0432ca(a);
    a->s28 = 13;
    func_0c02a0c4(a, 21, 9);
}

void func_0c06a1f0(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28)
        return;
    a->b6++;
    func_0c02a0c4(a, 21, ((unsigned char)a->b1a3 << 1) + 10);
}

void func_0c06a228(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
