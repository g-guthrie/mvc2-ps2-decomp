#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c1e3afc(struct Obj_tu5_03 *),func_0c1d975e(struct Obj_tu5_03 *),func_0c037688(struct Obj_tu5_03 *);
extern void func_0c1ce660(struct Vec3_tu5_03 *,int);
extern int dat_0c264590[];
extern const float dat_0c2645cc;
extern float dat_0c2645a4[][2];
extern struct Vec3_tu5_03 dat_0c2645dc;
extern float func_0c1ec2c0(int),func_0c1ebd40(int);
void func_0c1e3d42(struct Obj_tu5_03 *);
void func_0c1e3cec(struct Vec3_tu5_03 *position,int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e3afc;
  a->l84=(*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n])[1];
  a->lcc=0x80b;a->b32=n;a->pos=*position;
 }
}
void func_0c1e3d42(struct Obj_tu5_03 *a)
{
 double degrees=360.0;
 double half=0.5;
 double units=65536.0;
 register float zero=0.0f;
 switch(a->b4){
 case 0:
  a->b4++;
  a->f92=dat_0c2645cc*func_0c1ec2c0((int)(dat_0c264590[a->b32]*units/degrees+half)&65535);
  a->f96=zero;
  a->f100=dat_0c2645cc*func_0c1ebd40((int)(dat_0c264590[a->b32]*units/degrees+half)&65535);
  *(struct Vec3_tu5_03 *)&a->f104=dat_0c2645dc;
  break;
 case 1:
  a->b4++;func_0c1ce660(&a->pos,1);break;
 case 2:
  func_0c1d975e(a);
  a->angles.array[0]+=(int)(dat_0c2645a4[a->b32][0]*units/degrees+half)&65535;
  a->angles.scalar.l48=a->angles.scalar.l48+((int)(dat_0c2645a4[a->b32][1]*units/degrees+half)&65535u);
  if(a->pos.x>-250.0f && a->pos.x<250.0f){
   if(a->pos.y>300.0f)break;
   a->pos.y=300.0f;
  }else{
   if(a->pos.y>zero)break;
   a->pos.y=zero;
  }
  a->f96*=-0.3000000120f;
  if(++a->w28>2){a->b4++;a->w28=0;}
  break;
 case 3:
  if(++a->w28>=15)func_0c037688(a);
  break;
 }
}
void func_0c1e3f28(struct Vec3_tu5_03 *position,int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e3d42;
  a->l84=(*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n])[42];
  a->lcc=0x80b;a->b32=n;a->pos=*position;
 }
}
