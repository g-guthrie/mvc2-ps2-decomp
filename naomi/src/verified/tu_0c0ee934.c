#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0ee934(struct Actor *a)
{
 if(func_0c02a026(a)<0){
  a->b6++;func_0c0442fa(a);
  if(!a->b525){if(a->w340&0x800)a->b1d2=a->w130=0;else if(a->w340&0x400)a->b1d2=a->w130=1;}
  a->f92=a->b1d2?-6.66666651f:6.66666651f;
  a->f104=a->b1d2?0.20833333f:-0.20833333f;
  a->f96=21.42857f;a->f108=-0.80357140303f;
  func_0c02a0c4(a,21,10);
 }
}
void func_0c0ee9d4(struct Actor *a)
{
 if(a->f56-a->f41c>137.142853f && a->f96<0.0f){
  char cpu=a->b525;
  if((cpu&&a->b1fe)||(!cpu&&(a->w340&0x300))){a->b6++;a->s28=10;return;}
 }
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->f56>a->f41c){
  if(!a->b525){if(a->w340&0x800)a->f92=-5.0f;else if(a->w340&0x400)a->f92=5.0f;}
 }else{
  float stopped=0.0f;
  a->b6=8;a->f56=a->f41c;a->b1f9=1;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c043324(a);func_0c02a0c4(a,21,12);
 }
}
void func_0c0eeb1e(struct Actor *a)
{
 if(--a->s28)func_0c02a026(a);
 else{int zero=0;
  a->b6++;a->b1a1=58;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,11);
 }
}
