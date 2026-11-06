#include "objects.h"
extern int dat_0c2d9610;
extern int dat_0c264724;
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
void func_0c1e565c(struct Obj_tu5_03 *a)
{
    switch (a->b4) {
    case 0:
        if (dat_0c2d9610 >= 2) a->b4++;
        break;
    case 1:
        a->f120 += 1.0f / dat_0c264724;
        a->f124 -= 1.0f / dat_0c264724;
        if (++a->w28 >= dat_0c264724) {
            a->b4 = 2;
            a->w28 = 0;
            a->f120 = 1.0f;
            a->f124 = 0.0f;
        }
        break;
    case 2: break;
    }
}
void func_0c1e56d0(void)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0,5,1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e565c;
        a->l84 = dat_0c2d964c->p0->entries[0].value;
        a->lcc = 0xc01;
        a->f120 = 0.0f;
        a->f124 = 1.0f;
        a->f128 = 0.0f;
    }
}
