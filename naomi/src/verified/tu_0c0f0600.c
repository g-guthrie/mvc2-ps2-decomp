#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c1b2e10(struct Actor *, int);

void func_0c0f0600(struct Actor *a)
{
    int zero = 0;
    float stopped;
    struct ActorSub2a4 *sub = &a->sub2a4;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c0442fa(a);
    stopped = 0.0f;
    a->f56 = a->f41c;
    a->b1f9 = zero;
    a->f92 = stopped;
    a->f96 = stopped;
    a->f104 = stopped;
    a->f108 = stopped;
    a->b1a1 = 71;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0432ca(a);
    ((unsigned char *)sub)[13] = zero;
    func_0c02a0c4(a, 22, zero);
}

void func_0c0f0696(struct Actor *a)
{
    struct LinkedActorVec3 position;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    func_0c02a026(a);
    if (((char *)&a->w150)[1] & 1) {
        ((char *)&a->w150)[1] &= 254;
        func_0c1b2e10(a, 6);
    }
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        position.x = 81.666664124f;
        position.y = 147.857132f;
        position.z = 0.0f;
        func_0c0429a4(a, &position, 1);
    }
}
