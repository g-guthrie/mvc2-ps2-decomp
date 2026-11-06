#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void (*table_0c249f14[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0ee318(struct Actor *a,struct ActorSubControlBytes *p){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(!p->b2 && a->b19e){p->b2=1;func_0c0344a0(a,3);}if(a->b141){a->b141=0;a->b1a1=a->b1a3?43:41;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;}if(!(a->f56>a->f41c)){a->b7++;a->f56=a->f41c;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c043324(a);func_0c02a0c4(a,21,4);}}
void func_0c0ee408(struct Actor *a){table_0c249f14[a->b6](a,&a->sub2a4);}
void func_0c0ee41e(struct Actor *a){a->b6++;func_0c048bb0(a,2);func_0c0442fa(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;if(a->b1f9!=2)func_0c0432ca(a);func_0c02a0c4(a,21,5);}
