#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct ActorMotionFixed3 dat_0c23f7c8[];
void func_0c057a14(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    a->b1f2 = 3;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        sub->b2 = 0;
        func_0c02a0c4(a, 15, 18);
    }
}
void func_0c057a68(struct Actor *a)
{
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    a->b1f2 = 3;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->f92 = dat_0c23f7c8[(unsigned char)a->b1a3].x_speed * 1.66666663f / 65536.0f;
        a->f104 = 0;
        a->f96 = dat_0c23f7c8[(unsigned char)a->b1a3].y_speed * 2.1428571f / 65536.0f;
        a->f108 = dat_0c23f7c8[(unsigned char)a->b1a3].y_acceleration * 2.1428571f / 65536.0f;
        if (!(a->f52 < 0)) a->f92 = -a->f92;
        func_0c02a0c4(a, 15, 12);
    }
}
