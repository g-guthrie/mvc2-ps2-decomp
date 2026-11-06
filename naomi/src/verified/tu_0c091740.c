#include "objects.h"

struct Vec3_0c091740 { float x, y, z; };
extern void (*table_0c242c20[])(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c091740 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c091740(struct Actor *a) { table_0c242c20[a->b1f7 & 63](a); }

void func_0c091758(struct Actor *a)
{
    struct Vec3_0c091740 v;
    func_0c025900(a, 5, 5);
    if (a->w1fa & 0x400) {
        a->w130 ^= 1;
        a->b1d2 ^= 1;
    }
    v.x = -146.66666f;
    v.y = 188.57143f;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
    a->b1a0 = 10;
    a->b7 = a->b6 = 0;
    func_0c02a0c4(a, 15, 0);
}

void func_0c0917c0(struct Actor *a)
{
    struct Vec3_0c091740 v;
    func_0c025900(a, 5, 5);
    if (a->w1fa & 0x800) {
        a->w130 ^= 1;
        a->b1d2 ^= 1;
    }
    v.x = -173.33333f;
    v.y = 188.57143f;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
    a->b1a0 = 10;
    a->b7 = a->b6 = 0;
    func_0c02a0c4(a, 15, 1);
}
