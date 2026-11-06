#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24d720[])(struct Actor *);
void func_0c124c80(struct Actor *,struct ActorSub2a4 *);
void func_0c124c00(struct Actor *a,struct ActorSub2a4 *sub)
{
 float stopped=0.0f;int zero=0;
 a->b6++;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->b1f9=zero;a->f56=a->f41c;
 func_0c02a39a(a,zero);func_0c0442fa(a);func_0c0432ca(a);
 a->b1a1=81;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,10);func_0c124c80(a,sub);
}
void func_0c124c80(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141&1){a->b141&=254;position.x=61.666664124f;position.y=117.85714f;func_0c043014(a,&position);}
}
void func_0c124cd2(struct Actor *a){table_0c24d720[a->b6](a);}
