#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0432ca(struct Actor *),func_0c0437b8(struct Actor *),func_0c144fc0(struct Actor *,int);
extern void func_0c19cffc(struct LinkedActorVec3 *,int,int);
extern void (*table_0c2431f4[])(struct Actor *);
void func_0c097b64(struct Actor *);
void func_0c097ae0(struct Actor *a)
{
 int zero;
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;zero=0;
 a->f56=a->f41c;a->b1fc=zero;a->b1f9=zero;func_0c048bb0(a,5);
 a->b1a1=49;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,2);func_0c0432ca(a);func_0c097b64(a);
}
void func_0c097b64(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;func_0c144fc0(a,a->b1a3);
  position=*(struct LinkedActorVec3 *)((char *)a+52);position.x+=!a->w130?-133.33333f:133.33333f;position.y+=240.0f;
  func_0c19cffc(&position,(short)a->w130,0);}
}
void func_0c097bd4(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c097bf6(struct Actor *a){struct Actor *p=a;table_0c2431f4[p->b6](a);}
