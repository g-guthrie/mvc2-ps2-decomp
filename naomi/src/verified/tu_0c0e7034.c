#include "objects.h"

struct Vec3_0c0e7034 { float x, y, z; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c0e7034 *, int);

void func_0c0e7034(struct Actor *a)
{
    struct Vec3_0c0e7034 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 30.0f;
        v.y = 120.0f;
        v.z = 0;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c0e70a4(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b14b) {
        a->b14b = 0;
        a->b1a1 = 98;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->w1ac = 16;
    }
    if (a->b141) {
        a->b6++;
        a->b1f9 = 2;
        a->f96 = 34.2857132f;
        a->f108 = -0.80357140303f;
    }
}
