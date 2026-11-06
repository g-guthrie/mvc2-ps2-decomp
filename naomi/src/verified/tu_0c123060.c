#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int dat_0c24d640[];
void func_0c1230fe(struct Actor *,struct ActorSub2a4 *);
void func_0c123060(struct Actor *a,struct ActorSub2a4 *sub)
{
 float stopped;int zero;
 a->b6++;func_0c048bb0(a,5);func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 zero=0;a->b1f9=zero;a->f56=a->f41c;
 sub->b1=zero;sub->b0=zero;sub->b2=zero;sub->b3=zero;
 a->b1a1=a->b1a3*2+48;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3);a->s28=a->b141;func_0c1230fe(a,sub);
}
void func_0c1230fe(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);
 if(--a->s28==0){
  a->b6++;func_0c02a0c4(a,21,a->b1a3+2);a->s28=a->b141;
  a->f92=(float)dat_0c24d640[(unsigned char)a->b1a3*2]*1.66666663f/65536.0f;
  a->f104=(float)(dat_0c24d640+(unsigned char)a->b1a3*2)[1]*1.66666663f/65536.0f;
  if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 }
}
