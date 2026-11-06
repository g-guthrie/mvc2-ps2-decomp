#include "objects.h"

typedef void (*LinkedHandler)(struct LinkedActor *);
typedef void (*LinkedOwnerHandler)(struct LinkedActor *, struct LinkedActor *);
extern struct LinkedActor *func_0c0374da(int, int, int);
extern LinkedOwnerHandler table_0c25734c[];
extern LinkedHandler table_0c25735c[];
extern void func_0c029e70(struct LinkedActor *, int, int);

void func_0c18fa00(struct LinkedActor *);
void func_0c18fa1c(struct LinkedActor *);

struct LinkedActor *func_0c18f974(struct LinkedActor *owner, char mode)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0)
    {
        a->p16 = func_0c18fa00;
        a->p24 = owner;
        a->b1 = owner->b1;
        a->b32 = mode;
        a->b33 = 0;
        a->w38 = 0x0304;
    }
    return a;
}

struct LinkedActor *func_0c18f9ba(struct LinkedActor *source, char mode)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0)
    {
        a->p16 = func_0c18fa00;
        a->p24 = source->p24;
        a->p20 = source;
        a->b1 = source->b1;
        a->b32 = mode;
        a->b33 = 0;
        a->w38 = 0x0304;
    }
    return a;
}

void func_0c18fa00(struct LinkedActor *a)
{
    struct LinkedActor *owner = a->p24;
    a->b36 = owner->b36;
    table_0c25734c[a->b4](a, owner);
}

void func_0c18fa1c(struct LinkedActor *a)
{
    a->b4++;
    table_0c25735c[a->b32](a);
}

void func_0c18fa38(struct LinkedActor *a, struct LinkedActor *owner)
{
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
    a->sdc.w130 = owner->sdc.w130;
    a->f52 = owner->f52;
    a->f56 = owner->f56;
    func_0c029e70(a, 27, 2);
}
