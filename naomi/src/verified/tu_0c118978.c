#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c17a454(struct Actor *,int,int);
extern void func_0c0437b8(struct Actor *),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int),func_0c02a0c4(struct Actor *,int,int),func_0c17a03c(struct Actor *,int,int);
void func_0c118978(struct Actor *a)
{
 struct LinkedActorVec3 position;int zero;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141&2){zero=0;a->b141&=253;a->b6++;a->s28=120;a->s30=zero;
  if(!func_0c17a454(a,zero,zero))func_0c0437b8(a);
  else{position.x=-163.33333f;position.y=207.857132f;position.z=0.0f;a->b3f0=zero;a->b3f1=zero;func_0c0429a4(a,&position,1);}
 }
}
void func_0c118a16(struct Actor *a,struct ActorSub2a4 *sub)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(--a->s28==0){int zero=0;a->b6++;a->s28=10;sub->b6=1;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;}
}
void func_0c118a68(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s28==0){a->b6++;func_0c02a0c4(a,22,2);func_0c17a03c(a,1,0);}
}
