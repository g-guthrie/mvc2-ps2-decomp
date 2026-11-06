#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c08de30(struct Actor *a, char *done)
{
    int zero;
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28)
        return;
    a->b6++;
    *done = 1;
    func_0c025900(a, 0, 0);
    a->b159 = 22;
    a->b158 = 4;
    func_0c02a0c4(a, a->b159, a->b158);
    switch (a->b32) {
    case 0:
        a->f92 = 3.3333333f;
        break;
    case 1:
        a->f92 = -3.3333333f;
        break;
    default:
        a->f92 = 0.0f;
    }
    if (a->b1d2)
        a->f92 *= -1.0f;
    zero = 0;
    a->f96 = 17.142857f;
    a->f108 = -1.07142854f;
    a->b3f9 = zero;
    a->b3f8 = zero;
    a->b327 = zero;
    a->b328 = zero;
}
