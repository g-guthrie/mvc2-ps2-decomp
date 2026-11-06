#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct ActorFlags *dat_0c2d6f84;
extern struct Vec3_tu5_03 dat_0c2332f0;
extern unsigned char dat_0c2f833e;
extern int dat_0c2d9610;
extern int func_0c026a86(void);
extern void func_0c1d91a8(int);
extern int func_0c1d8ff8(int,int),func_0c1d901e(void);
extern int func_0c1d9100(float *),func_0c1d914c(float *),func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
extern float func_0c1ec2c0(int);
void func_0c1e58be(struct Obj_tu5_03 *);
void func_0c1e5860(void)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,8,1))!=0){
  a->b12c=1;a->p16=func_0c1e58be;
  a->l84=(*(int (*)[68])dat_0c2d964c->p0)[47];a->lcc=0xc01;
  a->pos=dat_0c2332f0;
  a->f120=0.0f;a->f124=0.0f;a->f128=0.0f;
  func_0c1d91a8(a->l84);
 }
}
void func_0c1e58be(register struct Obj_tu5_03 *a)
{
 float point[3],second,first;
 register float unit;
 a->b12c=1;
 if(dat_0c2d6f84->b98 || dat_0c2f833e || func_0c026a86()==2)a->b12c=0;
 unit=1.0f;
 switch(a->b4){
 case 0:
  a->f124+=0.00291666670f;
  if(a->f124>=0.6999999881f){a->b4++;a->f124=0.6999999881f;}
  break;
 case 1:if(dat_0c2d9610==2)a->b4++;break;
 case 2:
  a->f120+=0.00416666690f;a->f124-=0.00291666670f;
  if(a->f120>=unit){a->b4++;a->f120=unit;a->f124=0.0f;}
  break;
 case 3:break;
 }
 if(++a->w28>=200)a->w28=0;
 if(a->w30>=360)a->w30=0;
 a->w30+=10;
 func_0c1d8ff8((*(int (*)[68])dat_0c2d964c->p0)[48],a->l84);
 {
 register float half=0.5f,degrees=360.0f,drift=0.0049999999f;
 while(func_0c1d901e()==0){
  func_0c1d9100(point);
  if(point[1]>0.0f){
   point[1]=point[1]+func_0c1ec2c0((int)((a->w30+point[0]*10.0f)*65536.0f/degrees+half)&65535)*unit;
  }
  func_0c1d914c(point);
  func_0c1d912a(&first,&second);
  first+=a->w28*drift;
  func_0c1d917e(&first,&second);
 }
 }
}
