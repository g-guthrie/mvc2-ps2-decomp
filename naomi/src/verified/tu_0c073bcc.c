#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c241194[];
extern unsigned char dat_0c241038[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);

void func_0c073bcc(struct Actor *a)
{
    int t;

    a->b1d2 = dat_0c241038[a->b34];
    a->w130 = a->b1d2;
    t = a->b34;
    if (t >= 5)
        t = 8 - t;
    func_0c02a0c4(a, 21, t * 2 + 10);
    func_0c0344a0(a, 32);
}

void func_0c073c18(struct Actor *a)
{
    table_0c241194[a->b6](a);
}

void func_0c073c2a(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->s28 = (unsigned char)a->b1a3 * 4 + 4;
    a->s30 = 0;
    a->b32 = 0;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 59;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, a->b1a3 + 22);
}
