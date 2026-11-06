/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
struct Vec3_0c05ec28 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2480a8[];
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c05ec28 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);

void func_0c0cddbc(struct Actor *a)
{
    struct Vec3_0c05ec28 v;

    func_0c025900(a, 5, 5);
    v.x = -83.33333f;
    v.y = 158.57143f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048bb0(a, 8);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 15, 6);
}

void func_0c0cde14(struct Actor *a)
{
    a->b1ea = 1;
    table_0c2480a8[a->b1f7 & 63](a);
}

void func_0c0cde32(struct Actor *a)
{
    struct Actor *o;
    if (a->b141) {
        a->b141 = 0;
        o = a->p1c8;
        o->p1b4 = a;
        o->b1f6 = 1;
        o->b1f9 = 2;
        func_0c025900(a, 0, 0);
        o->b1a1 = 32;
        o->b1d2 = a->b1d2;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0cde90(struct Actor *a)
{
    struct Actor *o;
    if (a->b141) {
        a->b141 = 0;
        o = a->p1c8;
        o->p1b4 = a;
        o->b1f6 = 1;
        o->b1f9 = 2;
        func_0c025900(a, 0, 0);
        o->b1a1 = 33;
        o->b1d2 = a->b1d2;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
