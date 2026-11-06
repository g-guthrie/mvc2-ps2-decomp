/* Owner-linked effect child: spawn and follow-owner callback. The owner flag at 0x1a0 is read through a char pointer; the member spelling loads it into r0. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
void func_0c1b4f5c(struct LinkedActor *a);
struct LinkedActor *func_0c1b4f20(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,1))){a->w38=0x2b01;a->b34=owner->b1d0;a->b35=A(owner)->b1e9;a->p16=func_0c1b4f5c;a->p24=owner;}
 return a;
}
void func_0c1b4f5c(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 switch(a->b4){
 case 0:
  a->b4++;
  *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
  a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
  a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
  func_0c02a0c4(a,23,11);
 case 1:
  if(owner->b1d0==a->b34&&A(owner)->b1e9==a->b35){
   *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
   if(*((char *)owner+0x1a0))break;
   if(func_0c02a026(a)>=0)break;
  }
  a->b4++;a->sdc.b12c=0;
  break;
 case 2:
  func_0c037688(a);
  break;
 }
}

