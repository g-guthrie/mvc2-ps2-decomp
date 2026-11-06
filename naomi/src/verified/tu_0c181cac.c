#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c037d0c(struct Actor *);

void func_0c181cac(struct Actor *a)
{
    float delta;

    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if ((a->s30 += 0x2000) == 0)
        a->b19e = 0;
    delta = a->f52 - (float)a->i204;
    if (delta < 0.0f)
        delta = -delta;
    if (delta < 80.0f) {
        a->b5++;
        func_0c02a0c4(a, 22, 1);
    }
    func_0c037d0c(a);
}

void func_0c181d3a(struct Actor *a)
{
    float delta;

    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if ((a->s30 += 0x2000) == 0)
        a->b19e = 0;
    delta = a->f52 - (float)a->i204;
    if (delta < 0.0f)
        delta = -delta;
    if (delta < 40.0f) {
        a->b5++;
        func_0c02a0c4(a, 22, 2);
    }
    func_0c037d0c(a);
}
