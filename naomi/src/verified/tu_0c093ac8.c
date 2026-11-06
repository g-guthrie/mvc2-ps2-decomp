#include "objects.h"
extern void (*table_0c242e6c[])(struct Actor *),(*table_0c242e74[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0953be(struct Actor *),func_0c143b10(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
void func_0c093b6e(struct Actor *,struct ActorSub2a4 *);
void func_0c093ac8(struct Actor *a)
{
 if(a->b1f9==2)a->b6=1;
 table_0c242e6c[a->b6](a);
}
void func_0c093aea(struct Actor *a,struct ActorSub2a4 *state)
{
 float stopped;
 a->b7++;func_0c048bb0(a,5);func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 a->b1f9=0;a->f56=a->f41c;a->b1a1=63;
 a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,3);func_0c093b6e(a,state);
}
void func_0c093b6e(struct Actor *a,struct ActorSub2a4 *state)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 func_0c0953be(a);
 if(a->b141){int index;a->b141=0;for(index=0;index<10;index++)func_0c143b10(a,0,index);}
}
void func_0c093bc6(struct Actor *a)
{
 table_0c242e74[a->b7](a);
}
