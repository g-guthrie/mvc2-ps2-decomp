#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c037688(struct Actor *);

void func_0c19cdf4(struct Actor *a, struct Actor *b)
{
    if (b->b1d0 != 22) {
        a->b4 = 2;
        a->b12c = 0;
        return;
    }
    if (--a->s28 == 0) {
        a->b5++;
        a->b12c = 1;
    }
}

void func_0c19ce26(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (--a->s30 == 0) {
        a->b5++;
        func_0c02a0c4(a, 23, 21);
    }
}

void func_0c19ce72(struct Actor *a)
{
    func_0c02a026(a);
}

void func_0c19ce78(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c19ce86(struct Actor *a)
{
    func_0c037688(a);
}
