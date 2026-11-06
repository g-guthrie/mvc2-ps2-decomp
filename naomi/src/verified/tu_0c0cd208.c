#include "objects.h"

struct Vec3_0c0cd208 { float x, y, z; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c0cd208 *, int);

void func_0c0cd208(struct Actor *a, struct Actor *b)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f56 = a->f41c;
    a->b1f9 = 0;
    b->b3 = a->b525 ? 16 : 24;
    a->s28 = 40;
    a->b1a1 = 85;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, 1);
}

void func_0c0cd2a4(struct Actor *a)
{
    struct Vec3_0c0cd208 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 61.666664124f;
        v.y = 107.142853f;
        v.z = 0;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c0cd314(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b6++;
    func_0c02a0c4(a, 22, 8);
}
