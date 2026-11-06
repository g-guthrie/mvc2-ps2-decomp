#include "objects.h"
extern void (*table_0c2431e8[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c19996c(struct Actor *,int);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c145f34(struct Actor *,int);
extern void func_0c0437b8(struct Actor *);
void func_0c0979ea(struct Actor *a);
void func_0c097964(struct Actor *a)
{
 int zero;
 a->b6++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 zero=0;
 a->f56=a->f41c;
 a->b1fc=zero;a->b1f9=zero;
 func_0c048bb0(a,5);
 a->b1a1=63;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3);
 func_0c0432ca(a);
 func_0c0979ea(a);
}
void func_0c0979ea(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b140){
  a->b6++;
  if(!a->b1a3)func_0c19996c(a,4);else func_0c19996c(a,7);
 }
}
void func_0c097a20(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b6++;
  a->b141=0;
  func_0c0344a0(a,47);
  func_0c19996c(a,!a->b1a3?2:3);
  func_0c145f34(a,0);
 }
}
void func_0c097a6e(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c097a90(struct Actor *a){table_0c2431e8[a->b6](a);}
