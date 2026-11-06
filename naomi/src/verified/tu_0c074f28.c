#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a18c(struct Actor *, int, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c074f28(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 < a->f41c)
        a->f96 = 0.0f;
    if (a->s30) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b7++;
        a->f92 = -4.16666651f;
        if (a->b1d2)
            a->f92 = -a->f92;
        a->f104 = 0.0f;
        a->f96 = 5.35714245f;
        a->f108 = -0.9375f;
        func_0c02a18c(a, 1, 1, 8);
    }
}
void func_0c074fea(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 < a->f41c) {
        a->b6++;
        a->b7 = 0;
        a->b1f9 = 0;
        a->f56 = a->f41c;
        func_0c043324(a);
        func_0c02a0c4(a, 1, 4);
    }
}
