/* Rotating stage-object effects: spawners and per-frame angle updaters sharing literal pools. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2632a0[],dat_0c2632c0[],dat_0c2632e0,dat_0c2632ec;
extern int dat_0c2632b8[],dat_0c2632d8[];
extern float func_0c1ec2c0(int);
void func_0c1e2138(struct Obj_tu5_03 *a)
{
 switch(a->b4){
 case 0:
  a->w28++;
  if(a->w28>=1440)a->w28=0;
  switch(a->b32){
  case 0:a->angles.array[0]=(int)(a->w28/2.0*65536.0/360.0+0.5)&65535;break;
  case 1:a->angles.array[0]=(int)(a->w28/4.0*65536.0/360.0+0.5)&65535;break;
  }
  break;
 }
}
void func_0c1e21ba(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e2138;
  a->l84=(*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n])[1];
  a->lcc=0x807;a->pos=dat_0c2632a0[n];a->angles.scalar.l44=dat_0c2632b8[n];a->b32=n;
 }
}

void func_0c1e23da(struct Obj_tu5_03 *);
void func_0c1e2254(struct Obj_tu5_03 *a)
{
 switch(a->b4){
 case 0:
  a->w28+=2;
  if(a->w28>=360)a->w28=0;
  {float degrees=360.0f;register float half=0.5f;
  a->angles.array[0]=(int)(func_0c1ec2c0((int)(a->w28*65536.0f/degrees+half)&65535)*2949120.0f/degrees+half)&65535;
  }
  break;
 }
}
void func_0c1e22c6(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e2254;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[3];a->lcc=0x807;
  a->pos=dat_0c2632c0[n];a->angles.scalar.l44=dat_0c2632d8[n];a->w28=(short)n*180;
  func_0c1e23da(a);
 }
}
void func_0c1e2368(struct Obj_tu5_03 *a)
{
 switch(a->b4){
 case 0:
  a->w28+=3;
  if(a->w28>=360)a->w28=0;
  {float degrees=360.0f;register float half=0.5f;
  a->angles.array[0]=(int)(func_0c1ec2c0((int)(a->w28*65536.0f/degrees+half)&65535)*1310720.0f/degrees+half)&65535;
  }
  break;
 }
}
void func_0c1e23da(struct Obj_tu5_03 *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e2368;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[7];a->lcc=0x803;
  a->p200=&parent->f136;
 }
}
void func_0c1e241e(struct Obj_tu5_03 *a)
{
 switch(a->b4){
 case 0:
  a->w28++;
  if(a->w28>=360)a->w28=0;
  {float units=65536.0f,degrees=360.0f;register float half=0.5f;
  a->angles.array[0]=(int)((-90.0f+func_0c1ec2c0((int)(a->w28*units/degrees+half)&65535)*45.0f)*units/degrees+half)&65535;
  }
  break;
 }
}

void func_0c1e24d8(void)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0) {
  a->b12c=1;a->p16=func_0c1e241e;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[6];a->lcc=0x80f;
  a->pos=dat_0c2632e0;
  {int mask=65535;
   struct Vec3_tu5_03 *rotation=&dat_0c2632ec;
   a->angles.array[0]=(int)(rotation->x*65536.0/360.0+0.5)&mask;
   a->angles.scalar.l44=(int)(rotation->y*65536.0/360.0+0.5)&mask;
   a->angles.scalar.l48=(int)(rotation->z*65536.0/360.0+0.5)&mask;
  }
 }
}
void func_0c1e2564(void)
{
 int i;
 for(i=0;i<2;i++)func_0c1e21ba(i);
 for(i=0;i<2;i++)func_0c1e22c6(i);
 func_0c1e24d8();
}
