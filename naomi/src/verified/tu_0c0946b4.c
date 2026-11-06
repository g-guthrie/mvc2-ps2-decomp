#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c094752(struct Actor *,struct ActorSubByteState *);
void func_0c0946b4(struct Actor *a,struct ActorSubByteState *state)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1f9=0;a->f56=a->f41c;state->b6=0;
 a->b1a1=64;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,22,5);a->s28=48;func_0c094752(a,state);
}
void func_0c094752(struct Actor *a,struct ActorSubByteState *state)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141&1){
 a->b141&=126;a->b6++;
 position.x=-26.666666031f;position.y=182.142853f;position.z=0.0f;
 a->b3f0=0;a->b3f1=0;func_0c0429a4(a,&position,1);
 }
}
