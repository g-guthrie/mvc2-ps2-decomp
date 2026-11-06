/* Actor motion/state group with reviewed interior pool and initializer fallthrough. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0432ca(struct Actor *), func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c173868(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c10c188(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void (*dat_0c24b99c[])(struct Actor *);
void func_0c10aba4(struct Actor *);
void func_0c10ab18(struct Actor *a)
{
    float horizontal;
    a->b6++;
    a->b1a1 = 53;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0432ca(a);
    a->b1f9 = 0;
    a->b32 = 0;
    a->f56 = a->f41c;
    horizontal = -6.66666651f;
    if (a->b1d2)
        horizontal = 6.66666651f;
    a->f92 = horizontal;
    a->f104 = 0.0f;
    func_0c02a0c4(a, 21, 11);
    *(int *)&a->pad10c[12] = a->b142;
    func_0c173868(a);
    func_0c048bb0(a, 10);
    func_0c10aba4(a);
}
void func_0c10aba4(struct Actor *a)
{
    int zero = 0;
    if (--*(int *)&a->pad10c[12] < 0) {
        *(int *)&a->pad10c[12] = 8;
        func_0c0346da(a, 26);
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) < 0) {
        float horizontal;
        float acceleration;
        a->b6++;
        horizontal = -6.66666651f;
        acceleration = 0.20833333f;
        if (a->w130) {
            horizontal = 6.66666651f;
            acceleration = -0.20833333f;
        }
        a->f92 = horizontal;
        a->f104 = acceleration;
        a->b1a1 = 53;
        a->w1ac = zero;
        a->b19e = zero;
        *(void **)&a->p1c4 = (void *)zero;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 21, 64);
    }
    {
    int state = (signed char)a->b14b;
    if ((unsigned char)state) {
        state += *(int *)&a->pad10b[0];
        a->b1a1 = state;
        a->w1ac = zero;
        a->b19e = zero;
        *(void **)&a->p1c4 = (void *)zero;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = zero;
    }
    }
}
void func_0c10acc4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c10c188(a);
    } else if (a->b141) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        if (!(a->f92 * a->f104 < 0.0f))
            a->f92 = a->f104 = 0.0f;
    }
}
void func_0c10ad20(struct Actor *a)
{
    dat_0c24b99c[a->b6](a);
}
void func_0c10ad32(struct Actor *a)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 53;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a0c4(a, 20, 5);
}
void func_0c10ad8a(struct Actor *a)
{
    struct LinkedActorVec3 position;
    a->b328 = 5;
    (void)func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        func_0c0344a0(a, 21);
        (void)func_0c02a39a(a, 1);
        *(int *)&a->sub2a4 = 0;
        position.x = 21.666666031f;
        position.y = 160.71428f;
        func_0c0429a4(a, &position, 1);
    }
}
