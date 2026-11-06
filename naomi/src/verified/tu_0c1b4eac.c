#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c02850e(struct Actor *);
extern void func_0c037688(struct Actor *);

void func_0c1b4eac(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (func_0c02850e(a) == 0) {
        a->b4++;
        a->b12c = 0;
    }
}

void func_0c1b4f0c(struct Actor *a)
{
    func_0c037688(a);
}
