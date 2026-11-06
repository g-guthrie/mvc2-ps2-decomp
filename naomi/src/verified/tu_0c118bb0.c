#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c17aabc(struct Actor *,int,int),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24cba4[])(struct Actor *);
void func_0c118c34(struct Actor *,struct ActorSub2a4 *);
void func_0c118bb0(struct Actor *a,struct ActorSub2a4 *sub)
{
 float stopped=0.0f;int zero=0;
 a->b6++;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->b1f9=zero;a->f56=a->f41c;
 func_0c02a39a(a,zero);func_0c0442fa(a);func_0c0432ca(a);
 a->b1a1=71;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,12);a->s28=40;func_0c118c34(a,sub);
}
void func_0c118c34(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if(a->s28--==0){a->b6++;func_0c02a0c4(a,21,13);return;}
 if(a->b141&1){a->b141&=254;func_0c17aabc(a,1,8);}
 if(a->b141&2){a->b141&=253;position.x=0.0f;position.y=126.42857f;func_0c043014(a,&position);}
}
void func_0c118cb4(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c118cd6(struct Actor *a){table_0c24cba4[a->b6](a);}
