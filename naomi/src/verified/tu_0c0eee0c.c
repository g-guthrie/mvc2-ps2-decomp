#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c043324(struct Actor *),func_0c1b2e10(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0eee0c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->f56-a->f41c>137.142853f){char cpu=a->b525;
  if((cpu&&a->b1fe)||(!cpu&&(a->w340&0x300))){int zero=0;
   a->b6++;a->b1a1=59;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
   dat_0c2f83f8->arr[a->b2]++;func_0c0442fa(a);
   a->f92=a->b1d2?-13.33333302f:13.33333302f;
   a->f104=a->b1d2?0.625f:-0.625f;a->f96=12.85714245f;a->f108=-0.80357140303f;
   func_0c02a0c4(a,21,14);
  }
 }
 if(!(a->f56>a->f41c)){float stopped=0.0f;
  a->b6=4;a->f56=a->f41c;a->b1f9=1;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c043324(a);func_0c02a0c4(a,21,15);
 }
}
void func_0c0eef70(struct Actor *a)
{

 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->f56>a->f41c){

  if(((char *)&a->w150)[1]){((char *)&a->w150)[1]=0;func_0c1b2e10(a,7);}
  if(!a->b525){if(a->w340&0x800)a->f92=-6.66666651f;else if(a->w340&0x400)a->f92=6.66666651f;}
 }else{
  a->b6++;a->f56=a->f41c;a->b1f9=1;func_0c043324(a);func_0c02a0c4(a,21,15);
 }
}
