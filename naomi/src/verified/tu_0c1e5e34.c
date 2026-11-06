#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c233328;
void func_0c1e5e94(struct Obj_tu5_03 *);
void func_0c1e5e34(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0, 5, 1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e5e94;
        a->l84 = dat_0c2d964c->p0->entries[5].value;
        a->lcc = 0xc11;
        a->pos = *v;
        *(struct Vec3_tu5_03 *)&a->f80 = dat_0c233328;
        a->f120 = a->f124 = a->f128 = 1.0f;
    }
}
void func_0c1e5e94(struct Obj_tu5_03 *a)
{
    a->f80 += 1.0f;
    a->f88 += 1.0f;
    a->f124 = a->f128 = (a->f120 -= 0.05000000075f);
    if (a->f120 <= 0.0f) func_0c037688(a);
}
