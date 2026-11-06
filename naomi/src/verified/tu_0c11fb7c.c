#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c120c24(struct Actor *),func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1824c0(struct Actor *),func_0c1c00bc(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c02a684(struct Actor *,int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24d39c[])(struct Actor *);
void func_0c11fb7c(struct Actor *a){if(func_0c02a026(a)<0)func_0c120c24(a);}
void func_0c11fb9e(struct Actor *a)
{
 int zero=0;
 if(!a->b6){a->b6++;a->s28=17;a->b1f9=zero;func_0c0442fa(a);func_0c048bb0(a,5);func_0c0432ca(a);
  a->b1a1=51;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,a->b1a3+6);}
 if(func_0c02a026(a)<0){func_0c120c24(a);return;}
 if(a->b141&1){func_0c1824c0(a);if(!*(int *)((char *)a+0x2b8))func_0c1c00bc(a);func_0c0344a0(a,34);a->b27b=zero;a->b27a=16;}
 a->b141&=-2;
 if(a->b140){a->s28^=7;if((char)a->b140&1){goto event;event:func_0c02a684(a,1,a->s28,1);}}
}
void func_0c11fc84(struct Actor *a){*(int *)((char *)a+0x2c0)=4;table_0c24d39c[a->b6](a);}
