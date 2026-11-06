#include "objects.h"
extern void func_0c048ce6(struct Actor *),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24973c[])(struct Actor *);
void func_0c0e77b8(struct Actor *a)
{
 struct LinkedActorVec3 p;
 func_0c048ce6(a);a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;
 if(a->b34&2){a->b1d2=a->w130=a->b1d2^1;a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;}
 a->f96=0;p.x=11.666666031f;p.y=229.28571f;p.z=0;func_0c1d4610(a,&p);a->b1a0=10;func_0c02a0c4(a,15,2);
}
void func_0c0e784a(struct Actor *a)
{
 struct LinkedActorVec3 p;func_0c048ce6(a);p.x=-80;p.y=184.28571f;p.z=0;func_0c1d4610(a,&p);a->b1a0=10;
 a->b1d2=a->w130=a->b1d2^1;a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;a->f56=a->f41c;func_0c02a0c4(a,15,3);
}
void func_0c0e78be(struct Actor *a)
{
 struct LinkedActorVec3 p;func_0c048ce6(a);a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;a->f92=a->b1d2?6.66666651f:-6.66666651f;a->f104=0;a->f96=8.5714283f;a->f108=-0.80357140303f;
 p.x=-43.3333321f;p.y=75;p.z=0;func_0c1d4610(a,&p);a->b1a0=10;func_0c02a0c4(a,15,4);
}
void func_0c0e796c(struct Actor *a)
{
 func_0c048ce6(a);a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;
 if(a->b34&2){a->b1d2=a->w130=a->b1d2^1;a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;}
 func_0c02a0c4(a,15,5);
}
void func_0c0e79d2(struct Actor *a)
{
 struct LinkedActorVec3 p;a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;a->s28=16;a->f92=a->b1d2?1.66666663f:-1.66666663f;a->f104=0;a->f96=34.2857132f;a->f108=-0.80357140303f;
 p.x=-43.3333321f;p.y=75;p.z=0;func_0c1d4610(a,&p);func_0c02a0c4(a,15,6);
}
void func_0c0e7a4e(struct Actor *a){a->b1ea=1;table_0c24973c[a->b1f7&63](a);}
