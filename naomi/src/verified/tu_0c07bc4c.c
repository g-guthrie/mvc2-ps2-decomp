#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *),func_0c13d06c(struct Actor *,int),func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c241718[])(struct Actor *);
void func_0c07bd3e(struct Actor *);
void func_0c07bc4c(struct Actor *a)
{
 int zero;
 a->b6++;func_0c0442fa(a);zero=0;
 if(a->b1f9==2){
 a->b1a1=a->b1a3+50;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c048bb0(a,5);a->f92/=8.0f;a->f96/=8.0f;a->f104/=8.0f;a->f108/=8.0f;a->s30=2;
 }else{
 a->b1a1=a->b1a3+48;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c048bb0(a,5);a->f56=a->f41c;func_0c0432ca(a);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->s30=zero;
 }
 func_0c02a0c4(a,21,0);func_0c07bd3e(a);
}
void func_0c07bd3e(struct Actor *a)
{
 if(a->b1f9==2){
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->f56=a->f41c;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c043324(a);a->b1f9=0;}
 }
 if(a->b141){a->b141=0;{int argument=a->s30;argument+=a->b1a3;func_0c13d06c(a,argument);}}
 if(func_0c02a026(a)<0){if(a->b1f9==2){a->f108=-0.80357140303f;func_0c0438de(a);}else func_0c0437b8(a);}
}
void func_0c07be0c(struct Actor *a)
{
 table_0c241718[a->b6](a);
}
