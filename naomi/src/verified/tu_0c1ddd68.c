#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c1dde40(struct Obj_tu5_03 *);
void func_0c1ddd68(int);
void func_0c1de058(struct Obj_tu5_03 *);
extern void func_0c1ddb80(struct Obj_tu5_03 *);
extern void (*table_0c262318[])(struct Obj_tu5_03 *);
extern struct Vec3_tu5_03 dat_0c233098[];
extern struct Vec3_tu5_03 dat_0c2330b0[];
extern struct Vec3_tu5_03 dat_0c2fb628[];
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2330c8;
extern struct Vec3_tu5_03 dat_0c2330d4[];
void func_0c1ddf38(struct Obj_tu5_03 *);
void func_0c1ddd68(int unused)
{
 int i;
 for(i=0;i<2;i++){
  struct Obj_tu5_03 *a;
  if(!(a=func_0c0374da(0,5,1)))break;
  a->b12c=1;
  a->p16=func_0c1ddb80;
  a->l84=(int)((void **)dat_0c2d964c->p0)[39];
  a->lcc=0x0807;
  a->pos=dat_0c233098[i];
  a->angles.array[0]=(int)(dat_0c2330b0[i].x*65536.0f/360.0f+0.5f)&65535;
  a->angles.array[1]=(int)(dat_0c2330b0[i].y*65536.0f/360.0f+0.5f)&65535;
  a->angles.array[2]=(int)(dat_0c2330b0[i].z*65536.0f/360.0f+0.5f)&65535;
  a->b35=i;
  a->b5=i;
  func_0c1de058(a);
 }
}
void func_0c1dde40(struct Obj_tu5_03 *a)
{
 table_0c262318[a->b4](a);
 return;
}
void func_0c1dde88(struct Obj_tu5_03 *a)
{
 float duration;
 *(struct Vec3_tu5_03 *)&a->f92=dat_0c2330d4[(unsigned char)a->b5];
 a->b5=a->b5+1;
 a->b5 &= 1;
 *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c2330d4[(unsigned char)a->b5];
 duration=100.0f;
 dat_0c2fb628[a->b35].x=(a->f104-a->f92)/duration;
 dat_0c2fb628[a->b35].y=(a->f108-a->f96)/duration;
 dat_0c2fb628[a->b35].z=(a->f112-a->f100)/duration;
 a->b4=1;
 func_0c1ddf38(a);
 return;
}
void func_0c1ddf38(struct Obj_tu5_03 *a)
{
 a->w28++;
 if(a->w28>100){a->b4=0;a->w28=0;return;}
 a->angles.array[0]=(int)(a->f92*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[1]=(int)(a->f96*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[2]=(int)(a->f100*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[0]+=(int)(dat_0c2fb628[a->b35].x*a->w28*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[1]+=(int)(dat_0c2fb628[a->b35].y*a->w28*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[2]+=(int)(dat_0c2fb628[a->b35].z*a->w28*65536.0f/360.0f+0.5f)&65535;
}
void func_0c1de058(struct Obj_tu5_03 *owner)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))){
  a->b12c=1;
  a->p16=func_0c1dde40;
  a->l84=(int)((void **)dat_0c2d964c->p0)[40];
  a->lcc=0x0803;
  a->pos=dat_0c2330c8;
  a->angles.array[0]=(int)(dat_0c2330d4[0].x*65536.0f/360.0f+0.5f)&65535;
  a->angles.array[1]=(int)(dat_0c2330d4[0].y*65536.0f/360.0f+0.5f)&65535;
  a->p20=owner;
  a->p200=&owner->f136;
  a->b5=owner->b5;
  a->b35=owner->b35;
 }
}
void func_0c1de0ea(void)
{
 func_0c1ddd68(39);
}
