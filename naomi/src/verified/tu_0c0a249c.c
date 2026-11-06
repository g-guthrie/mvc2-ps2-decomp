#include "objects.h"

struct Vec3_0a249c { float x, y, z; };

extern void func_0c1d4610(struct Actor *, struct Vec3_0a249c *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c048ce6(struct Actor *);
extern void func_0c19ee9c(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0a249c(struct Actor *a)
{
    struct Vec3_0a249c v;
    struct Actor *child;

    if (a->w1fa & 0x0400) {
        a->b1d2 = a->b1d2 ^ 1;
        a->w130 = a->w130 ^ 1;
    }
    v.x = -83.33333f;
    v.y = 158.57143f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c025900(a, 5, 5);
    func_0c048ce6(a);
    func_0c19ee9c(a, 0);
    child = a->p1c8;
    func_0c02a0c4(child, 13, 5);
    func_0c02a0c4(a, 15, 0);
}

void func_0c0a251a(struct Actor *a)
{
    struct Vec3_0a249c v;

    if (a->w1fa & 0x0400) {
        a->b1d2 = a->b1d2 ^ 1;
        a->w130 = a->w130 ^ 1;
    }
    v.x = -83.33333f;
    v.y = 158.57143f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c025900(a, 5, 5);
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 1);
}
