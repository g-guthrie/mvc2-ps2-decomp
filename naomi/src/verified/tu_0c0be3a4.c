#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct LinkedActor *func_0c15ba0c(struct LinkedActor *,unsigned char,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c245c9c[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0be3a4(struct Actor *a,struct ActorSub2a4 *state)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(!state->b1){a->b6++;a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;func_0c02a0c4(a,22,4);}
 if(state->b2&&func_0c047bbe(a)){if(!((--state->b2)&1))a->s30++;}
}
void func_0c0be412(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0be434(struct Actor *a){table_0c245c9c[a->b6](a,&a->sub2a4);}
void func_0c0be44a(struct Actor *a,struct ActorSub2a4 *state)
{
 int zero,sixty=60;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;zero=0;a->b1a1=69;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;a->w1ac=64;
 func_0c0442fa(a);a->b1f9=zero;a->f56=a->f41c;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 if(a->b525)((struct ActorSubByteState *)state)->b4=20;else ((struct ActorSubByteState *)state)->b4=sixty;
 a->s28=sixty;func_0c0432ca(a);func_0c02a0c4(a,22,5);
}
void func_0c0be532(struct Actor *a)
{
 int zero;struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){a->b6++;zero=0;a->b141=zero;a->f92=a->b1d2?13.33333302f:-13.33333302f;func_0c15ba0c((struct LinkedActor *)a,4,3);a->b3f0=zero;a->b3f1=zero;position.x=-40;position.y=90;position.z=0;func_0c0429a4(a,&position,1);}
}
