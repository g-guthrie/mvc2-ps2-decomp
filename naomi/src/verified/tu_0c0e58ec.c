#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0e58ec(struct Actor *a)
{
 int zero;
 unsigned char direction;
 float stopped;
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 zero=0;
 if(a->b14b){
  a->b1a1=65;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 direction=a->b1d2;stopped=0.0f;
 if((!direction && a->f92>0.0f)||(direction && a->f92<0.0f)){a->f92=stopped;a->f104=stopped;}
 if(a->f96>0.0f)return;
 a->b6++;a->f92=stopped;a->f104=stopped;
 a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
 func_0c02a0c4(a,21,17);
}
