#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243a28[], table_0c243a34[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c037d54(struct Actor *);
extern void func_0c044450(struct Actor *, int);

void func_0c0a102c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a104e(struct Actor *a)
{
    table_0c243a28[a->b6](a);
}

void func_0c0a1060(struct Actor *a)
{
    a->b6++;
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 4);
}

void func_0c0a10d6(struct Actor *a)
{
    int r;
    func_0c02a026(a);
    if (a->b143 < 0) {
        a->b6++;
        func_0c02a0c4(a, 21, 5);
    }
    if (a->b141) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 195;
            func_0c044450(a, r);
        }
    }
}

void func_0c0a1122(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a1144(struct Actor *a)
{
    table_0c243a34[a->b6](a);
}
