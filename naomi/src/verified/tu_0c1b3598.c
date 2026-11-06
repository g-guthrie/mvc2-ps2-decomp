/* The 128-byte translation unit, including both literal pools, matches retail exactly. */
#include "objects.h"

extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c02a684(struct LinkedActor *, int, int, int);

void func_0c1b3598(struct LinkedActor *a)
{
    struct LinkedActor *p = a->p24;

    if (dat_0c2d6f84->flags & 1)
        func_0c02a684(p, 1, p->b37 * 2, 1);
    else
        func_0c02a684(p, 1, p->b37 * 2 + 1, 1);
}

void func_0c1b35c8(struct LinkedActor *a)
{
    struct LinkedActor *p = a->p24;

    func_0c02a684(p, 1, p->b37 * 2, 1);
}

void func_0c1b35e0(struct LinkedActor *a)
{
    struct LinkedActor *p = a->p24;

    if (dat_0c2d6f84->flags & 1)
        func_0c02a684(p, 0, p->b37 * 2, 1);
    else
        func_0c02a684(p, 0, p->b37 * 2 + 1, 1);
}
