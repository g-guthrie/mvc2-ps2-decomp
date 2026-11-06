/* The initializer differs only in the register used for its direction store.
 * The following complete motion function and all literal-pool bytes match retail. */
#include "objects.h"
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Actor *func_0c1a1a34(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern int func_0c02850e(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
void func_0c0a8800(struct Actor *a)
{
    struct Actor *child;
    float *stored = (float *)&a->sub2a4;
    a->b6++;
    a->b12c = 1;
    *stored = a->f52;
    a->f56 += 205.71428f;
    a->f96 = -8.5714283f;
    a->f108 = 0.33482140303f;
    if (!a->b2) {
        a->w130 = 1;
        a->f52 -= 320.0f;
        a->f92 = 13.33333302f;
    } else {
        register int zero = 0;
        a->w130 = zero;
        a->f52 += 320.0f;
        a->f92 = -13.33333302f;
    }
    a->f104 = 0;
    func_0c02a0c4(a, 2, 5);
    if ((child = func_0c1a1a34(a, 15, 8)) != 0) {
        child->f92 = -a->f92;
        child->f104 = a->f104;
        child->f96 = a->f96;
        child->f108 = a->f108;
        child->w130 = a->w130;
    }
}
void func_0c0a88b2(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    a->b141 = 2;
    a->b141 = 0;
    if (func_0c02850e(a)) {
        a->b6++;
        func_0c0344a0(a, 30);
    }
}
