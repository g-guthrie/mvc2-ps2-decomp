#include "objects.h"
extern int func_0c02849a(void);
extern void func_0c1bb838(struct Actor *,int,float,float),func_0c037d0c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c181bb4(struct Actor *a)
{
 float x=a->f52+((func_0c02849a()&62)-32)*1.66666663f;
 func_0c1bb838(a,256,x,a->f56);
 if(func_0c02a026(a)<0){
 float velocity,acceleration;
 a->b5++;a->s28=20;velocity=-7.5f;acceleration=-0.20833333f;
 if(a->w130){velocity=7.5f;acceleration=0.20833333f;}
 a->f92=velocity;a->f104=acceleration;
 }else if(a->b141){a->b141=0;a->b19e=0;}
 func_0c037d0c(a);
}
void func_0c181c2e(struct Actor *a)
{
 if(--a->s28<0){
 unsigned char state=59;
 a->b5++;a->s30=(short)0xc000;if(a->b33)state=60;a->b1a1=state;
 a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 }
 func_0c037d0c(a);
}
