#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c245bdc[], table_0c245c1c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned int func_0c02849a(void);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);

void func_0c0bdab4(struct Actor *a)
{
    a->b6++;
    a->s28 = func_0c02849a() & 3;
    switch (a->s28) {
    case 0: func_0c02a0c4(a, 19, 0); break;
    case 1: func_0c02a0c4(a, 19, 1); break;
    case 2: func_0c02a0c4(a, 19, 2); break;
    case 3: func_0c02a0c4(a, 19, 3); break;
    }
}

void func_0c0bdafe(struct Actor *a)
{
    func_0c02a026(a);
}

void func_0c0bdb04(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else {
        func_0c02a026(a);
    }
}

void func_0c0bdb1e(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 4);
    } else {
        func_0c02a026(a);
    }
}

void func_0c0bdb38(struct Actor *a)
{
    table_0c245bdc[a->b1e9](a);
}

void func_0c0bdb4c(struct Actor *a)
{
    table_0c245c1c[a->b6](a);
}

void func_0c0bdb5e(struct Actor *a)
{
    a->b6++;
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 0);
}
