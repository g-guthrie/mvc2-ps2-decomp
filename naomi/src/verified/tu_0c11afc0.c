#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c17bf10(struct Actor *,int),func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24ce1c[])(struct Actor *,struct ActorSub2a4 *);
void func_0c11b044(struct Actor *,struct ActorSub2a4 *);
void func_0c11b08e(struct Actor *,struct ActorSub2a4 *);
void func_0c11afc0(struct Actor *a,struct ActorSub2a4 *sub)
{
 float stopped;int zero;
 a->b6++;func_0c0442fa(a);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 zero=0;a->b1f9=zero;a->f56=a->f41c;func_0c0432ca(a);func_0c048bb0(a,5);
 a->b1a1=33;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,22);a->s28=72;func_0c11b044(a,sub);
}
void func_0c11b044(struct Actor *a,struct ActorSub2a4 *sub)
{
 if(func_0c02a026(a)<0){a->b6++;func_0c0344a0(a,21);func_0c0344a0(a,47);func_0c17bf10(a,a->b1a3);func_0c11b08e(a,sub);}
}
void func_0c11b08e(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);if(--a->s28==0)func_0c0437b8(a);
}
void func_0c11b0b4(struct Actor *a){table_0c24ce1c[a->b6](a,&a->sub2a4);}
