/* Interpolate a short effect, copy its placement, and clamp a later bounce. */
#include "objects.h"
extern struct EffectKnot dat_0c261004[],dat_0c261014[],dat_0c26102c[],dat_0c26103c[];
extern struct ActorGlobalRoot *dat_0c2d9650;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c037688(struct Obj_tu5_03 *),func_0c1d975e(struct Obj_tu5_03 *);
extern float func_0c1ce8c4(void *,unsigned char *,int);
void func_0c1d205c(struct Obj_tu5_03 *a)
{
 if(a->w28>=9) {func_0c037688(a);return;}
 a->f80=func_0c1ce8c4(dat_0c261004,&a->b4,a->w28);
 a->f84=func_0c1ce8c4(dat_0c261014,(unsigned char *)&a->b5,a->w28);
 a->f88=func_0c1ce8c4(dat_0c26102c,&a->b6,a->w28);
 a->f120=func_0c1ce8c4(dat_0c26103c,&a->b7,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d20d6(struct Vec3_tu5_03 *position)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0) {
  a->b12c=1;a->p16=func_0c1d205c;
  a->l84=(*(int (*)[88])dat_0c2d9650->p0)[81];a->lcc=17;
  a->pos=*position;
 }
}
void func_0c1d211e(struct Obj_tu5_03 *a)
{
 func_0c1d975e(a);
 if(a->pos.y<0.0f) {a->f96*=-0.5f;a->pos.y=0.0f;}
 if(++a->w28>=60)func_0c037688(a);
}
