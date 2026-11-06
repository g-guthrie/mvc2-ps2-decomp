#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0b130c(struct Actor *);
extern void func_0c1a417c(struct Actor *,int);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern void (*table_0c244be0[])(struct Actor *),(*table_0c244bf4[])(struct Actor *);
void func_0c0b24cc(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->b7++;a->b1f9=0;a->f56=a->f41c;func_0c02a0c4(a,1,3);}}
void func_0c0b2542(struct Actor *a){if(func_0c02a026(a)>=0)return;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0437b8(a);}
void func_0c0b2574(struct Actor *a){struct Actor *p=a;table_0c244be0[p->b7](a);}
void func_0c0b2586(struct Actor *a){int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}a->b7++;zero=0;a->b1a1=62;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c0442fa(a);
 if(a->b2)func_0c025900(a,1,4);else func_0c025900(a,1,3);a->s28=16;func_0c02a0c4(a,22,0);}
void func_0c0b25fa(struct Actor *a){struct LinkedActorVec3 v;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(!--a->s28){a->b3f0=0;a->b3f1=0;a->b7++;func_0c02a0c4(a,22,1);a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 v=*(struct LinkedActorVec3 *)((char *)a+52);v.x=-53.3333321f;v.y=205.71428f;func_0c0429a4(a,&v,1);}}
void func_0c0b26b8(struct Actor *a){struct Actor *p=a;table_0c244bf4[p->b6](a);}
void func_0c0b26ca(struct Actor *a){int zero;a->b6++;func_0c0b130c(a);func_0c0432ca(a);zero=0;a->b1a1=73;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,9);func_0c1a417c(a,2);}
