#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2407e8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0429a4(struct Actor *, void *, int);
extern void func_0c136c44(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern ActorHandler table_0c2407f4[];

struct Vec3_069dfc { float x, y, z; };

void func_0c069dfc(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 > a->f41c)
        return;
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c043324(a);
    func_0c02a0c4(a, 1, 3);
}

void func_0c069e7a(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c069e9c(struct Actor *a)
{
    table_0c2407e8[a->b6](a);
}

void func_0c069eae(struct Actor *a)
{
    short z;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    z = 0;
    a->b1a1 = 53;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = z;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    a->b1f9 = z;
    a->f56 = a->f41c;
    a->f96 = 0;
    a->f108 = 0;
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 2);
}

void func_0c069f2a(struct Actor *a)
{
    struct Vec3_069dfc v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = -58.3333321f;
        v.y = 147.857132f;
        v.z = 0;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c069fca(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        int z;

        z = 0;
        a->b3f8 = a->b3f9 = z;
        a->b327 = z;
        a->b328 = z;
        a->b141 = z;
        func_0c136c44(a);
    }
}

void func_0c06a032(struct Actor *a)
{
    table_0c2407f4[a->b6](a);
}

void func_0c06a044(struct Actor *a)
{
    short z;

    a->b6++;
    z = 0;
    a->b1a1 = a->b1a3 ? 56 : 54;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = z;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 8);
    func_0c0442fa(a);
    a->f96 = 0;
    a->f108 = 0;
    a->f56 = a->f41c;
    a->b1f9 = z;
    func_0c0432ca(a);
    a->s28 = 15;
    func_0c02a0c4(a, 21, 5);
}
