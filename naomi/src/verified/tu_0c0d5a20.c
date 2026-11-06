#include "objects.h"

struct Vec3 { float x, y, z; };

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c0429a4(struct Actor *, struct Vec3 *, int);
extern void func_0c163a64(struct Actor *, int);

void func_0c0d5a20(struct Actor *a)
{
    int z = 0;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6 = a->b6 + 1;
    a->b1a1 = 82;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = z;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 10);
}

void func_0c0d5aa4(struct Actor *a)
{
    struct Vec3 v;
    int z;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        z = 0;
        a->b6 = a->b6 + 1;
        a->b141 = z;
        a->b3f0 = z;
        a->b3f1 = z;
        func_0c025900(a, 1, 13);
        v.x = -66.666664124f;
        v.y = 23.57143f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c0d5b1e(struct Actor *a)
{
    int z;

    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        z = 0;
        a->b6 = a->b6 + 1;
        a->b141 = z;
        func_0c163a64(a, 4);
        a->s28 = 104;
        a->s30 = 27;
    }
}
