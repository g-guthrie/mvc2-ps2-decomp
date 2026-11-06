/* Five linked actor movement callbacks and their fixed-point table. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *),func_0c0439c4(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0451f2(struct Actor *);
extern void (*dat_0c24c25c[])(struct Actor *);
extern const int dat_0c24c268[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c1149c2(struct Actor *,struct ActorSub2a4 *);
void func_0c1147a0(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c044e52(a)){a->b6++;func_0c02a0c4(a,20,1);func_0c043324(a);a->s28=40;}
}
void func_0c11480e(struct Actor *a)
{
 func_0c02a026(a);if(--a->s28==0){func_0c02a39a(a,0);func_0c0439c4(a);}
}
void func_0c11483c(struct Actor *a){dat_0c24c25c[a->b6](a);}
void func_0c11484e(struct Actor *a,struct ActorSub2a4 *sub)
{
 int zero;
 a->b6++;func_0c048bb0(a,5);func_0c0442fa(a);func_0c02a39a(a,0);
 zero=0;
 if(a->b1f9!=2){a->b1f9=zero;func_0c0432ca(a);a->f56=a->f41c;
  if(a->b1a3==0)a->b33=zero;else a->b33=1;
 }else{
  if(!a->b1a3)a->b33=2;else a->b33=3;
 }
 a->b1a1=(char)a->b1a3+48;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,(char)a->b1a3);
 a->f92=(float)dat_0c24c268[a->b33*4]*1.66666663f/65536.0f;
 a->f104=(float)(dat_0c24c268+a->b33*4)[1]*1.66666663f/65536.0f;
 a->f96=(float)(dat_0c24c268+a->b33*4)[2]*2.1428571f/65536.0f;
 a->f108=(float)(dat_0c24c268+a->b33*4)[3]*2.1428571f/65536.0f;
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 ((char *)sub)[10]=zero;func_0c1149c2(a,sub);
}
void func_0c1149c2(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);
 if(a->b141){int zero=0;a->b141=zero;a->b6++;((char *)sub)[10]=1;a->s30=zero;
  if(a->b33==1)func_0c0451f2(a);
 }
}
