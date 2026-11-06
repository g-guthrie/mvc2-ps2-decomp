#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c1646c0(struct Actor *, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern short dat_0c2f6830;

void func_0c0d565c(struct Actor *a)
{
    int z = 0;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b7 = a->b7 + 1;
    a->b1a1 = 80;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = z;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 4);
}

void func_0c0d56e0(struct Actor *a, unsigned char *state)
{
    struct LinkedActorVec3 position;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b7++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        state[8] = 0;
        state[9] = 0;
        if (dat_0c2f6830 < 4) {
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            func_0c0437b8(a);
        } else {
            func_0c1646c0(a, 3);
            func_0c1646c0(a, 2);
            func_0c1646c0(a, 1);
            func_0c1646c0(a, 0);
            position.x = -1.66666663f;
            position.y = 130.71428f;
            position.z = 0.0f;
            func_0c0429a4(a, &position, 1);
        }
    }
}
