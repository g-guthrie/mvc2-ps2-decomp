#include "objects.h"

extern signed char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c1b69e8(struct Actor *, int);
typedef void (*Handler_0c103448)(struct Actor *);
extern Handler_0c103448 table_0c24b258[];
extern Handler_0c103448 table_0c24b260[];

void func_0c103448(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (--a->s28 != 0)
        return;
    a->b6 = a->b6 + 1;
    func_0c02a0c4(a, 2, 2);
}

void func_0c103494(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c1034b6(struct Actor *a)
{
    table_0c24b258[a->b6](a);
}

void func_0c1034c8(struct Actor *a)
{
    char *p = (char *)&a->sub2a4;
    float dx;

    a->b6 = a->b6 + 1;
    *p = 0;
    func_0c0344a0(a, 30);
    func_0c1b69e8(a, 0);
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    dx = 160.0f;
    a->f92 = 6.875f;
    if (a->b1d2) {
        dx = -160.0f;
        a->f92 = -a->f92;
    }
    a->f52 = a->f52 + dx;
    a->f104 = 0.0f;
}

void func_0c103528(struct Actor *a)
{
    char *p = (char *)&a->sub2a4;

    if (*p == 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
    } else if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c103572(struct Actor *a)
{
    table_0c24b260[a->b6](a);
}
