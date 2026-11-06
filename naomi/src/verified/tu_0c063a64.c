#include "objects.h"
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c063a64(struct Actor *a)
{
    struct LinkedActorVec3 position;
    if (a->w1fa & 0x400) { a->b1d2 = a->b1d2 ^ 1; a->w130 = a->w130 ^ 1; }
    a->b1a0 = 10;
    a->b6 = 0;
    func_0c025900(a, 5, 5);
    position.x = -53.3333321f;
    position.y = 137.142853f;
    func_0c1d4610(a, &position);
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 0);
}
void func_0c063ad2(struct Actor *a)
{
    struct LinkedActorVec3 position;
    a->b1a0 = 10;
    a->b6 = 0;
    position.x = -53.3333321f;
    position.y = 137.142853f;
    func_0c1d4610(a, &position);
    func_0c02a0c4(a, 15, 1);
}
void func_0c063b0c(struct Actor *a)
{
    struct LinkedActorVec3 position;
    a->b1a0 = 10;
    a->b6 = 0;
    position.x = -53.3333321f;
    position.y = 137.142853f;
    func_0c1d4610(a, &position);
    func_0c025900(a, 5, 5);
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 8);
}
