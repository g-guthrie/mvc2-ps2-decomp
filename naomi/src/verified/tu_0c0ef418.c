#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0ef418(struct Actor *a,struct ActorSub2a4 *sub)
{
 int zero,attack;
 a->b3f8=2;a->b328=5;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);zero=0;attack=61;
 if(a->b141){
  a->b141=zero;a->b1a1=attack;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;((unsigned char (*)[2])sub)[2][1]=2;
 }
 if(!(--((unsigned char (*)[2])sub)[2][1]) && a->b19e){
  a->b1a1=attack;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
 if(!(a->f56>a->f41c)){
  a->b6++;a->f56=a->f41c;sub->b2=zero;
  a->b1a1=attack;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;
  a->f92=a->b1d2?21.666666031f:-21.666666031f;
  a->f104=a->b1d2?-0.3125f:0.3125f;a->f96=6.428571224213f;a->f108=-0.80357140303f;
  func_0c02a0c4(a,21,19);
 }
}
void func_0c0ef59c(struct Actor *a,struct ActorSub2a4 *sub)
{
 int zero,attack;
 a->b3f8=2;a->b328=5;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);zero=0;attack=61;
 if(a->b141){
  a->b141=zero;a->b1a1=attack;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;((unsigned char (*)[2])sub)[2][1]=2;
 }
 if(!(--((unsigned char (*)[2])sub)[2][1]) && a->b19e){
  a->b1a1=attack;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=zero;func_0c02a0c4(a,21,20);}
}
