#include "objects.h"
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0786e0(struct Actor *a)
{
    struct ActorSub2a4Extended *sub;
    if (a->b255 == 6) { a->b3f0 = 255; a->b3f1 = 16; }
    a->b6++;
    func_0c0442fa(a);
    func_0c02a0c4(a, 21, 15);
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    sub = (struct ActorSub2a4Extended *)&a->sub2a4;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    sub->base.b20 = 0;
    sub->b40 = 0;
    a->s28 = 80;
    a->s30 = 0;
    if (!a->b1f9) func_0c0432ca(a);
}
void func_0c078778(struct Actor *a)
{
    struct LinkedActorVec3 position;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    if (a->b141) {
        a->b6++;
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b141 = 0;
        func_0c0344a0(a, 23);
        position.x = -13.33333302f;
        position.y = 222.857132f;
        position.z = 0;
        func_0c0429a4(a, &position, 1);
    }
    func_0c02a026(a);
}
