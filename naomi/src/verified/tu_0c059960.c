#include "objects.h"
extern void (*table_0c23f908[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c056bb8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern char func_0c02a026(struct Actor *);
void func_0c059960(struct Actor *a)
{
 table_0c23f908[a->b6](a);
}
void func_0c059972(struct Actor *a)
{
 a->b6++;a->b1a1=55;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c056bb8(a);a->f92=4.16666651f;a->f104=0.0f;
 if(!a->b1d2)a->f92=-a->f92;
 func_0c02a0c4(a,21,8);
}
void func_0c0599d6(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(((char *)&a->w150)[1]){
 ((char *)&a->w150)[1]=0;
 position.x=-40.0f;position.y=154.28571f;
 func_0c0429a4(a,&position,1);return;
 }
 {
 a->b328=5;
 if(a->b141==1){a->b141=0;a->b1a1=55;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}
 if(a->b141==2){a->b141=0;a->b1a1=56;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,24,4);}
 }
}
