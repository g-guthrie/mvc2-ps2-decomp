#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0427f2(struct Actor *),func_0c042780(struct Actor *);
extern void func_0c1ceafe(struct Actor *,struct LinkedActorVec3 *),func_0c034946(struct Actor *,int),func_0c04b02a(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
void func_0c1251c0(struct Actor *a)
{
 struct Actor *other=a->p1c8;struct LinkedActorVec3 position;unsigned char command;
 func_0c02a026(a);if(func_0c0427f2(a))a->b142=1;if(func_0c042780(a->p1c8))a->s28=0;
 command=32;
 if(a->b141){a->b141=0;position.x=-43.3333321f;position.y=27.8571415f;func_0c1ceafe(a,&position);func_0c034946(other,2);
  other->p1b4=a;a->b1a1=other->b1a1=command;other->b1d2=a->b1d2;other->b1d2^=1;func_0c04b02a(a);a->b1a0=8;}
 if(a->s28--==0){other->p1b4=a;a->b1a1=other->b1a1=command;other->b1f6=3;
  a->f92=7.91666651f;a->f104=-0.0520833321f;a->f96=11.78571415f;a->f108=-0.6361607f;
  if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}
  func_0c02a0c4(a,15,1);a->b6++;
 }
}
