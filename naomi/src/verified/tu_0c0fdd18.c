#include "objects.h"
extern struct ActorVec2 dat_0c24abec[];
extern char func_0c02a026(struct Actor *);
extern void func_0c1b4f20(struct Actor *),func_0c1b5070(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,unsigned char);
void func_0c0fdd18(struct Actor *a)
{
 char n;float f;
 a->b1f5=2;
 if(a->b141){
  a->b141=0;a->f92=dat_0c24abec[(unsigned char)a->b1a3].x;a->f104=dat_0c24abec[(unsigned char)a->b1a3].y;
  if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
  func_0c1b4f20(a);func_0c1b5070(a,1,0);func_0c1b5070(a,1,1);
 }
 if(a->b19e&&(a->b19e&1))a->s28=1;
 func_0c02a026(a);
 if(--a->s28==0){
  a->b6++;a->b1f5=0;f=0.20833333f;
  if(a->b19e&&!(a->b19e&1)){a->f92=-8.33333302f;a->f104=f;n=3;}
  else{a->f92=-5.0f;n=4;a->f104=f;}
  if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
  func_0c02a0c4(a,21,n);
 }
 a->f52+=a->f92;a->f92+=a->f104;
}
