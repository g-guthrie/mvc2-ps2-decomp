/* Resource construction followed by delayed activation. */
#include "objects.h"

extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern struct ActorGlobalRoot *dat_0c2d967c;
extern void func_0c1cd306(struct Obj_tu5_03 *);

void func_0c1cd2c0(int index)
{
    struct Obj_tu5_03 *q;

    if ((q = func_0c0374da(0, 11, 1)) != 0) {
        q->b12c = 0;
        q->b32 = index;
        q->p16 = func_0c1cd306;
        q->l84 = ((int *)dat_0c2d967c->p0)[index];
        q->lcc = 0;
        q->w28 = 0x1e0;
    }
}

void func_0c1cd306(struct Obj_tu5_03 *a)
{
    if (a->w28 != 0) {
        a->w28 = a->w28 - 1;
        return;
    }
    a->b12c = 1;
}
