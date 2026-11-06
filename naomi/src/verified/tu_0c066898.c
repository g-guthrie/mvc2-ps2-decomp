#include "objects.h"

struct Vec3_0c066898 { float x, y, z; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c066898 *, int);

void func_0c066898(struct Actor *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    a->s28 = 0;
    func_0c0442fa(a);
    if (a->b1f9 == 2) {
        a->b1f9 = 2;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f108 = -0.80357140303f;
    } else {
        a->b1f9 = 0;
        func_0c0432ca(a);
    }
    a->b1a1 = 68;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, 16);
}

void func_0c066934(struct Actor *a)
{
    struct Vec3_0c066898 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b34 = 0;
        a->s30 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = -53.3333321f;
        v.y = 240.0f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    }
}
