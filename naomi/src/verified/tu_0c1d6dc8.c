#include "objects.h"
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern float dat_0c261714[],dat_0c2617b8[],dat_0c2618b4[];
extern int dat_0c26185c[];
void func_0c1d6dc8(struct Obj_tu5_03 *a)
{
 if(a->w28>40){func_0c037688(a);return;}
 a->f116=dat_0c261714[a->w28];a->w28++;
}
void func_0c1d6dea(struct Obj_tu5_03 *a)
{
 if(a->w28>40){func_0c037688(a);return;}
 if(a->w28>=28){a->f80+=0.416666656733f;a->f84-=0.163333341480f;}
 {float minimum=0.0199999995530f;if(a->f84<minimum)a->f84=minimum;}
 a->f116=dat_0c2617b8[a->w28];a->w28++;
}
void func_0c1d6e3e(struct Obj_tu5_03 *a)
{
 if(a->w28>=22){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[dat_0c26185c[a->w28]];
 a->f116=dat_0c2618b4[a->w28];a->w28++;
}
