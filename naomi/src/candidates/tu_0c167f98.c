/* Candidate (386/404): w130 test lands in r0 (retail r1), the 79 store uses r2 (retail r1),
 * and the closing 68/48/64 byte stores share r4 where retail uses r4/r3/r2. */
/* Linked actor child setup: copies the owner's state block and picks a
 * per-direction speed row from dat_0c251fcc. */
#include "objects.h"
#define LA struct LinkedActor
#define B(a, o) (((unsigned char *)(a))[o])
struct Tail19c {
    char b19c, b19d, b19e, b19f, pad1a0, b1a1, pad1a2[0x1ac - 0x1a2];
    short w1ac;
    char pad1ae[0x1c4 - 0x1ae];
    int l1c4;
};
#define T(a) ((struct Tail19c *)(a)->pad11)
struct Speed_251fcc { float x, dx, y, dy; };
extern struct Speed_251fcc dat_0c251fcc[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(LA *, int, int);

void func_0c167f98(LA *a)
{
    float *t;
    a->b5++;
    a->sdc = a->p24->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    t = (float *)&dat_0c251fcc[a->p24->b1a3];
    a->f92 = *t++;
    a->f104 = *t++;
    a->f96 = *t++;
    a->f108 = *t;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&a->p24->f52;
    if (!(a->sdc.w130 == 0)) {
        a->f52 -= -136.66666f;
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    } else {
        a->f52 -= 136.66666f;
    }
    a->f56 += 154.28571f;
    if (!a->p24->b1a3) {
        T(a)->b1a1 = 79;
        T(a)->w1ac = 0;
        T(a)->b19e = 0;
        T(a)->l1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 23, 6);
    } else {
        T(a)->b1a1 = 81;
        T(a)->w1ac = 0;
        T(a)->b19e = 0;
        T(a)->l1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 23, 8);
    }
    T(a)->b19c = 68;
    T(a)->b19d = 68;
    B(a, 0x13d) = 48;
    B(a, 0x13c) = 48;
    B(a, 0x13e) = 64;
    B(a, 0x13f) = 64;
}
