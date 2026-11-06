#include "objects.h"

struct ActorCounts { unsigned char pad[124]; short counts[64]; };
typedef void (*ActorHandler)(struct Actor *);
extern struct ActorCounts *dat_0c2f83f8;
extern ActorHandler table_0c244840[], table_0c244854[];
extern unsigned int func_0c1ec190(void);
extern int func_0c03916c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);

void func_0c0ae454(struct Actor *a)
{
    unsigned int r;
    a->b7++;
    r = func_0c1ec190();
    if (r & 1)
        func_0c02a0c4(a, 19, 0);
    else
        func_0c02a0c4(a, 19, 1);
}

void func_0c0ae47e(struct Actor *a)
{
    func_0c02a0c4(a, 19, 2);
}

void func_0c0ae486(struct Actor *a)
{
    func_0c02a0c4(a, 19, 0);
}

void func_0c0ae48e(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c0437b8(a);
    } else {
        table_0c244840[a->b32](a);
    }
}

void func_0c0ae4ba(struct Actor *a)
{
    func_0c02a026(a);
}

void func_0c0ae4c0(struct Actor *a)
{
    table_0c244854[a->b6](a);
}

void func_0c0ae4d2(struct Actor *a)
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
    a->b1a1 = 54;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
