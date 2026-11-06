#include "objects.h"

extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern void func_0c1d09da(struct Obj_tu5_03 *);

void func_0c1d0a8c(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *p;
    if ((p = func_0c0374da(0, 8, 1)) != 0) {
        p->b12c = 0;
        p->p16 = func_0c1d09da;
        p->pos = *v;
    }
}
