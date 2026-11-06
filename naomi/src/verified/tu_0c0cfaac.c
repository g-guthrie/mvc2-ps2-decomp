/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0cfaac(struct Actor *a)
{
    a->b6++;
    a->s28 = 24;
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

void func_0c0cfb2e(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->f92 = a->b1d2 ? -4.16666651f : 4.16666651f;
        a->f104 = a->b1d2 ? 0.2864583135f : -0.2864583135f;
        a->b6++;
        a->s28 = 8;
    }
}
