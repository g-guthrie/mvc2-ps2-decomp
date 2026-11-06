/* Candidate: all pools and three functions match; func_0c06cc4c differs only in the order of three instructions (retail hoists the &v[0] temp into r4 and computes r1=r4+12 before r13=r4; ours assigns r13 first). 423/428 bytes. */
#include "objects.h"
extern void func_0c025900(struct Actor *,int,int),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c048ce6(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c03efea(struct Actor *);
extern void (*table_0c240994[])(struct Actor *),(*table_0c2409a4[])(struct Actor *);
void func_0c06cbac(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(!(a->b34&1)){a->b1d2^=1;a->w130=a->b1d2;}
 func_0c025900(a,5,5);a->b1a0=10;
 position.x=-96.666664124f;position.y=128.57143f;position.z=0.0f;
 func_0c1d4610(a,&position);func_0c048ce6(a);func_0c0344a0(a,5);func_0c02a0c4(a,15,5);
}
void func_0c06cc1c(struct Actor *a)
{
 a->b1ea=1;table_0c240994[a->b1f7&63](a);
}
void func_0c06cc3a(struct Actor *a)
{
 table_0c2409a4[a->b6](a);
}
void func_0c06cc4c(register struct Actor *a)
{
 struct LinkedActorVec3 v[3];
 struct Actor *child;float stopped;
 struct LinkedActorVec3 *d=&v[0];
 a->b6++;stopped=0.0f;a->f104=stopped;a->f108=stopped;
 child=a->p1c8;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 child->f92=stopped;child->f96=stopped;child->f104=stopped;child->f108=stopped;
 *d=v[1]=*(struct LinkedActorVec3 *)&a->f52;
 func_0c03efea(a);
 d->x=a->f52-d->x;d->y=a->f56-d->y;
 *(struct LinkedActorVec3 *)&a->f52=v[1];
 a->f92=d->x/16.0f;a->f96=d->y/16.0f;a->f104=stopped;
 a->f96+=8.5714283f;a->f108=-0.5357143f;a->s28=16;
}
