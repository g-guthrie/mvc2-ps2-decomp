#include "objects.h"

struct Vec3_0c06cd58 { float x, y, z; };
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c06cd58 *);
extern void func_0c043324(struct Actor *);

void func_0c06cd58(struct Actor *a)
{
    struct Vec3_0c06cd58 v;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b6++;
        a->f92 = a->b1d2 ? 6.66666651f : -6.66666651f;
        a->f104 = 0.0f;
        a->f96 = 6.428571224213f;
        a->f108 = -0.80357140303f;
        a->b1a0 = 10;
        v.x = 20.0f;
        v.y = 115.71428f;
        v.z = 0.0f;
        func_0c1d4610(a, &v);
        func_0c02a0c4(a, 15, 1);
    }
}

void func_0c06ce0c(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 <= a->f41c) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        func_0c043324(a);
        func_0c02a0c4(a, 15, 2);
    }
}
