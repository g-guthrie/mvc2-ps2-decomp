#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24b094[])(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);

void func_0c128658(struct Actor *a)
{
    a->b6++;
    func_0c02a39a(a, 0);
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = -0.2678571343422f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 50;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

void func_0c1286d4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        func_0c043324(a);
        a->b6++;
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c128742(struct Actor *p)
{
    if (func_0c02a026(p) < 0) {
        func_0c02a39a(p, 0);
        func_0c0439c4(p);
    }
}
