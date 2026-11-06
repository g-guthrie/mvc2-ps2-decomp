/* Knockback setup that mirrors the push velocity when facing left, an empty handler and the b1f7 dispatcher. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24d740[];
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);

extern void func_0c048ce6(struct Actor *), func_0c02a0c4(struct Actor *, int, int), func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
void func_0c1250d8(struct Actor *a)
{
    struct ActorSub2a4 *s = &a->sub2a4;
    struct LinkedActorVec3 v;

    if (a->b34 & 1) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 18);
    s->b20 = 0;
    a->f96 = 0;
    a->f108 = 0;
    a->f92 = -15.0f;
    a->f104 = -0.20833333f;
    if (a->w130) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    v.x = -20.0f;
    v.y = 184.28571f;
    v.z = 0;
    func_0c1d4610(a, &v);
}

void func_0c125178(void) {}

void func_0c12517c(struct Actor *a)
{
    table_0c24d740[a->b1f7&63](a);
}
