#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c04337e(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
void func_0c06bd20(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (a->b141 != 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c04337e(a, 3);
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c06bd96(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    (void)func_0c02a026(a);
    if (a->b141 == 0)
        return;
    a->b6++;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->s28 = 12;
    a->f96 = 34.2857132f;
    a->f108 = -0.401785702f;
}
