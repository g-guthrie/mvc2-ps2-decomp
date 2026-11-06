#include "objects.h"

extern struct LinkedActor *func_0c0374da(int, int, int);
extern void (*const table_0c25af88[])(struct LinkedActor *);
void func_0c1b3852(struct LinkedActor *);

struct LinkedActor *func_0c1b37a0(struct LinkedActor *parent)
{
    struct LinkedActor *p;
    int flags = 0x2701;
    if ((p = func_0c0374da(0, 3, 0)) != 0) {
        p->p16 = func_0c1b3852;
        p->p24 = parent;
        p->w38 = flags;
        p->b32 = 0;
    }
    if ((p = func_0c0374da(0, 3, 0)) != 0) {
        p->p16 = func_0c1b3852;
        p->p24 = parent;
        p->w38 = flags;
        p->b32 = 1;
    }
    if ((p = func_0c0374da(0, 3, 0)) != 0) {
        p->p16 = func_0c1b3852;
        p->p24 = parent;
        p->w38 = flags;
        p->b32 = 2;
    }
    if ((p = func_0c0374da(0, 3, 0)) != 0) {
        p->p16 = func_0c1b3852;
        p->p24 = parent;
        p->w38 = flags;
        p->b32 = 3;
    }
    if ((p = func_0c0374da(0, 3, 0)) != 0) {
        p->p16 = func_0c1b3852;
        p->p24 = parent;
        p->w38 = flags;
        p->b32 = 4;
    }
    return p;
}

void func_0c1b3852(struct LinkedActor *a)
{
    table_0c25af88[a->b4](a);
}
