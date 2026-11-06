#include "objects.h"
struct Pos_0de22c {float x,y,z;};
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1b1910(struct Actor *,int),func_0c0429a4(struct Actor *,struct Pos_0de22c *,int);
extern char func_0c02a026(struct Actor *);
void func_0c0de22c(struct Actor *a){int zero=0;if(a->b255==6){a->b3f0=255;a->b3f1=16;}a->b1f9=zero;a->b6++;func_0c0442fa(a);func_0c02a39a(a,zero);func_0c0432ca(a);a->s28=48;if(a->b525)a->sub2a4.b21=24;else a->sub2a4.b21=16;a->b1a1=85;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,12);func_0c1b1910(a,10);}
void func_0c0de2c0(struct Actor *a){struct Pos_0de22c v;a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);if(a->b141&1){a->b141&=254;a->b6++;a->b3f0=0;a->b3f1=0;v.x=13.33333302f;v.y=122.142853f;v.z=0;func_0c0429a4(a,&v,1);}}
