#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *),func_0c15ccc8(struct Actor *,int),func_0c1a9cf0(struct Actor *,int);
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c048bb0(struct Actor *,int),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
void func_0c0c0e08(struct Actor *a)
{if(func_0c02a026(a)<0){func_0c0438de(a);return;} if(a->b1e8==2){goto L;L:if(a->b141){a->b141=0;func_0c15ccc8(a,2);func_0c1a9cf0(a,2);}}}
void func_0c0c0e52(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c0c0e74(struct Actor *a){if(!a->b6){int zero;func_0c044cbc(a);zero=0;a->b6++;a->b1a1=22;a->b1f9=zero;func_0c02a0c4(a,20,3);a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);}if(a->b1ff==3)func_0c043352(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);}
