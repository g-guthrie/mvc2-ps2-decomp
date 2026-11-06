/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
struct ActorCounts { unsigned char pad[124]; short counts[64]; };
typedef void (*ActorHandler)(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern struct ActorCounts *dat_0c2f83f8;
extern ActorHandler dat_0c244c0c[];
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c03f004(struct Actor *, struct Actor *);

void func_0c0b2894(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.285714149475098f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 72;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

void func_0c0b290e(struct Actor *a)
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
    }
}

void func_0c0b297c(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0439c4(a);
    } else if (a->b141)
        a->b141 = 0;
}

void func_0c0b29b0(struct Actor *p)
{
    dat_0c244c0c[p->b1f7 & 63](p);
}

void func_0c0b29c8(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c0b29d6(struct Actor *a)
{
    func_0c03f004(a->p1c8, a);
}
