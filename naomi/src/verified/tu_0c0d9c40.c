#include "objects.h"
extern void (*table_0c248abc[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,char,char),func_0c03489c(struct Actor *),func_0c0437b8(struct Actor *),func_0c04b02a(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c0346da(struct Actor *,int),func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
void func_0c0d9c40(struct Actor *a){a->b1ea=1;table_0c248abc[a->b1f7&63](a);}
void func_0c0d9c5e(struct Actor *a)
{
 if(func_0c02a026(a)>=0){
  if(a->b141){struct Actor *other;a->b141=0;other=a->p1c8;other->p1b4=a;other->b1f6=11;other->b1a1=32;func_0c025900(a,0,0);func_0c03489c(a);}
  return;
 }
 func_0c0437b8(a);
}
void func_0c0d9cb2(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *other;
 if(func_0c02a026(a)>=0){
  if(a->b141<0){
   a->b141=0;other=a->p1c8;other->b1a1=35;func_0c04b02a(a);
   position.x=-53.3333321f;position.y=68.57143f;position.z=0;
   func_0c1cea66(a,&position,1);func_0c0344a0(a,3);func_0c0346da(a,0);
  }
  else if(a->b141>0){a->b141=0;other=a->p1c8;other->p1b4=a;other->b1f6=1;other->b1a1=33;func_0c025900(a,0,0);}
  return;
 }
 func_0c0437b8(a);
}