#include "objects.h"

extern void func_0c02a026(struct Actor *a);

void func_0c0e5858(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b1f9 = 2;
        a->f92 = a->b1d2 ? 33.3333321f : -33.3333321f;
        a->f104 = a->b1d2 ? -2.0833333f : 2.0833333f;
        a->f96 = 42.85714f;
        a->f108 = -1.33928561211f;
    }
}
