#include "objects.h"

typedef void (*handler_0c0de0b8)(struct Actor *);

extern char func_0c02a026(struct Actor *);
extern void func_0c04392e(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern handler_0c0de0b8 table_0c248ee0[];

void func_0c0de0b8(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c04392e(a);
        return;
    } else if (a->b14b) {
        a->b1a1 = a->b14b;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = 0;
    }
}

void func_0c0de140(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 >= a->f41c)
        return;
    a->b6 = a->b6 + 1;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c02a0c4(a, 21, 10);
    func_0c043324(a);
}

void func_0c0de1ce(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0de1f0(struct Actor *a)
{
    table_0c248ee0[a->b6](a);
}
