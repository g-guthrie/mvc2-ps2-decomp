#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c10c188(struct Actor *),func_0c17323c(struct Actor *,int),func_0c1b80d8(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c109ff8(struct Actor *a)
{
 int zero=0;
 if(!a->b6){
  a->b6++;func_0c0442fa(a);func_0c0432ca(a);a->b1f9=zero;func_0c048bb0(a,10);
  a->b1a1=48;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,21,((char *)a)[0x2c0]+56);func_0c0344a0(a,4);
 }
 if(func_0c02a026(a)<0)func_0c10c188(a);
 else if(a->b141){
  a->b141=zero;func_0c0344a0(a,32);func_0c17323c(a,0);func_0c1b80d8(a,0);a->b27b=zero;a->b27a=16;
 }
}
