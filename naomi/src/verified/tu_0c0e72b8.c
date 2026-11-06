#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
typedef void (*handler_0c0e72b8)(struct Actor *);
extern handler_0c0e72b8 table_0c249704[];

void func_0c0e72b8(struct Actor *a)
{
    func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c)
        return;
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c043324(a);
    func_0c02a0c4(a, 22, 17);
}

void func_0c0e7318(struct Actor *a)
{
    if (func_0c02a026(a) >= 0)
        return;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0437b8(a);
}

void func_0c0e734a(struct Actor *a)
{
    table_0c249704[a->b6](a);
}

void func_0c0e735c(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f56 += 102.85714f;
    a->f92 = 26.666666031f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = -0.5357143f;
    a->b1a1 = 60;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
