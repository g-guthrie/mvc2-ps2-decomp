/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
struct Vec3_0c0a25ac { float x, y, z; };
extern ActorHandler table_0c243ad8[];
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c0a25ac *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0a25ac(struct Actor *a)
{
    struct Vec3_0c0a25ac v;

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
    func_0c02a0c4(a, 15, 2);
}

void func_0c0a2616(struct Actor *a)
{
    struct Vec3_0c0a25ac v;

    v.x = -83.33333f;
    v.y = 158.57143f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c025900(a, 5, 5);
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 3);
}

void func_0c0a265c(struct Actor *a)
{
    a->b1ea = 1;
    table_0c243ad8[a->b1f7 & 63](a);
}
