#include "objects.h"

extern unsigned char dat_0c24ba42[];
extern void func_0c045248(struct Actor *, int);

struct Pair_0c10c238 { unsigned char e, a; };
extern struct Pair_0c10c238 dat_0c24ba48[];
extern struct Pair_0c10c238 dat_0c24ba4e[];

void func_0c10c238(struct Actor *a)
{
    int n;

    a->b6 = a->b7 = a->b5 = 0;
    n = a->b4c9;
    if ((unsigned char)n == 2)
        n += *(int *)((char *)a + 0x2c0);
    *((unsigned char *)a + 0x1e9) = dat_0c24ba42[(unsigned char)n];
    func_0c045248(a, 29);
}

void func_0c10c262(struct Actor *a)
{
    struct Pair_0c10c238 *t = dat_0c24ba48;

    a->b6 = a->b7 = a->b5 = 0;
    a->b1e9 = t[a->b4c9].e;
    *(&a->b1a3) = t[a->b4c9].a;
    func_0c045248(a, 21);
}

void func_0c10c290(struct Actor *a)
{
    struct Pair_0c10c238 *t = dat_0c24ba4e;

    a->b6 = a->b7 = a->b5 = 0;
    a->b1e9 = t[a->b4c9].e;
    *(&a->b1a3) = t[a->b4c9].a;
    func_0c045248(a, 21);
}
