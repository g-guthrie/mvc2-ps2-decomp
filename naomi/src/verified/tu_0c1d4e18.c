/* Exact 0x0c1d4e18..0x0c1d501c update group: five functions, both pools.
 * Angle-array compound addition retains the native accumulator register.
 */
#include "objects.h"
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern float dat_0c261558[],dat_0c2615ac[],dat_0c2615dc[];
extern int dat_0c26160c[],dat_0c261638[],dat_0c261664[];
void func_0c1d4e18(struct Obj_tu5_03 *a)
{
 if(a->w28>20){func_0c037688(a);return;}
 if(a->w28<8)a->pos.y-=6.0f;
 a->f120=dat_0c261558[a->w28];a->f124=dat_0c261558[a->w28];a->f128=dat_0c261558[a->w28];
 a->w28++;
}
void func_0c1d4e64(struct Obj_tu5_03 *a)
{
 if(a->w28<7){a->w28++;return;}
 if(a->w30>10){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[170];
 a->f120=dat_0c2615ac[a->w28];a->f124=dat_0c2615ac[a->w28];a->f128=dat_0c2615ac[a->w28];
 a->f80+=0.1363636405f;a->f88+=0.1363636405f;a->f84-=0.0454545469f;
 a->angles.array[1]+=(a->b33?2979:-2979);
 a->w30++;
}
void func_0c1d4ef6(struct Obj_tu5_03 *a)
{
 if(a->w28<9){a->w28++;return;}
 if(a->w30>10){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[dat_0c26160c[a->w30]];
 a->f116=dat_0c2615dc[a->w30];a->w30++;
}
void func_0c1d4f40(struct Obj_tu5_03 *a)
{
 if(a->w28<9){a->w28++;return;}
 if(a->w30>10){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[dat_0c261638[a->w30]];
 a->f116=dat_0c2615dc[a->w30];a->w30++;
}
void func_0c1d4fba(struct Obj_tu5_03 *a)
{
 if(a->w28<9){a->w28++;return;}
 if(a->w30>10){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[dat_0c261664[a->w30]];
 a->f116=dat_0c2615dc[a->w30];a->w30++;
}
