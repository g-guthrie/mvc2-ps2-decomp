#include "objects.h"
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct Vec3_tu5_03 dat_0c23333c[];
extern int dat_0c233334[];
extern float dat_0c233354[];
extern float func_0c1ec2c0(int);
void func_0c1e60f8(int);
void func_0c1e6154(struct Obj_tu5_03 *);
void func_0c1e60dc(void)
{
 int i;
 for(i=0;i<2;i++) func_0c1e60f8(i);
}
void func_0c1e60f8(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0) {
  a->b12c=1;
  a->p16=func_0c1e6154;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[n+23];
  a->lcc=0x801;
  a->pos=dat_0c23333c[n];
  a->b32=n;
 }
}
void func_0c1e6154(register struct Obj_tu5_03 *a)
{
 const float angle=360.0f;
 a->pos.x=dat_0c23333c[a->b32].x+func_0c1ec2c0((int)(a->w28*angle/dat_0c233334[a->b32]*65536.0f/angle+0.5f)&65535)*100.0f;
 a->pos.y=dat_0c23333c[a->b32].y+dat_0c233354[a->b32]*a->w28/dat_0c233334[a->b32];
 a->w28++;
 if(a->w28>=dat_0c233334[a->b32]) a->w28=0;
}
