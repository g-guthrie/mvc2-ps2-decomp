#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c191980(struct Actor *, int);
extern void func_0c13b79c(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);

void func_0c12ba1c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        func_0c191980(a, 5);
        func_0c13b79c(a, 0);
        func_0c02a0c4(a, 21, a->b1a3 + 25);
        func_0c0344a0(a, 31);
    }
    if (a->b141) {
        a->f92 = -10.83333302f;
        if (a->b1d2)
            a->f92 = -a->f92;
    }
}
