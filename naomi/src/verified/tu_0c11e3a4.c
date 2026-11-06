/* Two reviewed position and opponent-orientation callbacks, 312 bytes. */
#include "objects.h"
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1bfa20(struct Actor *), func_0c1bac7c(struct Actor *, int);
void func_0c11e3a4(struct Actor *a)
{
    struct LinkedActorVec3 position;
    if (a->b34 & 1) {
        a->b1d2 = a->w130 = (unsigned char)a->b1d2 ^ 1;
        a->p1c8->b1d2 = a->p1c8->w130 = (unsigned char)a->p1c8->b1d2 ^ 1;
    }
    position.x = -106.666664124f;
    position.y = 205.71428f;
    func_0c1d4610(a, &position);
    a->b1a0 = 10;
    func_0c02a684(a, 1, 11, 1);
    func_0c02a0c4(a, 15, 0);
}
void func_0c11e41c(struct Actor *a)
{
    struct LinkedActorVec3 position;
    if (a->b34 & 1) {
        a->b1d2 = a->w130 = (unsigned char)a->b1d2 ^ 1;
        a->p1c8->b1d2 = a->p1c8->w130 = (unsigned char)a->p1c8->b1d2 ^ 1;
    }
    position.x = -106.666664124f;
    position.y = 205.71428f;
    func_0c1d4610(a, &position);
    a->b1a0 = 10;
    func_0c02a684(a, 1, 5, 1);
    a->p1c8->pad220[10] = 3;
    a->p1c8->pad220[8] = 3;
    func_0c1bfa20(a->p1c8);
    func_0c1bac7c(a, 1);
    func_0c02a0c4(a, 15, 2);
}
