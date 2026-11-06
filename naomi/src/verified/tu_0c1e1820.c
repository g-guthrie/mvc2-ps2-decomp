#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern int func_0c1d91a8(int),func_0c1d8ff8(int,int),func_0c1d901e(void);
extern int func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(struct Vec3_tu5_03 *);
extern int func_0c1d912a(int *,float *),func_0c1d917e(int *,float *);
extern float func_0c1ec2c0(int);
void func_0c1e1862(struct Obj_tu5_03 *);
void func_0c1e1820(void)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e1862;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[1];
  a->lcc=0x801;func_0c1d91a8(a->l84);
 }
}
void func_0c1e1862(register struct Obj_tu5_03 *a)
{
 float value; int first; struct Vec3_tu5_03 point;
 switch(a->b4){
 case 0:{
  int phase;
  if(++a->w28>=360)a->w28=0;
  if(++a->w30>=2000)a->w30=0;
  phase=0;
  func_0c1d8ff8((*(int (*)[36])dat_0c2d964c->p0)[2],a->l84);
  {
  while(func_0c1d901e()==0){
   func_0c1d9100(&point);
   point.y=-53.5999985f+func_0c1ec2c0((int)((a->w28+phase)*65536.0/360.0+0.5)&65535)*10.0f;
   func_0c1d914c(&point);
   phase+=30;
   func_0c1d912a(&first,&value);
   value+=a->w30*0.000500000024f;
   func_0c1d917e(&first,&value);
  }
  } break;
 }
 default:break;
 }
}
