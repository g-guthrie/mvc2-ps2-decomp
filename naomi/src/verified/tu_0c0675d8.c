#include "objects.h"

struct ActorCounts { unsigned char pad[124]; short counts[64]; };
typedef void (*ActorHandler)(struct Actor *);
extern struct ActorCounts *dat_0c2f83f8;
extern ActorHandler table_0c2404cc[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);

void func_0c0675d8(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->b1f9 = 0;
        func_0c02a0c4(a, 20, 3);
    } else {
        if (a->b140) {
            a->b140 = 0;
            func_0c0346da(a, 48);
        }
        if (func_0c02a026(a) < 0)
            func_0c0437b8(a);
    }
}

void func_0c06763e(struct Actor *a)
{
    table_0c2404cc[a->b6](a);
}

void func_0c067650(struct Actor *a)
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
    a->b1a1 = 84;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
