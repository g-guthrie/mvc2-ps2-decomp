#include "objects.h"

typedef void (*handler_0c0b1088)(struct Actor *);

extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1a3d8c(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern handler_0c0b1088 table_0c244aa0[];
extern handler_0c0b1088 table_0c244ab4[];

void func_0c0b1088(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b12c = 1;
    func_0c02a0c4(a, 18, 0);
    func_0c1a3d8c(a, 0);
}

void func_0c0b10b0(struct Actor *a)
{
    if (func_0c02a026(a) >= 0)
        return;
    a->b6 = a->b6 + 1;
    func_0c02a0c4(a, 18, 1);
    a->f96 = 17.142857f;
    a->f108 = -0.80357140303f;
    func_0c1a3d8c(a, 1);
    func_0c0346da(a, 50);
}

void func_0c0b10fa(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c)
        return;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->b5 = a->b5 + 1;
    func_0c0344a0(a, 10);
}

void func_0c0b116e(struct Actor *a)
{
    a->f56 = a->f41c;
    if (func_0c03916c(a) != 0)
        func_0c0437b8(a);
    else
        table_0c244aa0[a->b32](a);
}

void func_0c0b11a4(struct Actor *a)
{
    table_0c244ab4[a->b6](a);
}
