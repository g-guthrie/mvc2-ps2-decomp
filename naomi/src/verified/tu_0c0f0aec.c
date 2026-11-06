#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24a004[];
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0f0aec(struct Actor *a)
{
    struct LinkedActorVec3 position;
    struct Actor *linked;

    a->b1a0 = 10;
    if (a->b34 & 2) {
        a->b1d2 = a->w130 = a->b1d2 ^ 1;
        linked = a->p1c8;
        linked->b1d2 = linked->w130 = a->b1d2 ^ 1;
    }
    position.x = -120.0f;
    position.y = 171.42856f;
    position.z = 0.0f;
    func_0c1d4610(a, &position);
    func_0c02a0c4(a, 15, 0);
}

void func_0c0f0b5e(struct Actor *a)
{
    struct LinkedActorVec3 position;
    struct Actor *linked;

    a->b1a0 = 10;
    if (a->b34 & 1) {
        a->b1d2 = a->w130 = a->b1d2 ^ 1;
        linked = a->p1c8;
        linked->b1d2 = linked->w130 = a->b1d2 ^ 1;
    }
    position.x = 53.3333321f;
    position.y = 274.28571f;
    position.z = 0.0f;
    func_0c1d4610(a, &position);
    func_0c02a0c4(a, 15, 1);
}

void func_0c0f0bd0(struct Actor *a)
{
    a->b1ea = 1;
    table_0c24a004[a->b1f7 & 63](a);
}
