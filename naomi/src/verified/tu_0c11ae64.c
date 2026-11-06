#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c17ceb0(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int),func_0c0437b8(struct Actor *);
extern void (*table_0c24ce10[])(struct Actor *,struct ActorSub2a4 *);
void func_0c11ae64(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;((unsigned char *)sub)[10]=3;
 if(func_0c02a026(a)<0){int zero=0;
  a->b3f0=zero;a->b3f1=zero;a->b6++;func_0c02a0c4(a,22,1);a->s28=90;func_0c17ceb0(a);func_0c0344a0(a,45);
  position.x=-200.0f;position.y=240.0f;func_0c0429a4(a,&position,1);
 }
}
void func_0c11aee8(struct Actor *a,struct ActorSub2a4 *sub)
{
 ((unsigned char *)sub)[10]=3;a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(!func_0c047bbe(a)){if(a->s28--==0){int zero=0;
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;func_0c02a0c4(a,22,2);}}
}
void func_0c11af48(struct Actor *a,struct ActorSub2a4 *sub)
{
 ((unsigned char *)sub)[10]=3;if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c11af70(struct Actor *a){table_0c24ce10[a->b6](a,&a->sub2a4);}
