/* Apply gravity and restart the two actors on the input edge. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2329e8[];
extern float dat_0c232a00[];
extern int func_0c038fdc(int);
void func_0c1da918(struct Obj_tu5_03 *a)
{
 switch(a->b4) {
 case 0:
  {
  a->f96+=-4.0f;
  a->pos.y+=a->f96;
  if(a->pos.y<dat_0c2329e8[a->b32].y) {
   a->pos.y=dat_0c2329e8[a->b32].y;
   a->f96=0.0f;
   if(a->w28!=0)a->w28=0;
  }
  if(func_0c038fdc(0)) {
   a->f96=dat_0c232a00[a->b32];
   a->w28=1;
  }
  }
  break;
 }
}
void func_0c1da9ac(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0) {
  a->b12c=1;a->p16=func_0c1da918;
  a->l84=(*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n])[12];
  a->lcc=0x801;
  a->pos=dat_0c2329e8[n];a->b32=n;
 }
}
void func_0c1daa06(void)
{
 int i;
 for(i=0;i<2;i++)func_0c1da9ac(i);
}
