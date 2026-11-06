/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
struct Vec3_0c053b94 { float x, y, z; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c053b94 *, int);
extern void func_0c165b30(struct Actor *, int, int);

void func_0c0d8e7c(struct Actor *a, unsigned char *state)
{
    int zero = 0;
    struct Actor *child;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    a->b1a1 = 57;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1f9 = zero;
    child = a->p20c;
    state[1] = child->b1;
    a->s28 = 16;
    a->f92 = a->b1d2 ? 20.0f : -20.0f;
    func_0c0432ca(a);
    func_0c165b30(a, 6, 0);
    func_0c02a0c4(a, 22, 0);
}

void func_0c0d8f34(struct Actor *a)
{
    struct Vec3_0c053b94 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 31.666666031f;
        v.y = 162.857132f;
        v.z = 0;
        func_0c0429a4(a, &v, 1);
    }
}
