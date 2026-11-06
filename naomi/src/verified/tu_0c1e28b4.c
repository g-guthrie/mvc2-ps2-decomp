#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c263370;
extern int func_0c1d8ff8(int,int),func_0c1d901e(void);
extern int func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(struct Vec3_tu5_03 *);
extern float _builtin_fabsf(float);
extern float func_0c1ec2c0(int);
void func_0c1e2906(struct Obj_tu5_03 *);
void func_0c1e28b4(struct Obj_tu5_03 *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e2906;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[21];a->pos=dat_0c263370;
  a->angles.scalar.l44=0xe001;a->lcc=0x805;a->p24=parent;
 }
}
void func_0c1e2906(struct Obj_tu5_03 *a)
{
 struct Vec3_tu5_03 point;
 if(a->p24->b4>0){a->b12c=0;return;}
 {
  a->b12c=1;
  a->w28=a->w28+4;
  if(a->w28>=360)a->w28=0;
  func_0c1d8ff8((*(int (*)[36])dat_0c2d964c->p0)[22],a->l84);
  {int phase=0;
  while(func_0c1d901e()==0){
   func_0c1d9100(&point);
   if(point.y < -10.0f){
    point.z+=_builtin_fabsf(point.y)*_builtin_fabsf(point.y)*func_0c1ec2c0((int)((a->w28+phase)*65536.0/360.0+0.5)&65535)*0.000200000001f;
   }
   phase+=30;
   func_0c1d914c(&point);
  }
  }
 }
}
