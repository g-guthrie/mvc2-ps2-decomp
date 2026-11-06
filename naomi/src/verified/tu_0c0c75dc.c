#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *);
extern void (*table_0c247990[])(struct Actor *);
void func_0c0c76fc(struct Actor *);
void func_0c0c75dc(struct Actor *a)
{
 int zero=0;
 a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1f9=zero;a->f56=a->f41c;
 func_0c02a39a(a,1);func_0c0442fa(a);func_0c0432ca(a);a->b1a1=80;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,15);
}
void func_0c0c7652(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;position.x=35.0f;position.y=102.85714f;func_0c043014(a,&position);}
}
void func_0c0c769c(struct Actor *a){table_0c247990[a->b6](a);}
void func_0c0c76ae(struct Actor *a)
{
 int zero=0;a->b6++;func_0c0442fa(a);func_0c02a39a(a,1);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;a->b1fc=zero;a->b1f9=zero;func_0c02a0c4(a,20,2);func_0c0c76fc(a);
}
void func_0c0c76fc(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
