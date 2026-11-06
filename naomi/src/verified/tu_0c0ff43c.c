#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int);
extern void (*table_0c24adec[])(struct Actor *);
void func_0c0ff43c(register struct Actor *a)
{
 float stopped=0.0f;
 a->b6++;a->b1f9=0;a->f56=a->f41c;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 a->b1a1=68;a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,21,11);func_0c0346da(a,20);
}
void func_0c0ff4ae(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);}
 else if(a->b141){int zero=0;a->b141=zero;a->b1a1=69;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;func_0c0346da(a,22);}
}
void func_0c0ff50a(struct Actor *a){struct Actor *p=a;table_0c24adec[p->b6](a);}
void func_0c0ff51c(register struct Actor *a)
{
 float stopped=0.0f;
 a->b6++;a->b1f9=0;a->f56=a->f41c;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 a->b1a1=67;a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,21,12);
}
