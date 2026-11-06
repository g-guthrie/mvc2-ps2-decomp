#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c191980(struct Actor *,int),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24de08[])(struct Actor *),(*table_0c24de10[])(struct Actor *);
void func_0c12d074(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 else{
  if(a->b141&1){a->b141^=1;func_0c0344a0(a,32);func_0c191980(a,1);}
  if(a->b141&2){a->b141^=2;position.x=-106.666664124f;position.y=102.85714f;func_0c043014(a,&position);}
 }
}
void func_0c12d0e2(struct Actor *a){table_0c24de08[a->b6](a);}
void func_0c12d0f4(struct Actor *a)
{
 a->b6++;a->b1f9=0;a->f56=a->f41c;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0442fa(a);func_0c02a0c4(a,20,0);
}
void func_0c12d134(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 else if(a->b141){a->b141=0;func_0c191980(a,6);}
}
void func_0c12d16c(struct Actor *a){table_0c24de10[a->b6](a);}
