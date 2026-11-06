#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct Actor *func_0c16c3f0(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24a5bc[])(struct Actor *);
void func_0c0f7638(struct Actor *a)
{
 int zero=0;
 struct Actor *effect;
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b1d4++;func_0c0438de(a);return;
 }
 if(a->b141&1){a->b141&=254;effect=func_0c16c3f0(a,3);if(effect)effect->b33=zero;}
}
void func_0c0f76ac(struct Actor *a)
{
 if(func_0c02a026(a)<0){int zero=0;float stopped=0.0f;
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);
 }
}
void func_0c0f76f0(struct Actor *a){table_0c24a5bc[a->b6](a);}
void func_0c0f7702(struct Actor *a)
{
 int zero;
 a->b6++;func_0c02a0c4(a,21,21);zero=0;
 if(a->b255==3)a->b1a1=76;else {goto normal;
normal:a->b1a1=8;}
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
}
void func_0c0f7756(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
