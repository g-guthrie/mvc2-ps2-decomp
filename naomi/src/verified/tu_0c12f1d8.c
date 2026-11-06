/* Four movement callbacks, including their shared trigger path. */
#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c189224(struct Actor *,int,int),func_0c043324(struct Actor *),func_0c13150c(struct Actor *),func_0c0438de(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24e144[])(struct Actor *);
void func_0c12f1d8(struct Actor *a)
{
 int zero;
  a->b6++;func_0c0442fa(a);zero=0;
 if(a->b1f9!=2){a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->b1f9=zero;func_0c0432ca(a);}
 else{a->f92/=16.0f;a->f96/=8.0f;a->f108/=64.0f;a->f104=0.0f;}
 func_0c048bb0(a,5);a->s28=1;a->b1a1=48;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,(char)a->b1a3+3);
}
void func_0c12f28a(struct Actor *a)
{
 int remembered;
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->b140){int mask=512;if(a->b1a3)mask=256;
  if(!(a->w34a&mask)){remembered=a->b14b;func_0c02a0c4(a,21,(char)a->b1a3+14);goto triggered;}
 }
 if(a->b141){remembered=a->b14b;
triggered:
  a->b6++;a->b141=0;func_0c189224(a,(unsigned char)a->b1a3,remembered);
 }
 if(a->f56<a->f41c && a->b1f9==2){
  a->f56=a->f41c;a->b1f9=0;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c043324(a);
 }
}
void func_0c12f3ae(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){a->f56=a->f41c;a->b1f9=0;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c043324(a);}
 if(func_0c02a026(a)<0){if(a->b1f9!=2)func_0c13150c(a);else func_0c0438de(a);}
}
void func_0c12f44e(struct Actor *a){dat_0c24e144[a->b6](a);}
