#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int), func_0c043324(struct Actor *);
extern char func_0c02a026(struct Actor *);

#define W151(a) (((char *)&(a)->w150)[1])

void func_0c0d845c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (W151(a) >= 0) {
        func_0c02a026(a);
        if (a->b141) {
            a->b141 = 0;
            if (a->b255 == 3) a->b1a1 = 82;
            else { goto s; s: a->b1a1 = 54; }
            a->w1ac = 0;
            a->b19e = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
        }
    }
    if (a->f96 < 0.0f) {
        a->b6++;
        func_0c02a0c4(a, 21, 5);
    }
}

void func_0c0d8510(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (W151(a) >= 0) func_0c02a026(a);
    if (a->f56 > a->f41c) return;
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c043324(a);
    func_0c02a0c4(a, 21, 6);
}
