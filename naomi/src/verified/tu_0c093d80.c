#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c242e84[])(struct Actor *,struct ActorSub2a4 *);
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int);
extern struct LinkedActor *func_0c14483c(struct Actor *,unsigned char,unsigned char);
void func_0c093e36(struct Actor *,struct ActorSub2a4 *);
void func_0c093d80(struct Actor *a,struct ActorSub2a4 *context){if(a->b1f9==2)a->b6=1;table_0c242e84[a->b6](a,context);}
void func_0c093da2(struct Actor *a,struct ActorSub2a4 *context)
{
 int zero;
 a->b6++;func_0c048bb0(a,5);func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;zero=0;a->b1f9=zero;a->f56=a->f41c;
 a->b1a1=a->b1a3+54;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,5);((unsigned char *)context)[9]=zero;func_0c093e36(a,context);
}
void func_0c093e36(struct Actor *a,struct ActorSub2a4 *context)
{
 /* This entry shares the dispatcher signature; context is carried onward. */
 func_0c02a026(a);
 if(!a->b141){int zero=0;a->b141=zero;a->b6++;a->s28=36;a->s30=zero;func_0c0344a0(a,32);}
}
void func_0c093e6e(struct Actor *a,struct ActorSub2a4 *context)
{
 if(!(a->s28&3)){func_0c14483c(a,0,a->s30);a->s30++;}
 func_0c02a026(a);if(--a->s28==0){a->b6++;a->s28=90;((unsigned char *)context)[9]=1;}
}
