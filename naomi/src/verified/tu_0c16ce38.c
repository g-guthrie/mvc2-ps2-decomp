/* Full 124-byte linked-actor spawner extent, with three interior pools. */
#include "objects.h"

typedef void (*LinkedActorPairHandler)(struct LinkedActor *, struct LinkedActor *);
typedef struct LinkedActor *(*LinkedActorAllocator)(int, int, int);

extern struct LinkedActor *func_0c0374da(int, int, int);
extern LinkedActorPairHandler dat_0c25238c[];

void func_0c16ce8c(struct LinkedActor *p);

struct LinkedActor *func_0c16ce38(struct LinkedActor *parent)
{
    register short i;
    struct LinkedActor *owner;
    unsigned short size;
    LinkedActorAllocator alloc;
    struct LinkedActor *child;

    i = 7;
    owner = parent;
    size = 0x2a00;
    alloc = func_0c0374da;
    do {
        if ((child = alloc(0, 1, 0)) != 0) {
            child->p16 = func_0c16ce8c;
            child->p24 = owner;
            child->b1 = owner->b1;
            child->b33 = i;
            child->w38 = size;
            child->wcc.dword_value = (unsigned short)owner->sdc.w158.short_value;
        }
    } while (--i >= 0);
    return child;
}

void func_0c16ce8c(struct LinkedActor *p)
{
    dat_0c25238c[p->b4](p, p->p24);
}
