#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c03489c(struct Actor *),func_0c04b02a(struct Actor *),func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int),func_0c0437b8(struct Actor *),func_0c03edcc(struct Actor *,struct Actor *);
void func_0c0d9d88(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(!a->b6){
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(!a->b141)func_0c02a026(a);
  if(!a->b7 && !(a->f56>342.857117f)){a->b7++;func_0c0344a0(a,5);}
  if(!(a->f56>a->f41c)){a->b6++;func_0c02a0c4(a,15,3);func_0c03489c(a);}
 }else{
  if(func_0c02a026(a)>=0){
   int zero=0;
   if(a->b141<0){
    struct Actor *other;a->b141=zero;other=a->p1c8;other->b1a1=36;func_0c04b02a(a);
    position.x=-53.3333321f;position.y=68.57143f;position.z=0;func_0c1cea66(a,&position,1);return;
   }else if(a->b141>0){struct Actor *other;a->b141=zero;other=a->p1c8;other->p1b4=a;other->b1f6=1;other->b1a1=34;return;}
   return;
  }
  func_0c0437b8(a);
 }
}
void func_0c0d9ea2(struct Actor *a){func_0c03edcc(a->p1c8,a);}
