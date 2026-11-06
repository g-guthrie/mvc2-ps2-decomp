#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c166704(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short table_0c248c64[][2];
extern char dat_0c248e4c[], dat_0c248e50[], dat_0c248e54[];
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++

void func_0c0dcbb8(struct Actor *a)
{
 int k; int zero; int t; char d;
 zero=0;
 a->b6++;
 a->b1f9=zero;
 func_0c0442fa(a);
 func_0c02a39a(a,zero);
 func_0c0432ca(a);
 goto X; X: (a->i204?func_0c048bb0:func_0c048bb0)(a,8);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 t=a->i204; d=a->b1a3;
 k=t&1; k<<=1; k+=(unsigned char)d;
 a->s28=table_0c248c64[t][(unsigned char)d];
 a->b1a1=dat_0c248e4c[k];
 CLEAR_RECORD;
 func_0c02a0c4(a,21,dat_0c248e50[k]);
}

void func_0c0dcc62(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c02a026(a);
 if(a->b141){
  a->b141=0;
  if(!a->i204)func_0c166704(a,0);else func_0c166704(a,6);
  func_0c0344a0(a,30);
  a->b27b=0;
  a->b27a=16;
 }
 if((a->s28=a->s28-1)<=0){
  a->b6++;
  func_0c02a0c4(a,21,dat_0c248e54[a->i204*2+(unsigned char)a->b1a3]);
 }
}

void func_0c0dccd8(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}
