#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c1797f8(struct Actor *,char,char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c118330(struct Actor *,struct ActorSub2a4 *);
void func_0c118284(struct Actor *a,struct ActorSub2a4 *sub)
{
 float stopped;int zero;
 a->b6++;func_0c048bb0(a,5);func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 zero=0;a->b1f9=zero;a->f56=a->f41c;
 a->b1a1=51;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3+6);a->s28=4;a->s30=!a->b1a3?8:12;a->b33=zero;func_0c0344a0(a,21);func_0c118330(a,sub);
}
void func_0c118330(struct Actor *a,struct ActorSub2a4 *sub)
{
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,21,8);}
}
void func_0c11835a(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s30==0){func_0c1797f8(a,0,(*(char *)&a->b33)++);a->s30=!a->b1a3?8:12;if(--a->s28==0){a->b6++;a->s28=40;}}
}
