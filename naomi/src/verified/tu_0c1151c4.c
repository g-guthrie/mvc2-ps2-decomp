#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c1151c4(struct Actor *a,struct ActorSub2a4 *sub)
{
 void (*motion)(struct Actor *,int);int zero;
 a->b3f8=2;a->b328=5;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
 motion=func_0c0344a0;
 if(a->s28==50)motion(a,31);
 zero=0;
 if(!(a->f56<a->f41c+411.42856f)){if(a->w34a&0x1000){if(a->w34e&0x360)a->s28=zero;}}
 if(a->s28--==0){
  a->b6++;sub->b7=1;func_0c02a0c4(a,22,1);
  a->b1a1=52;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  a->f92=-13.33333302f;a->f96=-25.714285f;a->f108=-0.5357143f;if(a->w130)a->f92=-a->f92;
  motion(a,43);motion(a,4);
 }
}
