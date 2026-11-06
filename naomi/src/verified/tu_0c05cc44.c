#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);

void func_0c05cc44(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 < a->f41c) {
        a->b6++;
        a->b1f9 = 0;
        a->f56 = a->f41c;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c043324(a);
        func_0c02a0c4(a, 8, 9);
    }
}

void func_0c05ccd4(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
