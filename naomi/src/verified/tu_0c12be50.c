#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);

extern struct ActorFlags *dat_0c2d6f84;
extern ActorHandler table_0c24dd90[];
extern ActorHandler table_0c24dd9c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c12be50(struct Actor *a)
{
    if (a->f92 != 0.0f) {
        if (dat_0c2d6f84->flags & 1)
            func_0c043352(a);
        a->b1f2 = 3;
    }
    if (a->f92 * a->f104 >= 0.0f) {
        a->b1f2 = 0;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->b7 = 0;
        a->b1f9 = 0;
        a->f56 = a->f41c;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 21, a->b1a3 + 41);
    }
}

void func_0c12beee(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c12bf10(struct Actor *a)
{
    table_0c24dd90[a->b6](a);
}

void func_0c12bf22(struct Actor *a)
{
    table_0c24dd9c[a->b7](a);
}
