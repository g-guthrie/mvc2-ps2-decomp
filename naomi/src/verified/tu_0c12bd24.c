/* Throw/launch state handlers; reviewed span 0x0c12bd24..0x0c12be50. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern struct ActorFlags *dat_0c2d6f84;
extern int dat_0c24dc08[];

void func_0c12bd24(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->b1f2 = 3;
        a->s28 = 4;
        a->f92 = (float)dat_0c24dc08[(unsigned char)a->b1a3] * 1.66666663f / 65536.0f;
        if (a->b1d2)
            a->f92 = -a->f92;
        func_0c02a0c4(a, 21, 39);
    }
}

void func_0c12bd88(struct Actor *a)
{
    if (a->b1a3) { if (dat_0c2d6f84->flags & 1) func_0c043352(a); }
    a->b1f5 = 2;
    a->b1f2 = 3;
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    if (!--a->s28) {
        a->b7++;
        a->b1f5 = 0;
        a->f104 = -a->f92 / 8.0f;
        a->f92 /= 2.0f;
        func_0c02a0c4(a, 21, 40);
        func_0c0344a0(a, 32);
    }
}
