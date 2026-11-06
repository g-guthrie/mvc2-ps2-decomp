#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2625d4[],dat_0c2625ec[],dat_0c2625bc,dat_0c2625c8;
extern float dat_0c26261c[],dat_0c262624[];
extern float func_0c1ec2c0(int);
extern void func_0c1e06a0(struct Obj_tu5_03 *);
void func_0c1e05dc(void);
void func_0c1e03b4(struct Obj_tu5_03 *);
struct AngleWindow {struct Vec3_tu5_03 start,neighbor,end;};
void func_0c1e0310(void){func_0c1e05dc();}
void func_0c1e0314(int n,struct Obj_tu5_03 *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e03b4;
  a->l84=(*(int (*)[36])&(*(union ActorGlobalEntry (*)[36])dat_0c2d964c->p0)[n*2])[4];
  a->pos=dat_0c2625d4[n];
  a->angles.scalar.l44=(int)(dat_0c2625ec[n].y*65536.0/360.0+0.5)&65535;
  a->angles.scalar.l48=(int)(dat_0c2625ec[n].z*65536.0/360.0+0.5)&65535;
  a->lcc=0x80d;a->b32=n;a->p20=parent;
 }
}
void func_0c1e03b4(struct Obj_tu5_03 *a)
{
 double degrees=360.0; double half=0.5; double units=65536.0;
 switch(a->b4){
 case 0:
  if(a->p20->w30)break;
  {int state=a->p20->b4;
   if(state==2)goto advance;
   if(state!=a->b32)break;
   goto advance;
  }
  break;
 case 1:
  a->angles.scalar.l44=a->angles.scalar.l44+((int)(dat_0c26261c[a->b32]*units/degrees+half)&65535);
  a->w28++;
  if(a->w28>=20)goto reset_angle;
  break;
 case 2:
  a->angles.scalar.l44=(int)((((struct AngleWindow *)&dat_0c2625ec[a->b32])->end.y+
   ((60-a->w28)/60.0f)*func_0c1ec2c0((int)((a->w28*36)*units/degrees+half)&65535)*10.0f)*units/degrees+half)&65535;
  a->w28++;
  if(a->w28>=60){
reset_angle:
   a->b4++;a->w28=0;
   a->angles.scalar.l44=(int)(((struct AngleWindow *)&dat_0c2625ec[a->b32])->end.y*units/degrees+half)&65535;
  }
  break;
 case 3:
  a->w28++;
  if(a->w28>=60){
advance:
   a->b4++;a->w28=0;
  }
  break;
 case 4:
  a->angles.scalar.l44=a->angles.scalar.l44+((int)(dat_0c262624[a->b32]*units/degrees+half)&65535);
  a->w28++;
  if(a->w28>=100){
   a->w28=0;a->b4=0;
   a->angles.scalar.l44=(int)(dat_0c2625ec[a->b32].y*units/degrees+half)&65535;
  }
  break;
 }
}
void func_0c1e05dc(void)
{
 struct Obj_tu5_03 *a;int i;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e06a0;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[26];a->pos=dat_0c2625bc;
  a->angles.array[0]=(int)(dat_0c2625c8.x*65536.0/360.0+0.5)&65535;
  a->angles.scalar.l44=(int)(dat_0c2625c8.y*65536.0/360.0+0.5)&65535;
  a->lcc=0xc07;
  for(i=0;i<2;i++)func_0c1e0314(i,a);
 }
}
