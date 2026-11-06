/* Actor motion and dispatch handlers. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0439c4(struct Actor *);
extern int (*table_0c249fec[])(struct Actor *);

void func_0c0f0878(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 64;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 4);
}

void func_0c0f08f2(struct Actor *a)
{
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c0f0960(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0439c4(a);
    else if (a->b141)
        a->b141 = 0;
}

int func_0c0f098c(struct Actor *a)
{
    return table_0c249fec[a->b1f9](a);
}
