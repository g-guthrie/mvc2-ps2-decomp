#include "objects.h"

extern void func_0c029fc4(struct Actor *);
extern void func_0c037688(struct Actor *);

void func_0c1a1210(struct Actor *a)
{
    if ((a->s28)-- == 0)
        a->b4++;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c029fc4(a);
}

void func_0c1a1260(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c1a126e(struct Actor *a)
{
    func_0c037688(a);
}
