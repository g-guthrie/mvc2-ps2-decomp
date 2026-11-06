#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0d3970(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6 = a->b6 + 1;
        a->s28 = 18;
        a->b141 = 0;
        if (a->b1d2)
            a->f92 = -15.0f;
        else
            a->f92 = 15.0f;
        if (a->b1d2)
            a->f104 = 0.41666666f;
        else
            a->f104 = -0.41666666f;
        a->f96 = 10.714285f;
        a->f108 = -1.07142854f;
    }
}

void func_0c0d39d4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 != 0)
        return;
    a->b6 = a->b6 + 1;
    a->f104 = a->b1d2 ? 0.41666666f : 0.41666666f;
    a->f108 = -1.07142854f;
    func_0c02a0c4(a, 2, 3);
}
