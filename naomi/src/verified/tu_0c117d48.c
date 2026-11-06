#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern ActorHandler table_0c24cb00[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);

void func_0c117d48(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else {
        func_0c02a026(a);
    }
}

void func_0c117d62(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c0437b8(a);
    } else {
        table_0c24cb00[a->b32](a);
    }
}

void func_0c117d8e(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 2;
    a->f92 = -30.0f;
    if (a->b1d2)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = -0.2678571343422f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 63;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 1);
}

void func_0c117df6(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 2);
        func_0c043324(a);
    }
}

void func_0c117e64(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0439c4(a);
}
