#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c233308[];
extern float dat_0c233320[];
void func_0c1e5da8(struct Obj_tu5_03 *);
void func_0c1e5d4c(int);
void func_0c1e5d30(void)
{
 int i;
 for(i=0;i<2;i++)func_0c1e5d4c(i);
}
void func_0c1e5d4c(int n)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0,5,1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e5da8;
        a->l84 = (*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n])[37];
        a->lcc = 0x801;
        a->pos = dat_0c233308[n];
        a->b32 = n;
    }
}
void func_0c1e5da8(struct Obj_tu5_03 *a)
{
    int n = a->b32;
    a->pos.x = dat_0c233308[n].x + dat_0c233320[n] * a->w28 / 6000.0f;
    if (++a->w28 >= 6000) {
        a->w28 = 0;
        a->pos = dat_0c233308[a->b32];
    }
}
