#include "objects.h"
struct ScaleView {unsigned char pad[80];struct Vec3_tu5_03 scale;};
struct ActorKindView {unsigned char pad;unsigned char kind;};
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern int func_0c1ec190(void);
extern float func_0c1ec2c0(int),func_0c1ebd40(int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2616f4;
void func_0c1d605c(struct Obj_tu5_03 *a)
{
 int dx;
 a->pos=a->p20->pos;
 dx=(int)(a->p20->f80*13.3333330155f);
 if(!a->p20->w130)dx=-dx;
 a->pos.x=a->p20->pos.x+(short)dx;
 a->pos.y+=((struct Actor *)a->p20)->f84*222.857131959f;
 if(!((struct Actor *)a->p20)->b1a0){
  float degrees,half; register float scale;
  int mask;
  a->w28++;
  degrees=360.0f;half=0.5f;scale=65536.0f;mask=65535;
  a->angles.scalar.l44=(int)((a->w28+a->w30)*2*scale/degrees+half)&mask;
 a->angles.scalar.l48=(int)((a->w28+a->w30)*3*scale/degrees+half)&mask;
 }
 if(a->p20->b4)func_0c037688(a);
 if(((struct ActorKindView *)a->p20)->kind!=24)func_0c037688(a);
}
void func_0c1d6136(struct Actor *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1d605c;a->lcc=61;
  a->l84=(int)((void **)dat_0c2d964c->p0)[90];
  a->p20=(struct Obj_tu5_03 *)parent;a->f116=1.0f;
  ((struct ScaleView *)a)->scale=dat_0c2616f4;
 }
}
void func_0c1d61c4(register struct Obj_tu5_03 *a)
{
 int dx;
 a->pos=a->p20->pos;
 dx=(int)(a->p20->f80*13.3333330155f);
 if(!a->p20->w130)dx=-dx;
 a->pos.x=a->p20->pos.x+(short)dx;
 a->pos.y+=((struct Actor *)a->p20)->f84*222.857131959f;
 if(!((struct Actor *)a->p20)->b1a0){
  register float degrees,scale,half;
  register int mask;
  a->w28++;
  degrees=360.0f;mask=65535;scale=65536.0f;half=0.5f;
  a->angles.scalar.l44=(int)((a->w28+a->w30)*2*scale/degrees+half)&mask;
 a->angles.scalar.l48=(int)((a->w28+a->w30)*3*scale/degrees+half)&mask;
  a->f120=func_0c1ec2c0((int)((a->w28%360)*scale/degrees+half)&mask)*half+half;
  a->f124=func_0c1ebd40((int)((a->w28%360)*scale/degrees+half)&mask)*half+half;
 }
 if(a->p20->b4)func_0c037688(a);
 if(((struct ActorKindView *)a->p20)->kind!=24)func_0c037688(a);
}
void func_0c1d6348(struct Actor *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1d61c4;a->lcc=1053;
  a->l84=(int)((void **)dat_0c2d964c->p0)[88];
  a->p20=(struct Obj_tu5_03 *)parent;
  a->f120=1.0f;a->f124=0.0f;a->f128=0.0f;
  a->w30=func_0c1ec190()%360;
  ((struct ScaleView *)a)->scale=dat_0c2616f4;
 }
}
void func_0c1d63b6(struct Actor *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1d61c4;a->lcc=1053;
  a->l84=(int)((void **)dat_0c2d964c->p0)[89];
  a->p20=(struct Obj_tu5_03 *)parent;
  a->f120=1.0f;a->f124=0.0f;a->f128=0.0f;
  a->w30=func_0c1ec190()%360;
  ((struct ScaleView *)a)->scale=dat_0c2616f4;
 }
}
void func_0c1d6424(struct Actor *parent)
{
 func_0c1d6136(parent);func_0c1d6348(parent);func_0c1d63b6(parent);
}
