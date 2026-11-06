#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c065a14(struct Actor *a)
{
    a->b6++;
    a->s28 = 4;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->b1d2 ? -8.33333302f : 8.33333302f;
    a->f104 = a->b1d2 ? 0.0651041642f : -0.0651041642f;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
}

void func_0c065a96(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0)
        a->b6++;
}

void func_0c065af2(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0 || (!a->b525 && (a->w34a & 0x800))) {
        a->b6++;
        func_0c02a0c4(a, 2, 3);
    }
}
