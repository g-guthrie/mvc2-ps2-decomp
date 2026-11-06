#include "objects.h"
extern void func_0c048ce6(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c025900(struct Actor *,int,int);
void func_0c124fa4(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;struct LinkedActorVec3 position;float stopped;
 if(a->b34&1){a->b1d2^=1;a->w130=a->b1d2;}
 a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,3);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;sub->b20=0;
 a->f92=-15.0f;a->f104=-0.20833333f;
 if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}
 position.x=-20.0f;position.y=180.0f;position.z=stopped;func_0c1d4610(a,&position);
}
void func_0c12504c(struct Actor *a)
{
 struct LinkedActorVec3 position;float stopped;
 a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,6);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 position.x=-106.666664124f;position.y=102.85714f;position.z=stopped;func_0c1d4610(a,&position);func_0c025900(a,1,1);
}
