#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c025900(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void (*table_0c24d6a8[])(struct Actor *);
void func_0c123f90(struct Actor *a,struct ActorSub2a4 *sub)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 if(a->b141&1)a->b141&=254;if(a->b141&2)a->b141&=253;
 if(((char *)sub)[18]){a->b6++;a->s28=12;}
}
void func_0c12400c(struct Actor *a)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(a->s28--){int zero;a->b6++;func_0c02a0c4(a,22,18);zero=0;
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;}
}
void func_0c12405a(struct Actor *a)
{
 if(func_0c02a026(a)<0){float offset=66.666664124f;
  if(!a->w130)a->f52-=offset;else a->f52+=offset;func_0c025900(a,0,0);func_0c0437b8(a);}
}
void func_0c1240a0(struct Actor *a){table_0c24d6a8[a->b6](a);}
