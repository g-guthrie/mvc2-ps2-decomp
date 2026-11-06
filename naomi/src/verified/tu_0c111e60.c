#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c111e60(struct Actor *a)
{
 float stopped=0.0f;int zero=0;
 a->b6++;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->b1f9=zero;a->f56=a->f41c;
 func_0c0442fa(a);func_0c0432ca(a);
 a->b1a1=49;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,20,2);
}
void func_0c111ece(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;position.x=51.666664124f;position.y=120.0f;position.z=0.0f;func_0c043014(a,&position);}
}
void func_0c111f1e(struct Actor *a)
{
 if(!a->b6){float stopped;a->b6++;func_0c0442fa(a);stopped=0.0f;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->b1f9=0;a->f56=a->f41c;func_0c02a0c4(a,20,3);}
 else if(func_0c02a026(a)<0)func_0c0437b8(a);
}
