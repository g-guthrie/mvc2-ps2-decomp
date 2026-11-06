#include "objects.h"
extern int func_0c047bbe(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0e714c(struct Actor *a)
{
 int zero;
 a->b3f8=2;a->b328=5;
 if(func_0c047bbe(a))a->b142=1;
 func_0c02a026(a);a->f56+=a->f96;a->f96+=a->f108;
 zero=0;
 if(!(a->f96>4.28571415f)){
  a->b6++;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
  a->f108=-0.066964284f;a->s28=zero;
  a->b1a1=100;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;a->w1ac=zero;
  func_0c02a0c4(a,22,16);
 }else {goto event;
event:if(a->b14b){
  a->b14b=zero;a->b1a1=99;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;a->w1ac=16;
 }}
}
void func_0c0e7232(struct Actor *a)
{
 if((a->s28=(a->s28+1)&1))func_0c02a026(a);
 a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f96>2.1428571f)){a->b6++;goto acceleration;
acceleration:a->f108=-0.7366071343422f;}
}
