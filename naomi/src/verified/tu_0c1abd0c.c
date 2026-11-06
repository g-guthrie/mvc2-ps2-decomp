#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c259d00[])(struct LinkedActor *);
extern void (*table_0c259d10[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c259d24[])(struct LinkedActor *);
void func_0c1abd4a(struct LinkedActor *),func_0c1abdd6(struct LinkedActor *);
struct LinkedActor *func_0c1abd0c(struct LinkedActor *parent,unsigned char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){
  struct ActorSub2a4 *sub;
  a->p16=func_0c1abd4a;a->p24=parent;a->b32=mode;
  sub=&A(parent)->sub2a4;sub->b3=255;
 }
 return a;
}
void func_0c1abd4a(struct LinkedActor *a){table_0c259d00[a->b4](a);}
void func_0c1abd5c(struct LinkedActor *a)
{
 struct LinkedActor *owner;
 a->b4++;a->w38=0x1c04;owner=a->p24;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;
 A(a)->b13c=24;A(a)->b13d=24;A(a)->b13e=16;A(a)->b13f=16;a->b36=0;
 func_0c1abdd6(a);
}
void func_0c1abdd6(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 unsigned char mode;
 if(owner->b1d0==21){
  if((mode=A(owner)->b1e9)==7||mode==4||mode==5||mode==13){
   struct ActorSub2a4 *sub=&A(owner)->sub2a4;
   int zero=0;
   sub->b3=zero;a->b4++;a->b7=zero;a->b6=zero;a->b5=zero;a->sdc.b12c=zero;return;
  }
 }
 a->sdc.b12c=owner->sdc.b12c;
 table_0c259d10[a->b6](a,owner);
}
void func_0c1abe48(struct LinkedActor *a){table_0c259d24[a->b7](a);}
