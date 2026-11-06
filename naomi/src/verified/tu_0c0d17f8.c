/* Throw landing 0x0c0d17f8 and its recovery wait 0x0c0d18e2. */
#include "objects.h"
extern void func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern void func_0c0442fa(struct Actor *),func_0c0cfebe(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern void func_0c162414(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0d17f8(struct Actor *a)
{
 int zero;
 a->b6++;a->s28=5;
 func_0c02a39a(a,0);
 func_0c048bb0(a,5);
 zero=0;
 if(a->b1e9==12){
  if(a->b1f9==2){
   a->f92/=16;a->f96/=8;a->f108/=64;a->f104=0;
   func_0c0344a0(a,43);func_0c0442fa(a);
  }else func_0c0cfebe(a);
  a->b1a1=72;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,21,a->b1a3+13);
 }else{
  func_0c0cfebe(a);
  a->b1a1=50;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,21,a->b1a3+3);
 }
}
void func_0c0d18e2(register struct Actor *a)
{
 register int zero;
 func_0c02a026(a);
 if(a->b141==2){
  zero=a->b141=0;a->b27b=zero;a->b27a=16;
  if(a->b1e9==12)func_0c162414(a,1,0);else func_0c162414(a,0,0);
  *(int *)&a->pad10c[40]=zero;
  a->b6++;
 }
}
