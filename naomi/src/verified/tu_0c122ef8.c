#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
typedef void (*ActorSubHandler)(struct Actor *, struct ActorSub2a4 *);
extern ActorHandler table_0c24d608[];
extern ActorSubHandler table_0c24d614[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c1bc740(struct Actor *, int, int);
extern void func_0c0439c4(struct Actor *);

void func_0c122ef8(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 2;
    a->f92 = -30.0f;
    if (a->b1d2)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 0.2678571343422f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 58;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

void func_0c122f60(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 1);
        func_0c043324(a);
        func_0c1bc740(a, 5, 0);
    }
}

void func_0c122fd8(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0439c4(a);
}

void func_0c122ffa(struct Actor *a)
{
    table_0c24d608[a->b6](a);
}

void func_0c12300c(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    table_0c24d614[a->b1e9](a, sub);
}
