#include "objects.h"

extern void func_0c04337e(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2406b8[])(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c06907c(struct Actor *a)
{
    if (a->b141) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c04337e(a, 3);
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0690e6(struct Actor *a) { table_0c2406b8[a->b6](a); }

void func_0c0690f8(struct Actor *a)
{
    func_0c02a026(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b6++;
    a->f92 = a->b1d2 ? -16.666666031f : 16.666666031f;
    a->f104 = a->b1d2 ? 0.3125f : -0.3125f;
}

void func_0c06914c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->b159 = 2;
        a->b158 = 3;
        func_0c02a0c4(a, a->b159, a->b158);
    }
}
