#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c1b4f20(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct LinkedActor *func_0c1b54dc(struct LinkedActor *,int,int);
void func_0c0fe8f0(struct Actor *a)
{
 int zero;
 a->b3f8=2;a->b328=5;a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);
 zero=0;
 if(a->b141){
  a->b141=zero;a->f92=-43.3333321f;a->f104=0.0f;if(a->b1d2)a->f92=-a->f92;
  a->b1a1=56;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c1b4f20(a);func_0c1b54dc((struct LinkedActor *)a,0,0);func_0c1b54dc((struct LinkedActor *)a,0,1);func_0c1b54dc((struct LinkedActor *)a,1,0);func_0c1b54dc((struct LinkedActor *)a,1,1);
 }
 if(--a->s28==0){
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;a->b7=zero;
  a->f92=-6.66666651f;a->f104=0.20833333f;
  if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
  func_0c02a0c4(a,22,8);
 }
}
