/* Exact 328-byte table-driven motion setup routine, including its pool. */
#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern int func_0c17080c(struct LinkedActor *);
extern void func_0c048bb0(struct Actor *, int);
extern const int *dat_0c24b18c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c103a80(struct Actor *a, struct ActorSubCommandPrefix *sub)
{
    const int *motion;

    if (func_0c02a026(a) < 0) {
        func_0c0344a0(a, 21);
        if (a->b1f9 == 2)
            a->f56 += 85.71428f;
        func_0c17080c((struct LinkedActor *)a);
        func_0c048bb0(a, 5);
        motion = dat_0c24b18c[sub->command];
        motion += (unsigned char)a->b1a3 * 4;
        a->f92 = (float)*motion++ * 1.66666663f / 65536.0f;
        a->f104 = (float)*motion++ * 1.66666663f / 65536.0f;
        a->f96 = (float)*motion++ * 2.1428571f / 65536.0f;
        a->f108 = (float)*motion * 2.1428571f / 65536.0f;
        if (a->b1d2) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        a->b1a1 = a->b1a3 + 50;
        a->w1ac = 0;
        a->b19e = 0;
        *(void **)&a->p1c4 = (void *)0;
        dat_0c2f83f8->arr[a->b2]++;
        a->w1ac |= 0x10;
        a->b7++;
        a->b1f9 = 2;
        func_0c02a0c4(a, 21, 6);
    }
}
