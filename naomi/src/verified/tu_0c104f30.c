#include "objects.h"
struct Vec3_0c06cd58 { float x, y, z; };
extern char func_0c02a026(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c06cd58 *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;

void func_0c104f30(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 2;
    func_0c02a39a(a, 0);
    a->f92 = -36.666664124f;
    if (a->b1d2)
        a->f92 = -a->f92;
    a->f96 = -8.5714283f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 61;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 18);
}

void func_0c104fa8(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 <= a->f41c) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        func_0c043324(a);
        func_0c02a0c4(a, 21, 19);
    }
}

void func_0c105024(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0439c4(a);
}
