#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c03489c(struct Actor *);

void func_0c064050(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c064072(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 <= a->f41c) {
        a->f56 = a->f41c;
        a->b6++;
        func_0c02a0c4(a, 1, 5);
    }
}

void func_0c0640e4(struct Actor *a)
{
    struct Actor *p;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->f56 = a->f41c;
        func_0c025900(a, 0, 0);
        p = a->p1c8;
        p->p1b4 = a;
        p->b1f6 = 2;
        p->b1a1 = 34;
        a->b1d2 = (unsigned char)a->w130;
        p->w130 = a->b1d2 ^ 1;
        p->b1d2 = (unsigned char)p->w130;
        a->f92 = 10.0f;
        a->f104 = 0.0f;
        a->f96 = 17.142857f;
        a->f108 = -0.5357143f;
        if (a->w130)
            a->f92 = -a->f92;
        func_0c02a0c4(a, 1, 2);
        func_0c03489c(a);
    }
}
