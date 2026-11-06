#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c07f670(struct Actor *a)
{
    int n;

    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) >= 0)
        return;
    if (func_0c0447bc(a) != 0) {
        a->b6 = a->b6 + 1;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = 34.2857132f;
        a->f108 = 0.0f;
        a->s28 = 18;
        n = 4;
    } else {
        a->b6 = 6;
        n = 2;
    }
    func_0c02a0c4(a, 22, n);
}
