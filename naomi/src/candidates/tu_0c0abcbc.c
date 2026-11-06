/* Candidate: func_0c0abcfa float scale shape differs (retail loads 1.6666666f via lds/fsts and reloads &b141 per branch); other functions match modulo placement */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c1a1a34(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c04be40(struct Actor *);
extern void (*table_0c2445f4[])(struct Actor*,struct ActorSub2a4*);
extern void (*table_0c244618[])(struct Actor*,struct ActorSub2a4*);
#pragma inline(h1,h2)
static float h1(char *p,float k){float r=*p;r*=k;return r;}
static float h2(char c,float k){return c*k;}
void func_0c0abcbc(struct Actor *a)
{
 if(func_0c02a026(a)<=0){a->b6++;func_0c02a0c4(a,21,24);func_0c1a1a34(a,4,0);func_0c1a1a34(a,5,0);}
}
void func_0c0abcfa(struct Actor *a)
{
 struct LinkedActorVec3 v;int zero;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 zero=0;
 if(a->b141){
  float *p=&a->f52;float d;
  if(a->b1d2)d=h2(a->b141,1.66666663f);else d=-h2(a->b141,1.66666663f);
  *p+=d;
  a->b141=zero;
 }
 if(a->b140==1){a->b140=zero;v.x=0;v.y+=102.85714f;func_0c043014(a,&v);}
}



void func_0c0abd90(struct Actor *a)
{
 int c;
 a->b328=5;
 c=a->b6;
 if(c&&c!=8){a->b202|=0x80;a->b1eb=2;func_0c04be40(a);}
 table_0c2445f4[a->b6](a,&a->sub2a4);
}
void func_0c0abdd8(struct Actor *a){table_0c244618[a->b7](a,&a->sub2a4);}
