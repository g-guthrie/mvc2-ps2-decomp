#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c243480[])(struct Actor *);
extern int func_0c1ec190(void);

void func_0c09a1ec(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b6++;
        a->f92 = a->b1d2 ? -13.33333302f : 13.33333302f;
        a->f104 = a->b1d2 ? 0.41666666f : -0.41666666f;
        func_0c02a0c4(a, 2, 3);
    }
}

void func_0c09a282(struct Actor *a)
{
    if (a->b141) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c09a2e6(struct Actor *a) { table_0c243480[a->b6](a); }

void func_0c09a2f8(struct Actor *a)
{
    a->b6++;
    a->b12c = 1;
    a->s30 = func_0c1ec190() & 1;
    func_0c02a0c4(a, 18, a->s30);
}
