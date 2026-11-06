#include "objects.h"

struct Vec3_0c0eb978 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
extern ActorHandler table_0c249c08[];
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c0eb978 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

struct Actor *func_0c0eb978(struct Actor *a)
{
    int z = 0;
    struct Actor *q;
    if (!(a->b34 = (a->w1fa & 0x1c00) >> 10))
        return (struct Actor *)z;
    if (a->b1fe)
        return (struct Actor *)z;
    if ((unsigned char)a->b1a3 != 1)
        return (struct Actor *)z;
    if (a->f56 > 137.142853f) {
        if ((q = func_0c037d54(a)) != 0) {
            a->b1f7 = 2;
            return q;
        }
    }
    return (struct Actor *)z;
}
void func_0c0eb9d8(struct Actor *a)
{
    table_0c249c08[a->b1f7 & 63](a);
}
void func_0c0eb9f0(struct Actor *a)
{
    struct Vec3_0c0eb978 v;
    if (!(a->b34 & 1)) {
        a->b1d2 ^= 1;
        a->w130 = (unsigned char)a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = -90.0f;
    v.y = 162.857132f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 1);
}
void func_0c0eba52(struct Actor *a)
{
    struct Vec3_0c0eb978 v;
    if (!(a->b34 & 2)) {
        a->b1d2 ^= 1;
        a->w130 = (unsigned char)a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = -90.0f;
    v.y = 162.857132f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 6);
}
