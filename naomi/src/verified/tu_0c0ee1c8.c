#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c249ec4[])(struct Actor *,struct ActorSub2a4 *);
extern float dat_0c249ed4[][4],dat_0c249ed8[][4];
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
void func_0c0ee1c8(struct Actor *a){table_0c249ec4[a->b7](a,&a->sub2a4);}
void func_0c0ee1de(struct Actor *a,struct ActorSub2a4 *context)
{
 int zero=0;
 a->b7++;a->b1a1=48;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,10);func_0c0442fa(a);context->b2=zero;func_0c02a0c4(a,21,3);
}
void func_0c0ee23e(struct Actor *a)
{
 func_0c02a026(a);
 if(((unsigned char *)&a->w150)[1]){
  a->b7++;((unsigned char *)&a->w150)[1]=0;
  a->f92=a->b1d2?dat_0c249ed4[(unsigned char)a->b1a3][0]:-dat_0c249ed4[(unsigned char)a->b1a3][0];
  a->f104=a->b1d2?dat_0c249ed8[(unsigned char)a->b1a3][0]:-dat_0c249ed8[(unsigned char)a->b1a3][0];
  a->f96=dat_0c249ed4[(unsigned char)a->b1a3][2];a->f108=dat_0c249ed4[(unsigned char)a->b1a3][3];
 }
}
