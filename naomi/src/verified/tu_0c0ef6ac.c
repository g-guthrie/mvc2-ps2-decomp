#include "objects.h"

struct Host150 { unsigned char pad[0x150]; unsigned char b150; };

extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0346da(struct Actor *, int);

void func_0c0ef6ac(struct Actor *a, struct Actor *b)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if ((&((struct Host150 *)a)->b150)[1] == 0)
        return;
    a->b6 = a->b6 + 1;
    (&((struct Host150 *)a)->b150)[1] = 0;
    a->b1a1 = 61;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    b->b5 = 2;
    if (a->b1d2)
        a->f92 = 23.3333321f;
    else
        a->f92 = -23.3333321f;
    if (a->b1d2)
        a->f104 = -0.8333333135f;
    else
        a->f104 = 0.8333333135f;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    func_0c0346da(a, 41);
}
