#include "objects.h"

#pragma section n150c30
void func_0c150c30(struct Actor *p)
{
    if (--p->s28 <= 0)
        p->b4 = p->b4 + 1;
    p->f52 += p->f92;
    p->f92 += p->f104;
    p->f56 += p->f96;
    p->f96 += p->f108;
}
