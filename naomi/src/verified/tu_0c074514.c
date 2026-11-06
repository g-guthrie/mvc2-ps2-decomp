#include "objects.h"
extern void func_0c0437b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c13b9cc(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c074514(struct Actor *a,struct ActorChildTimerReference *context)
{
 struct Actor *child;
 unsigned short two=2;
 register int zero;
 float offset;
 a->b3f8=two;a->b328=5;
 context->timer++;
 a->b1f5=two;
 if(!a->b19e){func_0c0437b8(a);return;}
 zero=0;
 if(func_0c02a026(a)>=0){
 if(a->b141){
 a->b1a1=a->b141;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
 a->b141=zero;
 if(a->b140){func_0c0344a0(a,(char)a->b140+29);a->b140=zero;}
 child=context->base.child;
 if(!child->b202)child->f56+=4.28571415f;
 }
 }else{
 a->b7++;
 a->b3f9=zero;a->b3f8=zero;a->b328=5;
 func_0c025900(a,0,0);
 func_0c13b9cc(a);
 offset=-80.0f;
 if(a->b1d2)offset=80.0f;
 a->f52=a->f52+offset;
 a->f56+=68.57143f;
 func_0c02a0c4(a,22,2);
 }
}
