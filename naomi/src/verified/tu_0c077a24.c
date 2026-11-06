/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c077a24(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

extern ActorHandler table_0c241454[];

void func_0c077a7e(struct Actor *a)
{
    table_0c241454[a->b6](a);
}

void func_0c077a90(struct Actor *a)
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
    a->b1a1 = 81;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 3);
}

void func_0c077b0a(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 4);
        func_0c043324(a);
    }
}
