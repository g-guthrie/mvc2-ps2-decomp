#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c025900(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c104148(struct Actor *a)
{
 int zero=0;
 struct Actor *parent;
 a->b1ea=1;a->b1f2=3;
 if(!(a->f96<0.0f)){a->f56+=a->f96;a->f96+=a->f108;}
 if(func_0c02a026(a)<0){
  a->b7++;a->f96=-23.57143f;a->f108=0.0f;a->b1a1=56;
  a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,21,15);return;
 }
 else if(a->b141){
  a->b141=zero;a->b34=16;a->b1ea=zero;
  parent=a->p1c8;parent->p1b4=a;parent->b1f6=1;parent->b1d2=a->b1d2;parent->b1a1=35;parent->b236=zero;
  func_0c025900(a,0,0);
 }
}
