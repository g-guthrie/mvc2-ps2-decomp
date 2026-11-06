#include "objects.h"

typedef void (*ActorHandler_0c06a274)(struct Actor *);
extern ActorHandler_0c06a274 table_0c24080c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);

void func_0c06a274(struct Actor *a)
{
    table_0c24080c[a->b6](a);
}

void func_0c06a286(struct Actor *a)
{
    a->b6++;
    a->b1a1 = a->b1a3 ? 59 : 57;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 8);
    func_0c0442fa(a);
    a->b1f9 = 2;
    a->f92 /= 4.0f;
    a->f104 /= 4.0f;
    a->f96 /= 4.0f;
    a->f108 /= 4.0f;
    a->s28 = 14;
    func_0c02a0c4(a, 21, 13);
}

void func_0c06a30e(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c) {
        ;
    } else {
        a->f56 = a->f41c;
        a->f96 = 0;
        a->f108 = 0;
    }
    if (--a->s28)
        return;
    a->b6++;
    func_0c02a0c4(a, 21, ((unsigned char)a->b1a3 << 1) + 14);
}
