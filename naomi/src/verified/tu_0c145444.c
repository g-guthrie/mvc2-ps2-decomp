/* Actor turn/fall state handlers 0x0c145444-0x0c1458a0. 0c145524 and 0c1455a4 are
 * entered by fall-through from 0c1454e4/0c145594; 2.0f is materialised via an inlined 1.0f helper. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c028642(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,char),func_0c037688(struct Actor *);
extern void (*table_0c24fb14[])(struct Actor *);
void func_0c1454e4(struct Actor *,struct Actor *);
void func_0c145524(struct Actor *,struct Actor *);
void func_0c1455a4(struct Actor *);
#pragma inline(one)
static float one(void){return 1.0f;}

void func_0c145444(struct Actor *a,struct Actor *owner)
{
 unsigned char side=0;
 if(func_0c02a026(a)<0){
  if(a->f52-owner->f52<0.0f)side=1;
  if((short)a->w130==side){a->b6=6;func_0c1454e4(a,owner);return;}
  a->b6++;a->w130=side;func_0c02a0c4(a,23,14);
 }
}

void func_0c1454b4(struct Actor *a,struct Actor *owner)
{
 if(func_0c02a026(a)<0){a->b6++;func_0c1454e4(a,owner);}
}

void func_0c1454e4(struct Actor *a,struct Actor *owner)
{
 a->b6++;
 if(!a->w130)a->f92=-7.91666651f;else a->f92=7.91666651f;
 a->f104=0.0f;
 func_0c02a0c4(a,23,13);
 func_0c145524(a,owner);
}

void func_0c145524(struct Actor *a,struct Actor *owner)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 if(!func_0c028642(a)){a->b4++;a->b12c=0;}
}

void func_0c145566(struct Actor *a){table_0c24fb14[a->b6](a);}

void func_0c145594(struct Actor *a)
{
 a->b6++;a->f92=0.0f;a->f108=0.0f;
 func_0c1455a4(a);
}

void func_0c1455a4(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!--a->s28){a->b6++;{float t=one();t+=t;a->f92=a->f92/t;a->f96=a->f96/t;}a->f108=-0.80357140303f;func_0c02a0c4(a,23,29);}
}

void func_0c145628(struct Actor *a,struct Actor *owner)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>owner->f41c+171.42856f)){a->b6++;a->f108=-0.80357140303f;func_0c02a0c4(a,23,30);}
}

void func_0c1456bc(struct Actor *a,struct Actor *owner)
{
 struct ActorSubByteState *sub;
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>owner->f41c)){a->b6++;a->f56=owner->f41c;func_0c02a0c4(a,23,31);sub=(struct ActorSubByteState *)&owner->sub2a4;if(sub->b5)sub->b5--;}
}

void func_0c14573e(struct Actor *a,struct Actor *owner)
{
 unsigned char side=0;
 if(func_0c02a026(a)<0){
  if(a->f52-owner->f52<0.0f)side=1;
  if((short)a->w130==side){a->b6=6;func_0c1454e4(a,owner);return;}
  a->b6++;a->w130=side;func_0c02a0c4(a,23,14);
 }
}

void func_0c1457ae(struct Actor *a,struct Actor *owner)
{
 if(func_0c02a026(a)<0){a->b6++;func_0c1454e4(a,owner);}
}

void func_0c1457de(struct Actor *a,struct Actor *owner)
{
 a->b6++;
 if(!a->w130)a->f92=-7.91666651f;else a->f92=7.91666651f;
 a->f104=0.0f;
 func_0c02a0c4(a,23,13);
 func_0c145524(a,owner);
}

void func_0c145834(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 if(!func_0c028642(a)){a->b4++;a->b12c=0;}
}

void func_0c145876(struct Actor *a){a->b4++;a->b12c=0;}

void func_0c145884(struct Actor *a){func_0c037688(a);}
