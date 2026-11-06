/* Full 132-byte linked-actor spawn loop and dispatcher, with four pools. */
#include "objects.h"

typedef void (*LinkedActorSubHandler)(struct LinkedActor *, struct LinkedActor *, unsigned char *);

extern short dat_0c2f6830;
extern struct LinkedActor *func_0c0374da(int, int, int);
extern LinkedActorSubHandler dat_0c252778[];

void func_0c16fbe8(struct LinkedActor *p);

int func_0c16fb90(struct LinkedActor *parent)
{
    register int i;
    struct LinkedActor *child;

    if (dat_0c2f6830 <= 6)
        return 0;

    i = 0;
    do {
        if ((child = func_0c0374da(0, 1, 1)) != 0) {
            child->w38 = 0x2d00;
            ((unsigned char *)child)[0x20] = i;
            child->p16 = func_0c16fbe8;
            child->p24 = parent;
        }
    } while (++i < 6);
    return i;
}

void func_0c16fbe8(struct LinkedActor *p)
{
    struct LinkedActor *parent = p->p24;
    unsigned char *sub = (unsigned char *)parent + 0x2a4;

    dat_0c252778[p->b4](p, parent, sub);
}
