#include "objects.h"
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c245d4c[])(struct Actor *);
void func_0c0bf9bc(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(a->b34&1){struct Actor *other;a->b1d2=a->w130=a->b1d2^1;other=a->p1c8;other->b1d2=other->w130=other->b1d2^1;}
 position.x=11.666666031f;position.y=188.57143f;position.z=0;func_0c1d4610(a,&position);a->b1a0=10;func_0c02a0c4(a,15,0);
}
void func_0c0bfa2e(struct Actor *a)
{
 struct LinkedActorVec3 position;register float zero=0.0f;float velocity=zero;
 a->f104=velocity;a->f96=velocity;a->f108=-0.5357143f;
 if(a->b1d3>=0){velocity=a->b1d2?6.66666651f:-6.66666651f;if(a->b1d3)velocity=-velocity;}
 a->f92=velocity;
 if(a->b34&1){struct Actor *other;a->b1d2=a->w130=a->b1d2^1;other=a->p1c8;other->b1d2=other->w130=other->b1d2^1;}
 position.x=11.666666031f;position.y=188.57143f;position.z=zero;func_0c1d4610(a,&position);a->b1a0=10;func_0c02a0c4(a,15,1);
}
void func_0c0bfada(struct Actor *a){a->b1ea=1;table_0c245d4c[a->b1f7](a);}
