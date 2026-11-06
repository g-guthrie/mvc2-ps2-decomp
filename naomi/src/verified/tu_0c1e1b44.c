#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2332e4;
void func_0c1e1b96(struct Obj_tu5_03 *);
void func_0c1e1b44(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0, 5, 1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e1b96;
        a->l84 = dat_0c2d964c->p0->entries[5].value;
        a->lcc = 0x811;
        a->pos = *v;
        *(struct Vec3_tu5_03 *)&a->f80 = dat_0c2332e4;
    }
}
void func_0c1e1b96(struct Obj_tu5_03 *a)
{
    switch (a->b4) {
    case 0:
        a->b4++;
        a->w30 = 120;
        break;
    case 1:
        a->f80 += 0.1000000015f;
        a->f88 += 0.1000000015f;
        if (++a->w28 >= a->w30) func_0c037688(a);
        break;
    }
}
