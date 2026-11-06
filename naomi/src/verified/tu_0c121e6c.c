/* Thirteen connected callbacks and three reviewed pools. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1bc740(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c043352(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24d56c[])(struct Actor *),(*dat_0c24d574[])(struct Actor *),(*dat_0c24d580[])(struct Actor *);
void func_0c12203e(struct Actor *),func_0c122080(struct Actor *),func_0c1220a2(struct Actor *);
void func_0c121e6c(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141&2){a->b141&=(unsigned char)~2;func_0c1bc740(a,9,0);}
 if(a->b141&4){a->b141&=(unsigned char)~4;func_0c1bc740(a,9,1);}
 if(a->b141&8){int zero=0;a->b141&=(unsigned char)~8;
  a->b1a1=26;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
 if(!(a->f41c<a->f56)){
  a->f56=a->f41c;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
  func_0c0437b8(a);
 }
}
void func_0c121f20(struct Actor *a){dat_0c24d56c[a->b6](a);}
void func_0c121f32(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b6++;a->f92=-15.0f;a->f104=.4427083135f;
  if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}
  a->s28=24;
 }
}
void func_0c121f7c(struct Actor *a)
{
 func_0c043352(a);func_0c02a026(a);
 if(a->s28--==0){a->b6++;func_0c02a0c4(a,10,3);}
}
void func_0c121fde(struct Actor *a)
{
 func_0c043352(a);
 if(func_0c02a026(a)<0){a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0437b8(a);}
}
void func_0c122016(struct Actor *a){dat_0c24d574[a->b6](a);}
void func_0c122028(struct Actor *a)
{
 func_0c0421f4(a);func_0c0420f8(a);func_0c12203e(a);
}
void func_0c12203e(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);
 if((unsigned char)a->b1fe==1)func_0c1220a2(a);else func_0c122080(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c122080(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c1220a2(struct Actor *a){dat_0c24d580[a->b1e8](a);}
void func_0c1220b6(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c1220d8(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}
 if(a->b141&2){a->b141&=(unsigned char)~2;func_0c1bc740(a,9,5);}
}
void func_0c122150(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}
 if(a->b141&2){a->b141&=(unsigned char)~2;func_0c1bc740(a,9,6);}
 if(a->b141&4){a->b141&=(unsigned char)~4;func_0c1bc740(a,9,7);}
 if(a->b141&8){int zero=0;a->b141&=(unsigned char)~8;
  a->b1a1=27;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
}
