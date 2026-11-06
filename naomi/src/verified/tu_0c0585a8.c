#include "objects.h"

extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c23f824[])(struct Actor *);

void func_0c0585a8(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        func_0c043324(a);
        a->b7++;
        func_0c02a0c4(a, 15, 34);
    }
}

void func_0c058612(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c058634(struct Actor *a)
{
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    table_0c23f824[a->b7](a);
}

void func_0c058658(struct Actor *a)
{
    a->b1f2 = 3;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c02a0c4(a, 15, 30);
    }
}
