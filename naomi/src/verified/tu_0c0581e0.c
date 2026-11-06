#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned char dat_0c2d9260[];
extern void func_0c03489c(struct Actor *);
extern void func_0c04b02a(struct Actor *);

void func_0c0581e0(struct Actor *a)
{
    a->b1f2 = 3;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c02a0c4(a, 15, 25);
    }
}

void func_0c058212(struct Actor *a)
{
    unsigned char *p;
    unsigned char one;
    struct Actor *other;

    a->b1f2 = 3;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        if (a->b1d2)
            a->f52 += 160.0f;
        else
            a->f52 -= 160.0f;
        func_0c02a0c4(a, 15, 26);
        return;
    }
    if (!a->b141)
        return;
    a->b141 = 0;
    p = dat_0c2d9260;
    one = 1;
    p[5] = one;
    p[6] = one;
    func_0c03489c(a);
    other = a->p1c8;
    other->p1b4 = a;
    if (a->b255 == 3) {
        one = 64;
        a->b1a1 = one;
        other->b1a1 = one;
    } else {
        a->b1a1 = a->b1a3 + 63;
        other->b1a1 = a->b1a3 + 63;
    }
    func_0c04b02a(a);
}
