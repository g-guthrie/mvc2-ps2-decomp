#include "objects.h"
extern void (*table_0c247aec[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0c72d2(struct Actor *);
extern void func_0c0438de(struct Actor *);
void func_0c0c8f68(struct Actor *a);
void func_0c0c8ee8(struct Actor *a)
{
 a->b7++;
 func_0c0442fa(a);
 func_0c02a39a(a,1);
 a->f92/=8.0f;
 a->f104=0.0f;
 a->f96/=8.0f;
 a->f108/=64;
 func_0c048bb0(a,5);
 a->b1a1=72;
 a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,14);
 func_0c0c8f68(a);
}
void func_0c0c8f68(struct Actor *a)
{
 struct ActorSub2a4Grab *volatile sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 func_0c0c72d2(a);
 func_0c02a026(a);
 if(a->b141){
  a->b7++;
  sub->b9=1;
 }
}
void func_0c0c8f9e(struct Actor *a)
{
 func_0c0c72d2(a);
 if(func_0c02a026(a)<0){
  a->f96=0.0f;
  a->f108=0.0f;
  func_0c0438de(a);
 }
}
void func_0c0c8fce(struct Actor *a)
{
 a->x364[0]=0;
 table_0c247aec[a->b6](a);
}
