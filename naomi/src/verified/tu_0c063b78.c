#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
struct ActorSubByte27 { unsigned char pad[27], b27; };
extern ActorHandler table_0c240204[];
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c03489c(struct Actor *);
void func_0c063b78(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    struct LinkedActorVec3 position;
    if (a->w1fa & 0x400) { a->b1d2 = a->b1d2 ^ 1; a->w130 = a->w130 ^ 1; }
    func_0c025900(a, 5, 5);
    a->b1a0 = 10;
    a->b6 = 0;
    position.x = -53.3333321f;
    position.y = 137.142853f;
    func_0c1d4610(a, &position);
    ((struct ActorSubByte27 *)sub)->b27 = 0;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 7);
}
void func_0c063bf8(void) {}
void func_0c063bfc(struct Actor *a)
{
    a->b1ea = 1;
    table_0c240204[a->b1f7 & 63](a);
}
void func_0c063c1a(struct Actor *a)
{
    struct Actor *c;
    if (func_0c02a026(a) < 0) {
        a->w130 = a->w130 ^ 1;
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        c = a->p1c8;
        c->p1b4 = a;
        c->b1f6 = 1;
        c->b1f9 = 2;
        c->b1a1 = 32;
        c->b1d2 = a->b1d2;
        func_0c025900(a, 0, 0);
        func_0c03489c(a);
    }
}
