#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c262724[];
extern int dat_0c262730[];
void func_0c1e0bc0(struct Obj_tu5_03 *a)
{
    a->w28++;
    if (a->w28 >= 360) a->w28 = 0;
    a->angles.array[0] = (int)(a->w28 * 65536.0f / 360.0f + 0.5f) & 0xffff;
}
void func_0c1e0bfc(void)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0,5,1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e0bc0;
        a->l84 = dat_0c2d964c->p0->entries[1].value;
        a->lcc = 0x807;
        a->pos = dat_0c262724[0];
        a->angles.scalar.l44 = dat_0c262730[0];
    }
}
