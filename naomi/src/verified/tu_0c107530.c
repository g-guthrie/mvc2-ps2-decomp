#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c172474(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c1075d4(struct Actor *,struct ActorSub2a4 *);
void func_0c107530(register struct Actor *a,register struct ActorSub2a4 *sub)
{
 int zero;float stopped;
 a->b7++;func_0c048bb0(a,5);func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 zero=0;a->b1f9=zero;a->f56=a->f41c;((unsigned char (*)[2])sub)[4][0]=!a->b1a3?3:5;
 goto state;state:a->b1a1=68;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3);a->s30=a->b141;a->b141=zero;func_0c1075d4(a,sub);
}
void func_0c1075d4(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);
 if(a->b141){int zero=0;a->b7++;a->s28=zero;a->b27a=16;a->b27b=zero;}
}
void func_0c107604(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);
 if(((unsigned char (*)[2])sub)[4][0] && a->s28--==0){a->s28=3;func_0c172474(a,2,0);((unsigned char (*)[2])sub)[4][0]--;}
 if(--a->s30==0){a->b7++;func_0c02a0c4(a,21,a->b1a3+2);}
}
