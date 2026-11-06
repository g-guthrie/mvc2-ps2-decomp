/* Two linked-piece spawners sharing the piece callback, plus the owner dispatcher. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
#define PFX(p) ((struct LinkedActorPrefix12c *)&(p)->sdc.b12c)
typedef void (*Handler_1a94b0)(struct LinkedActor *);
extern struct LinkedActor *func_0c0374da(int, int, int);
extern Handler_1a94b0 table_0c259620[], table_0c259634[];
extern char dat_0c22a81c[];
struct Count2a6_1a94b0 { unsigned char pad[0x2a6]; char b2a6; };
struct Pos52_1a94b0 { unsigned char pad[52]; struct LinkedActorVec3 v52; };
#define CNT(p) (((struct Count2a6_1a94b0 *)(p))->b2a6)
void func_0c1a95be(struct LinkedActor *a);

struct LinkedActor *func_0c1a94b0(struct LinkedActor *owner, char mode)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c1a95be;
        a->p24 = owner;
        a->b32 = mode;
        a->w38 = 0x1a00;
        a->s30 = owner->sdc.w158.short_value;
    }
    return a;
}

void func_0c1a94f2(struct LinkedActor *owner, struct LinkedActorVec3 *pos, char mode)
{
    struct LinkedActor *a;
    if (CNT(owner) > 5)
        return;
    if ((a = func_0c0374da(0, 4, 0)) == 0)
        return;
    a->p16 = func_0c1a95be;
    a->p24 = owner;
    a->sdc = owner->sdc;
    a->sdc.b12c = 1;
    a->b2 = owner->b2;
    a->b1 = owner->b1;
    a->v80.x = owner->v80.x;
    a->v80.y = owner->v80.y;
    a->b1a3 = owner->b1a3;
    a->b1a4 = owner->b1a4;
    a->b48 = owner->b48;
    a->v80 = owner->v80;
    a->b36 = owner->b36;
    A(a)->f264 = 1.0f;
    PFX(a)->b12d = -1;
    PFX(a)->w12e = dat_0c22a81c[owner->b1a4];
    a->sdc.b12c = 0;
    a->b32 = 1;
    a->b33 = mode;
    ((struct Pos52_1a94b0 *)a)->v52 = *pos;
    a->w38 = 0x1a00;
    CNT(owner)++;
}

void func_0c1a95be(struct LinkedActor *a)
{
    table_0c259620[a->b32](a);
}

void func_0c1a95d2(struct LinkedActor *a)
{
    table_0c259634[a->b4](a);
}
