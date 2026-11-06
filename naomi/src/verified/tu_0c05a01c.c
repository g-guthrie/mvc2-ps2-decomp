#include "objects.h"

extern char func_0c02a026(struct Actor *);

void func_0c05a01c(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        a->b7++;
        a->f92 = 8.33333302f;
        a->f104 = 0.0f;
        a->f96 = 28.92857f;
        a->f108 = -1.33928561211f;
        if (a->b1d2 == 0) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
}

void func_0c05a074(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f96 < 0.0f) {
        a->b7++;
        a->f104 = 7.5f;
        if (a->b1d2 == 0)
            a->f104 = -a->f104;
    }
}
