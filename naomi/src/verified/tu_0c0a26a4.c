#include "objects.h"

struct Vec3_0c0a26a4 { float x, y, z; };

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243ae8[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1cea66(struct Actor *, struct Vec3_0c0a26a4 *, int);
extern void func_0c0346da(struct Actor *, int);

void func_0c0a26a4(struct Actor *a)
{
    struct Vec3_0c0a26a4 v;
    struct Actor *o;

    if (func_0c02a026(a) >= 0) {
        if (a->b141 == 6) {
            func_0c025900(a, 0, 0);
            v.x = -133.33333f;
            v.y = 137.142853f;
            func_0c1cea66(a, &v, 15);
            func_0c0346da(a, 6);
            o = a->p1c8;
            o->p1b4 = a;
            a->b1d2 = *(unsigned char *)&a->w130;
            o->w130 = (unsigned short)(a->b1d2 ^ 1);
            o->b1d2 = *(unsigned char *)&o->w130;
            o->b1a1 = 32;
            o->b1f6 = 1;
            return;
        }
    } else
        func_0c0437b8(a);
}

void func_0c0a272e(struct Actor *a)
{
    a->b1ea = 1;
    table_0c243ae8[a->b6](a);
}

void func_0c0a2748(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 != 2) {
        a->b6 = a->b6 + 1;
        a->b1f9 = 2;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        if (a->b1d2)
            a->f92 = 12.85714245f;
        else
            a->f92 = -12.85714245f;
        if (a->b1d2)
            a->f104 = -0.2678571343422f;
        else
            a->f104 = 0.2678571343422f;
        a->f96 = 27.8571415f;
        a->f108 = -1.07142854f;
    }
}
