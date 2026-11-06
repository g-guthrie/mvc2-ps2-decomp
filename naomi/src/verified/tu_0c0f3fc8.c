#include "objects.h"

typedef void (*handler_0c07c778)(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
extern handler_0c07c778 dat_0c241764[];
void func_0c07c7d8(struct Actor *p);
extern handler_0c07c778 dat_0c24a2d0[];

struct Actor *func_0c0f3fc8(struct Actor *p)
{
    int z;
    struct Actor *q;

    z = 0;
    if (!(p->b34 = (p->w1fa & 0x0c00) >> 10))
        return (struct Actor *)z;
    if (p->b1fe)
        return (struct Actor *)z;
    if ((unsigned char)p->b1a3 != 1)
        return (struct Actor *)z;
    if (p->f56 > 137.142853f) {
        if ((q = func_0c037d54(p)) != 0) {
            p->b1f7 = 2;
            return q;
        }
    }
    return (struct Actor *)z;
}

void func_0c0f4028(struct Actor *p)
{
    dat_0c24a2d0[p->b1f7 & 63](p);
}

struct Vec3_0f4040 { float x, y, z; };
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0f4040 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0f4040(struct Actor *a)
{
    struct Vec3_0f4040 v;
    a->b1d2 ^= 1;
    a->w130 = a->b1d2;
    if (!(a->b34 & 2)) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = -83.33333f;
    v.y = 158.57143f;
    func_0c1d4610(a, &v);
    ((unsigned char *)a)[0x1a0] = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 0);
}
