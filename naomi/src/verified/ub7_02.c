/* Exact 360-byte actor unit at 0x0c0c6590; the preceding 4 bytes belong to
 * the previous unit's literal pool. Its own 32-byte pool ends at 0x0c0c66f8. */

#include "objects.h"

typedef void (*handler_ub7_02)(struct Actor *);

extern handler_ub7_02 dat_0c247838[];
extern void func_0c1accc0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern signed char func_0c02a026(struct Actor *);

void func_0c0c6590(struct Actor *a)
{
    float d;

    a->b7++;
    a->s28 = 93;
    a->f100 = a->f52;
    d = 616.66663f;
    if (a->b2 == 0) {
        a->b1d2 = 0;
        a->f52 += d;
    } else {
        a->b1d2 = 1;
        a->f52 -= d;
    }
    a->w130 = a->b1d2;
    a->f56 = a->f41c;
    func_0c1accc0(a, 11);
    func_0c02a0c4(a, 18, 0);
}

void func_0c0c65f6(struct Actor *a)
{
    if (--a->s28 == 0) {
        a->b7++;
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = 0.0f;
        a->f108 = -0.80357140303f;
        func_0c02a0c4(a, 18, 2);
        return;
    }
    func_0c02a026(a);
}

void func_0c0c663e(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 <= a->f41c) {
        a->b7++;
        a->f56 = a->f41c;
        func_0c02a0c4(a, 18, 3);
        return;
    }
    func_0c02a026(a);
}

void func_0c0c669e(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b5++;
        a->b6 = 0;
        a->f52 = a->f100;
    }
}

void func_0c0c66c6(struct Actor *a)
{
    dat_0c247838[a->b7](a);
}
