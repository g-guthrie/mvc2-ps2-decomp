/* Throw/hold handlers 0x0c0d6094-0x0c0d6200 (0x0c0d6124 cloned from 0x0c03b3c8). */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c248794[];
extern void (*table_0c2487a4[])(struct Actor *);
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0427be(struct Actor *,int);
extern void func_0c0426c2(struct Actor *,int);

#pragma inline(flag_test)
static unsigned int flag_test(struct Actor *t,unsigned int hi,unsigned int lo)
{
 struct ActorFlags64 *f=(struct ActorFlags64 *)&t->l414;
 return (f->hi&hi)|(f->lo&lo);
}
void func_0c0d6094(struct Actor *a)
{
 struct LinkedActorVec3 v;
 func_0c025900(a,6,6);
 a->b1a0=10;
 v.x=-120.0f;v.y=120.0f;v.z=0;
 func_0c1d4610(a,&v);
 {struct Actor *t;struct ActorFlags64 *f;f=(struct ActorFlags64 *)&(t=a->p1c8)->l414;&t;if((f->hi&0)|(f->lo&0x04000000))a->p1c8->f56=a->f41c+68.57143f;}
 func_0c02a0c4(a,15,6);
}

void func_0c0d6106(struct Actor *a)
{
    a->b1ea = 1;
    table_0c248794[a->b1f7 & 63](a);
}

void func_0c0d6124(struct Actor *a){table_0c2487a4[a->b6](a);}

void func_0c0d6136(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b6++;a->b141=0;
  func_0c0427be(a,3);
  func_0c0426c2(a->p1c8,48);
  a->s28=120;a->s30=0;
  if(!(a->b34&2)){a->b1d2^=1;a->w130=a->b1d2;}
   {struct Actor *t;struct ActorFlags64 *f;f=(struct ActorFlags64 *)&(t=a->p1c8)->l414;&t;if(!((f->hi&0x20000000)|(f->lo&0x04000000)))a->p1c8->f56=a->f41c;}
 }
}
