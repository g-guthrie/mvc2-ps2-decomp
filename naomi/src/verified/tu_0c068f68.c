#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c068f68(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0)
        a->b6++;
}

void func_0c068fc2(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        if (a->b1d2)
            a->f92 = 6.66666651f;
        else
            a->f92 = -6.66666651f;
        if (a->b1d2)
            a->f104 = -0.20833333f;
        else
            a->f104 = 0.20833333f;
        a->b159 = 2;
        a->b158 = 2;
        func_0c02a0c4(a, a->b159, a->b158);
    }
}
