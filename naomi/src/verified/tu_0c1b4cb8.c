#include "objects.h"
struct Pair_1b4cb8 { short x,y; };
extern struct Pair_1b4cb8 dat_0c25b084[];

void func_0c1b4cb8(struct Actor *a, struct Actor *b)
{
    struct Pair_1b4cb8 *p = &dat_0c25b084[(signed char)b->b140];
    short x = p->x;
    short y = p->y;
    if (b->w130)
        x = -x;
    a->f52 = b->f52 + 1.66666663f * (float)x;
    a->f56 = b->f56 + 2.14285714f * (float)y;
}
