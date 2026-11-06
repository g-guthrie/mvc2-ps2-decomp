#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2332fc;
extern int func_0c1ec190(void);
void func_0c1e5b10(struct Obj_tu5_03 *),func_0c1e5b2c(struct Obj_tu5_03 *),func_0c1e5b90(struct Obj_tu5_03 *);
void func_0c1e5adc(void)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=0;
  a->l84=dat_0c2d964c->p0->entries[15].value;
  a->p16=func_0c1e5b10;a->lcc=0xc01;
 }
}
void func_0c1e5b10(struct Obj_tu5_03 *a)
{
 switch(a->b4){
 case 0:func_0c1e5b2c(a);break;
 case 1:func_0c1e5b90(a);break;
 }
}
void func_0c1e5b2c(struct Obj_tu5_03 *a)
{
 if(++a->w28>=60){
  a->b4++;a->b12c=1;
  a->pos=dat_0c2332fc;
  a->pos.x+=func_0c1ec190()%50000-10000;
  a->f120=a->f124=a->f128=1.0f;
 }
}
void func_0c1e5b90(struct Obj_tu5_03 *a)
{
 a->pos.x+=-145.0f;a->pos.y+=-84.0f;
 switch((unsigned char)a->b5){
 case 0:
  if(++a->w28>=50){a->b5++;a->w28=0;}
  break;
 case 1:
  {
   float step=0.020000000447f;
   a->f120-=step;a->f124-=step;a->f128-=step;
   if(a->f120<=0.0f){a->b4=0;a->b12c=0;}
  }
  break;
 }
}
