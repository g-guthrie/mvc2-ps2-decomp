/* Verified 0x0c1231bc..0x0c123358: zero is a plain void * set before the register copy of the cycle-bytes parameter. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c1bc740(struct Actor *,int,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24d650[])(struct Actor *);
/* func_0c1231bc: no twin (300 bytes) */
extern char func_0c02a026(struct Actor*);
extern void func_0c0437b8(struct Actor*);
void func_0c1231bc(struct Actor *a,struct ActorSubCycleBytes *s);
void func_0c123306(struct Actor *a);
void func_0c123338(struct Actor *a);

void func_0c1231bc(register struct Actor *a,struct ActorSubCycleBytes *s0)
{
 void *zero;
 register struct ActorSubCycleBytes *s;
 zero=0;
 s=s0;
 func_0c02a026(a);
 if(a->b141)return;
 if(a->b140){a->b140=(int)zero;s->b2=1;func_0c1bc740(a,7,0);}
 if(s->b0&&!--s->b0){
  s->b1=(int)zero;s->b0=(int)zero;
  if(s->b3^=1)a->b1a1=a->b1a3*2+48;
  else {goto t;t:a->b1a1=a->b1a3*2+78;}
  a->w1ac=(int)zero;a->b19e=(int)zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
 if(a->b19e&&!s->b1){s->b1=1;s->b0=8;}
 a->f52+=a->f92;a->f92+=a->f104;
 if(!a->b1d2){if((char)a->b1fd==2)goto stop;}
 else if((char)a->b1fd==1){stop:a->s28=(int)zero;}
 if(!a->s28--){
  a->b6++;
  s->b2=(int)zero;
  func_0c02a0c4(a,21,a->b1a3+4);
  func_0c1bc740(a,1,0);
 }
}

void func_0c123306(struct Actor *a)
{
 if(func_0c02a026(a)>=0)return;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);
}

void func_0c123338(struct Actor *a){table_0c24d650[a->b6](a);}
