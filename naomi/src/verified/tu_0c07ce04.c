#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c241788[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c045248(struct Actor *, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);

void func_0c07ce04(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; goto common;
    case 1: a->b1e9 = 0; goto common;
    case 2: ((volatile unsigned char *)a)[0x1e9] = 0; goto common;
    default: goto done;
    }
common:
    /* The byte access keeps SHC's scratch register choice at the tail call. */
    ((char *)a)[0x1a3] = 0;
done:
    func_0c045248(a, 21);
}

void func_0c07ce40(struct Actor *a)
{
    table_0c241788[a->b6](a);
}

void func_0c07ce52(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 59;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 5);
}

void func_0c07cecc(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 6);
    }
}
