#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void (*table_0c245e8c[])(struct Actor *);
extern void func_0c0c4f04(struct Actor *,void *),func_0c0c4f82(struct Actor *),func_0c1a9cf0(struct Actor *,int),func_0c15cff0(struct Actor *,int),func_0c0438de(struct Actor *);
void func_0c0c1f9c(struct Actor *),func_0c0c201a(struct Actor *);
void func_0c0c1f1c(struct Actor *record)
{
 struct Actor *a=record;
 a->b7++;func_0c0442fa(a);func_0c02a39a(a,0);
 a->f92/=8.0f;a->f104=0.0f;a->f96/=8.0f;a->f108/=64.0f;
 func_0c048bb0(a,5);
 record=0;a->b1a1=61;a->w1ac=(int)record;a->b19e=(int)record;a->p1c4=(int)record;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,2);
 func_0c0c1f9c(a);
}
void func_0c0c1f9c(struct Actor *a)
{
 func_0c0c201a(a);func_0c02a026(a);
 if(a->b141){a->b7++;a->b141=0;func_0c0c4f04(a,table_0c245e8c);func_0c0c4f82(a);func_0c1a9cf0(a,5);func_0c15cff0(a,2);}
}
void func_0c0c1fe6(struct Actor *a)
{
 func_0c0c201a(a);func_0c0c4f82(a);
 if(func_0c02a026(a)<0){a->f96=0.0f;a->f108=0.0f;func_0c0438de(a);}
}
void func_0c0c201a(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f41c<a->f56))a->f56=a->f41c;
}
