#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2441ec[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c14b8d8(struct Actor *, int, int, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);

void func_0c0a5094(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b1a1 = 49;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    a->s28 = 30;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 12);
}

void func_0c0a5116(struct Actor *a)
{
    if (a->b141) {
        a->b141 = 0;
        func_0c0346da(a, 22);
    }
    if ((a->s28)-- == 0) {
        a->b6 = a->b6 + 1;
        func_0c02a0c4(a, 21, 13);
    }
    func_0c02a026(a);
}

void func_0c0a5158(struct Actor *a)
{
    if (a->b141) {
        a->b6 = a->b6 + 1;
        func_0c14b8d8(a, 4, 19, 4);
        a->b141 = 0;
    }
    func_0c02a026(a);
}

void func_0c0a5188(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a51aa(struct Actor *a)
{
    table_0c2441ec[a->b6](a);
}
