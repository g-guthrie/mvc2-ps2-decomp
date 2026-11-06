/* Four reviewed actor timer and horizontal motion routines. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c173868(struct Actor *);
extern void func_0c0346da(struct Actor *, int), func_0c0344a0(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c10c188(struct Actor *);
void func_0c10aeb2(struct Actor *);
void func_0c10ae28(struct Actor *a)
{
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        func_0c02a0c4(a, 22, 0);
    }
}
void func_0c10ae5a(struct Actor *a)
{
    a->b328 = 5;
    (void)func_0c02a026(a);
    if (a->b141) {
        float horizontal;
        a->b6++;
        a->s28 = 90;
        *(int *)&a->pad10c[12] = 8;
        horizontal = -10.0f;
        if (a->b1d2)
            horizontal = 10.0f;
        a->f92 = horizontal;
        a->f104 = 0.0f;
        func_0c173868(a);
        func_0c10aeb2(a);
    }
}
void func_0c10aeb2(struct Actor *a)
{
    a->b328 = 5;
    if (--*(int *)&a->pad10c[12] < 0) {
        *(int *)&a->pad10c[12] = 8;
        func_0c0346da(a, 26);
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) < 0) {
        func_0c0344a0(a, 3);
    } else if (--a->s28 < 0) {
        float horizontal;
        float acceleration;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        horizontal = -6.66666651f;
        acceleration = 0.15625f;
        if (a->w130) {
            horizontal = 6.66666651f;
            acceleration = -0.15625f;
        }
        a->f92 = horizontal;
        a->f104 = acceleration;
        a->b1a1 = 60;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 22, 7);
    }
    if (a->b14b) {
        a->b1a1 = a->b14b + *(unsigned char *)((char *)a + 0x2c0);
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = 0;
    }
}
void func_0c10afdc(struct Actor *a)
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
