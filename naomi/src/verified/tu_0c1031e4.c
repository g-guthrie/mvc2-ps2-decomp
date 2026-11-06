#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c0346da(struct Actor *,int),func_0c0437b8(struct Actor *);
void func_0c1031e4(struct Actor *a)
{
 a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c-120.0f){a->b6++;a->f56=a->f41c;a->f96=-(a->f96/8.0f);func_0c02a026(a);func_0c043324(a);func_0c0346da(a,48);}
}
void func_0c103252(struct Actor *a)
{
 a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
 if(a->f56<a->f41c){float stopped=0.0f;
  a->b6++;a->b1f9=0;a->f56=a->f41c;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 }
}
void func_0c1032b2(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6=0;func_0c0437b8(a);}
}
