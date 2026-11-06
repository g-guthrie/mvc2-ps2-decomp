#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c13bbc4(struct Actor *);

void func_0c12cba4(struct Actor *a)
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
    if (--a->s28 != 0)
        return;
    a->b7 = a->b7 + 1;
    a->f92 /= 16.0f;
    a->f96 /= 16.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 22, 13);
    func_0c13bbc4(a);
}
