/* Four actor state handlers sharing one literal pool. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern void (*table_0c2442bc[])(struct Actor *);
extern ActorHandler table_0c2442b4[];
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c025900(struct Actor *,char,char);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c0a6d98(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(a->w1fa&0x400){a->b1d2=a->b1d2^1;a->w130=a->w130^1;}
 position.x=-83.33333f;position.y=158.57143f;
 func_0c1d4610(a,&position);
 a->b1a0=10;
 a->f92=0;
 a->f104=0;
 a->f96/=2.0f;
 a->f108=-0.80357140303f;
 func_0c048ce6(a);
 func_0c02a0c4(a,15,1);
}
void func_0c0a6e16(struct Actor *a)
{
    a->b1ea = 1;
    table_0c2442b4[a->b1f7 & 63](a);
}
void func_0c0a6e34(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(a->b141==1){
  struct Actor *target;
  position.x=-160.0f;position.y=154.28571f;
  func_0c1cea66(a,&position,2);
  func_0c0346da(a,2);
  a->b141=0;
  target=a->p1c8;
  target->p1b4=a;
  a->b1d2=a->w130;
  target->w130=a->b1d2^1;
  target->b1d2=target->w130;
  target->b1a1=32;target->b1f6=1;
  func_0c025900(a,0,0);
 }
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0a6ebe(struct Actor *a){table_0c2442bc[a->b6](a);}
