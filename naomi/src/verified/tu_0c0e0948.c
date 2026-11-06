#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c167a38(struct Actor *,int),func_0c0437b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c2491d4[])(struct Actor *);
void func_0c0e0948(struct Actor *a)
{
 int zero;
 a->b6++;func_0c0442fa(a);
 zero=0;a->b1f9=zero;func_0c0432ca(a);func_0c048bb0(a,8);
 if(a->b255==3)a->b1a1=50;else {goto strength;
strength:a->b1a1=a->b1a3+48;}
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
 goto call;
call:func_0c02a0c4(a,21,0);
}
void func_0c0e09ba(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){int zero=0;a->b6++;a->b141=zero;func_0c167a38(a,zero);}
}
void func_0c0e09ea(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0e0a0c(struct Actor *a){table_0c2491d4[a->b6](a);}
