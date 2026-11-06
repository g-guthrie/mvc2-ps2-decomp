/* Complete paired movement, callback dispatch and launch section. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0427f2(struct Actor *),func_0c042780(struct Actor *);
extern void func_0c1ceafe(struct Actor *,struct LinkedActorVec3 *),func_0c034946(struct Actor *,int),func_0c04b02a(struct Actor *),func_0c0437b8(struct Actor *);
extern void (*table_0c24c0b8[])(struct Actor *);
void func_0c112cb8(struct Actor *a)
{
 struct Actor *other=a->p1c8;struct LinkedActorVec3 position;int frame;
 func_0c02a026(a);other->f56=other->f41c;
 if(func_0c0427f2(a))a->b142=1;
 if(func_0c042780(a->p1c8))a->s28=0;
 frame=32;
 if(a->b141){
 a->b141=0;position.x=-43.3333321f;position.y=27.8571415f;func_0c1ceafe(a,&position);
 func_0c034946(other,2);other->p1b4=a;other->b1a1=frame;a->b1a1=frame;
 other->b1d2=a->b1d2;other->b1d2^=1;func_0c04b02a(a);a->b1a0=8;
 }
 if(a->s28--==0){
 other->p1b4=a;other->b1a1=frame;a->b1a1=frame;other->b1f6=1;
 other->b1d2=a->b1d2;other->b1d2^=1;func_0c0437b8(a);
 }
}
void func_0c112d80(struct Actor *a){table_0c24c0b8[a->b6](a);}
void func_0c112d92(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b141=0;a->b6++;a->f96=21.42857f;a->f108=-0.80357140303f;a->s28=20;}
}
