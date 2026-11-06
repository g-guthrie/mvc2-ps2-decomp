#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c043324(struct Actor *),func_0c05d6d4(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c05e740(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){
  a->b6++;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;
  func_0c043324(a);func_0c02a0c4(a,20,7);return;
 }
 func_0c02a026(a);
}
void func_0c05e7ce(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c05e7f0(struct Actor *a)
{
 a->b6++;a->b3f8=2;a->b328=5;
 a->b1a1=a->b1a3?78:78;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 a->s28=0;func_0c02a0c4(a,21,7);func_0c05d6d4(a);
}
