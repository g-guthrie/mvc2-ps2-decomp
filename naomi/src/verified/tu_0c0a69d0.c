#include "objects.h"

struct Vec3_0c0a69d0 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c244290[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043014(struct Actor *, struct Vec3_0c0a69d0 *);
extern void func_0c0346da(struct Actor *, int);

void func_0c0a69d0(struct Actor *a)
{
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 20;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 2);
}

void func_0c0a6a3e(struct Actor *a)
{
    struct Vec3_0c0a69d0 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 == 1) {
        a->b141 = 0;
        v.x = 53.3333321f;
        v.y = 137.142853f;
        func_0c043014(a, &v);
    }
    if (a->b141 == 2) {
        a->b141 = 0;
        func_0c0346da(a, 26);
    }
}

void func_0c0a6aa0(struct Actor *a)
{
    table_0c244290[a->b6](a);
}

void func_0c0a6ab2(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 19;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
