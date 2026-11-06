#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0451f2(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int);
extern void func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Actor *func_0c1af2b8(struct Actor *,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c248064[])(struct Actor *),(*table_0c24806c[])(struct Actor *);
void func_0c0cd788(struct Actor *);
void func_0c0cd610(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,20,6);a->s28=60;}else{if(--a->s28<=0){func_0c0437b8(a);return;}func_0c02a026(a);}}
void func_0c0cd658(struct Actor *a){table_0c248064[a->b6](a);}
void func_0c0cd66a(struct Actor *a){int zero=0;
 a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1f9=zero;a->f56=a->f41c;func_0c02a39a(a,zero);func_0c0442fa(a);func_0c0432ca(a);
 a->b1a1=89;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,20,11);}
void func_0c0cd6e0(struct Actor *a){struct LinkedActorVec3 point;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141<0){a->b141=0;point.x=38.3333321f;point.y=203.57143f;func_0c043014(a,&point);}
 if(a->b140){float offset=a->b1d2?3.3333333f:-3.3333333f;a->f52+=offset;}}
void func_0c0cd788(struct Actor *a){int zero;if(a->b141){zero=0;a->b141=zero;a->b1a1=83;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}}
void func_0c0cd7bc(struct Actor *a){table_0c24806c[a->b6](a);}
void func_0c0cd7ce(struct Actor *a){int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}a->b6++;func_0c0442fa(a);func_0c0432ca(a);func_0c048bb0(a,3);a->f56=a->f41c;
 a->b1a1=83;zero=0;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,10);}
void func_0c0cd840(struct Actor *a){struct LinkedActorVec3 point;int zero;
 a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141==2){a->b6++;a->s28=45;zero=0;a->s30=zero;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f96=17.142857f;func_0c0451f2(a);func_0c1af2b8(a,1);a->b3f0=zero;a->b3f1=zero;
 /* Retail reads this local XY without an earlier write. */
 point.x+=33.3333321f;point.y+=85.71428f;func_0c0429a4(a,&point,1);}}
void func_0c0cd902(struct Actor *a){int zero;
 a->b3f8=2;a->b328=5;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);func_0c0cd788(a);if(a->b19e)a->s30++;
 if(--a->s28<=0){a->b6++;if(a->s30){a->b1a1=84;zero=0;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,11);}
 else{a->b6++;func_0c02a0c4(a,21,5);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f108=-0.80357140303f;}}}
