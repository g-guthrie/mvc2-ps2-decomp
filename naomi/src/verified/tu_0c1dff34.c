/* Build twelve orbiting children around the parent actor. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2624cc[],dat_0c2624c0;
extern float func_0c1ebd40(int),func_0c1ec2c0(int);
void func_0c1dff34(struct Obj_tu5_03 *a){a->angles.array[0]-=16;}
void func_0c1dff40(struct Obj_tu5_03 *parent,int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0) {
  a->b12c=1;a->p16=func_0c1dff34;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[10];
  {int angle;
  float radius=2730.0f;
  a->pos.y=func_0c1ebd40(angle=(int)(n*30*65536.0/360.0+0.5)&65535)*radius;
  a->pos.z=func_0c1ec2c0(angle)*radius;
  {struct Vec3_tu5_03 *scale=&dat_0c2624cc[n];
   a->f120=scale->x;a->f124=scale->y;a->f128=scale->z;
  }
  a->lcc=0xc03;a->p200=&parent->f136;
  }
 }
}
void func_0c1dfff2(struct Obj_tu5_03 *a){a->angles.array[0]+=16;}
void func_0c1dfffe(void)
{
 struct Obj_tu5_03 *a;
 int i;
 if((a=func_0c0374da(0,5,1))!=0) {
  a->b12c=1;a->p16=func_0c1dfff2;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[9];
  a->pos=dat_0c2624c0;a->angles.scalar.l44=0x9b07;a->lcc=0x807;
  for(i=0;i<12;i++)func_0c1dff40(a,i);
 }
}
