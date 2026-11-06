#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a18c(struct Actor *,int,int,int),func_0c0451f2(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct ActorVec2 table_0c24a82c[];
void func_0c0f9a30(struct Actor *a)
{
 int zero=0;int attack;
 a->b6++;((unsigned char *)a)[0x2a9]=zero;func_0c0442fa(a);
 if(a->b1f9!=2){func_0c0432ca(a);func_0c02a0c4(a,21,(unsigned char)a->b1a3*2+18);}
 else func_0c02a18c(a,21,(unsigned char)a->b1a3*2+18,1);
 attack=a->b1a3?61:59;a->b1a1=attack;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
}
void func_0c0f9abc(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;func_0c0451f2(a);
  a->f96=table_0c24a82c[(unsigned char)a->b1a3].y;a->f108=-2.1428571f;
  a->f92=table_0c24a82c[(unsigned char)a->b1a3].x;a->f104=-0.00837053545f;
  if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 }
}
