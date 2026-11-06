#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c244f6c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0439c4(struct Actor *);

void func_0c0b6498(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c0b64a6(struct Actor *a)
{
    table_0c244f6c[a->b6](a);
}

void func_0c0b64b8(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 52;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

void func_0c0b6520(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 1);
        func_0c0344a0(a, 13);
    }
}

void func_0c0b6596(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0439c4(a);
}
