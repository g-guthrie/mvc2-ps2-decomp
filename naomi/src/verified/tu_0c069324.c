#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1385f8(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
void func_0c069324(struct Actor *a, struct SolHorizontalTarget *target)
{
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b7++;
        a->f92 = (target->x - a->f52) / 32.0f;
        a->f104 = 0.0f;
        a->f96 = 8.5714283f;
        a->f108 = -0.66964281f;
        a->s28 = 32;
        func_0c1385f8(a, 1);
        func_0c02a0c4(a, 18, 1);
    }
}
void func_0c0693ce(struct Actor *a, struct SolHorizontalTarget *target)
{
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b7++;
        a->f52 = target->x;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
}
void func_0c069444(struct Actor *a)
{
    (void)func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->b7++;
        a->f56 = a->f41c;
        func_0c043324(a);
        func_0c02a0c4(a, 1, 3);
    }
}
