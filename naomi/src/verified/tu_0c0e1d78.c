#include "objects.h"

struct Vec3_0c0e1d78 { float x, y, z; };
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c0e1d78 *, int);

void func_0c0e1d78(struct Actor *a)
{
    struct Vec3_0c0e1d78 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6++;
        a->b141 = 0;
        v.x = -26.66666603088379f;
        v.y = 186.42855834960938f;
        v.z = 0;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c0e1de8(struct Actor *a)
{
    a->b6++;
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a0c4(a, 21, 20);
}

void func_0c0e1e02(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) < 0)
        a->b6++;
}

void func_0c0e1e48(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b6++;
    func_0c02a0c4(a, 21, 21);
}

void func_0c0e1e62(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0)
        a->b6++;
}

void func_0c0e1e8c(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b6++;
    func_0c02a0c4(a, 21, 24);
}
