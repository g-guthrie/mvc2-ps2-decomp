#include "objects.h"

struct Vec3_0a660c { float x, y, z; };

extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0a660c *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c14b8d8(struct Actor *, int, int, int);

void func_0c0a660c(struct Actor *a)
{
    struct Vec3_0a660c v;

    a->b328 = 5;
    if (func_0c02a026(a) >= 0 && a->b141 == 1) {
        a->b141 = 0;
        v.x = -26.666666031f;
        v.y = 137.142853f;
        func_0c0429a4(a, &v, 1);
    }
    if (a->b143 < 0) {
        a->b6++;
        if (a->b1f9 != 2) {
            a->b1f9 = 2;
            a->f56 = a->f41c + 21.42857f;
        }
        a->b7 = 0;
        func_0c02a0c4(a, 22, 3);
        func_0c14b8d8(a, 10, 19, 10);
        func_0c14b8d8(a, 9, 19, 9);
        func_0c14b8d8(a, 11, 19, 11);
    }
    func_0c02a026(a);
}
