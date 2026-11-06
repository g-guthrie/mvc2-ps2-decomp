#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1c1678(struct Actor *,short *,int),func_0c042ad2(struct Actor *,struct LinkedActorVec3 *,int),func_0c0437b8(struct Actor *);
extern void (*table_0c24c2c8[])(struct Actor *);
void func_0c114f98(struct Actor *,struct ActorSub2a4 *);
void func_0c114f3c(struct Actor *a,struct ActorSub2a4 *sub)
{
 float stopped;
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);a->b1f9=0;
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->f56=a->f41c;
 func_0c02a0c4(a,22,3);a->s28=60;func_0c114f98(a,sub);
}
void func_0c114f98(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b202=1;sub->w4=600;sub->b3=0;func_0c1c1678(a,&sub->w4,7);
  position.x=-21.666666031f;position.y=210.0f;position.z=0.0f;func_0c042ad2(a,&position,1);}
}
void func_0c114ff8(struct Actor *a){func_0c02a026(a);if(--a->s28==0)func_0c0437b8(a);}
void func_0c11501e(struct Actor *a){table_0c24c2c8[a->b6](a);}
