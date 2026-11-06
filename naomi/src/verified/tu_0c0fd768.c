#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern ActorHandler table_0c24ad0c[];

void func_0c0fd768(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->s28 == 22) {
        a->f92 = -10.0f;
        a->f104 = 0.41666666f;
        if (a->b1d2) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        func_0c02a0c4(a, 2, 2);
    }
    if (--a->s28 == 0)
        a->b6++;
}

void func_0c0fd7fc(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0fd856(struct Actor *a)
{
    table_0c24ad0c[a->b6](a);
}
