#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25760c[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c1905d8(struct LinkedActor *),func_0c19068e(struct LinkedActor *),func_0c190692(struct LinkedActor *);
struct LinkedActor *func_0c190578(struct Actor *parent,float dx,float dy)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){
  a->p16=func_0c1905d8;a->p24=(struct LinkedActor *)parent;a->b32=0;a->w38=0x0500;
  a->f52=parent->f52+(parent->b1d2?-dx:dx);
  a->f56=parent->f56+dy;
 }
 return a;
}
void func_0c1905d8(struct LinkedActor *a){table_0c25760c[a->b4](a);}
void func_0c1905ea(struct LinkedActor *a)
{
 a->b4++;a->sdc.b12c=1;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->sdc.w130=a->p24->sdc.w130;a->b36=0;
 func_0c02a0c4(a,23,24);
}
void func_0c19066e(struct LinkedActor *a){if(func_0c02a026(a)<0)func_0c19068e(a);}
void func_0c19068e(struct LinkedActor *a){a->b4=3;func_0c190692(a);}
void func_0c190692(struct LinkedActor *a){func_0c037688(a);}
