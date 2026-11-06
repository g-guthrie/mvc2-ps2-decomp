#include "objects.h"

struct Vec3_0c07f3e8 { float x, y, z; };
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c07f3e8 *, int);

void func_0c07f3e8(struct Actor *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c0442fa(a);
    a->b1f9 = 0;
    func_0c0432ca(a);
    a->sub2a4.l24 = 255;
    a->f56 = a->f41c;
    func_0c02a0c4(a, 22, 0);
}
void func_0c07f438(struct Actor *a)
{
    struct Vec3_0c07f3e8 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    if (func_0c02a026(a) < 0) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6++;
        v.x = -28.3333321f;
        v.y = 173.57143f;
        func_0c0429a4(a, &v, 1);
    }
}
void func_0c07f49c(struct Actor *a)
{
    float vx, ax;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b6++;
    func_0c02a0c4(a, 22, 1);
    a->s28 = 24;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    vx = -26.666666031f;
    ax = 0.41666666f;
    if (a->b1d2) {
        vx = 26.666666031f;
        ax = -0.41666666f;
    }
    a->f92 = vx;
    a->f104 = ax;
}
