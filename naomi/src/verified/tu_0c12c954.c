/* Landing flags, fixed-point motion, effect position, and dispatcher. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0432ca(struct Actor *), func_0c0442fa(struct Actor *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern const int dat_0c24dc10[];
extern void (*dat_0c24dde8[])(struct Actor *);
void func_0c12c954(struct Actor *a)
{
    int zero, animation;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b7++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    zero = 0;
    a->b1a1 = 68;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    animation = 11;
    if (a->b1f9 == 2) {
        a->f96 = 8.5714283f;
        a->f108 = -0.66964281f;
        animation++;
    } else {
        func_0c0432ca(a);
    }
    func_0c0442fa(a);
    func_0c02a684(a, 2, 0, 1);
    func_0c02a0c4(a, 22, animation);
}
void func_0c12c9f8(struct Actor *a)
{
    struct LinkedActorVec3 position;
    int zero;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    zero = 0;
    if (a->b141 & 2) {
        const int *motion;
        a->b6++;
        a->b7 = zero;
        a->b141 ^= 2;
        a->s28 = 8;
        a->s30 = zero;
        motion = dat_0c24dc10;
        if (a->b1f9 == 2)
            motion += 2;
        a->f92 = (float)*motion++ * 1.66666663f / 65536.0f;
        a->f96 = (float)*motion * 2.1428571f / 65536.0f;
        if (a->b1d2)
            a->f92 = -a->f92;
        a->b1f9 = 2;
    } else if (a->b141 & 1) {
        a->b3f0 = zero;
        a->b3f1 = zero;
        a->b141 ^= 1;
        if (a->b1f9 == 2) {
            position.x = -26.666666031f;
            position.y = 171.42856f;
        } else {
            position.x = -120.0f;
            position.y = 111.42857f;
        }
        func_0c0429a4(a, &position, 1);
    }
}
void func_0c12cb52(struct Actor *a)
{
    a->b1f5 = 1;
    dat_0c24dde8[a->b7](a);
}
