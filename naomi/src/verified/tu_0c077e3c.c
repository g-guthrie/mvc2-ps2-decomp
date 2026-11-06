#include "objects.h"
extern void (*table_0c241470[])(struct Actor *);
extern void (*table_0c241494[])(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c048bb0(struct Actor *,int);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c044df4(struct Actor *);
extern void func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *);extern int func_0c13bff4(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
short func_0c077fac(struct Actor *a);
void func_0c077e3c(struct Actor *a){table_0c241470[a->b1e9](a);}
void func_0c077e50(struct Actor *a){table_0c241494[a->b6](a);}
void func_0c077e62(struct Actor *a_)
{
 void *zero=0;
 register struct Actor *a=a_;
 goto LB0_16; LB0_16:
 a->b6++;
 func_0c0344a0(a,20);func_0c0344a0(a,31);func_0c048bb0(a,5);
 if(a->b1f9==2){
  if(a->b255==3)a->b1a1=85;
  else if(a->b1a3)a->b1a1=63;else{goto L;L:a->b1a1=61;}
  a->w1ac=(int)zero;a->b19e=(int)zero;*(void **)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  a->b1f9=2;a->b158=1;
  a->f92/=8.0f;a->f104/=8.0f;a->f96/=8.0f;a->f108/=8.0f;
 }else{
  if(a->b255==3)a->b1a1=85;else{goto L2;L2:a->b1a1=a->b1a3+59;}
  a->w1ac=(int)zero;a->b19e=(int)zero;*(void **)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  func_0c0442fa(a);
  a->b1f9=(int)zero;a->f56=a->f41c;a->b158=(int)zero;
  func_0c0432ca(a);
 }
 func_0c02a0c4(a,21,a->b158);
 func_0c077fac(a);
}
short func_0c077fac(struct Actor *a)
{
 if(!(a->f56<a->f41c)){goto M;M:func_0c044df4(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}
 if(func_0c02a026(a)<0){
  if(a->b1f9==2){a->f92=0;a->f104=0;a->f96+=2.1428571f;a->f108=-0.5357143f;func_0c0438de(a);return;}
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);return;
 }
 goto LB1_43; LB1_43:
 if(a->b141){a->b141=0;{int n;if(a->b1f9==2)n=a->b1a3+3;else n=a->b1a3;return func_0c13bff4(a,n);}}
}
