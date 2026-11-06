/* Complete 0x0c0a3e7c..0x0c0a3f9c motion transition and shared pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0a3e7c(struct Actor *a)
{
    if (a->b141) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = (a->b1d2 != 0) ? 15.83333302f : -15.83333302f;
        a->f104 = (a->b1d2 != 0) ? -0.3125f : 0.3125f;
        a->f96 = 6.42857143f;
        a->f108 = -0.5357143f;
        a->s28 = 18;
        a->b141 = 0;
    }
    func_0c02a026(a);
}

void func_0c0a3ee8(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->s28 == 0) {

        a->b6++;
        a->f104 += a->b1d2 ? -0.3125f : 0.3125f;
        a->f108 = -0.5357143f;
        func_0c02a0c4(a, 2, 2);
    }
    a->s28--;
}
