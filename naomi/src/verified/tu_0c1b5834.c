#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c25b0fc[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c25b108[])(struct LinkedActor *);
extern void (*table_0c25b114[])(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c1b586c(struct LinkedActor *);
struct LinkedActor *func_0c1b5834(struct LinkedActor *owner,int mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,1))){a->pad0=1;a->w38=0x2b06;a->b32=mode;a->p16=func_0c1b586c;a->p24=owner;}
 return a;
}
void func_0c1b586c(struct LinkedActor *a){table_0c25b0fc[a->b32](a,a->p24);}
void func_0c1b5882(struct LinkedActor *a){table_0c25b108[a->b4](a);}
void func_0c1b5894(struct LinkedActor *a,struct LinkedActor *owner)
{
 float x;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->b36=12;
 a->f56=A(owner)->f41c;
 a->s28=32;
 x=dat_0c2d9260.f8c+480.0f;
 a->f92=-16.666666031f;
 if(A(owner)->b1d2){x=dat_0c2d9260.f88+-533.333313f;a->f92=-a->f92;}
 a->f52=x;
 func_0c02a0c4(a,23,26);
}
void func_0c1b5938(struct LinkedActor *a)
{
 switch((unsigned char)a->b5){
 case 0:
  func_0c02a026(a);
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(!--a->s28){a->b5++;a->f104=-(a->f92/4.0f);func_0c02a0c4(a,23,27);}
  break;
 case 1:
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(a->f92*a->f104>=0.0f){a->b5++;a->f92=0;a->f104=0;}
  break;
 case 2:
  if(func_0c02a026(a)<0)a->b5++;
  break;
 }
}
void func_0c1b5a74(struct LinkedActor *a){table_0c25b114[a->b4](a);}
