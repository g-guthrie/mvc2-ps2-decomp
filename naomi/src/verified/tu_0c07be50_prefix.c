#include "objects.h"
typedef void (*ActorCallback)(struct Actor *);
extern ActorCallback table_0c241724[],table_0c241738[],table_0c241740[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c13cc48(struct Actor *),func_0c1925b4(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c13d8e0(struct Actor *,int),func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c02a18c(struct Actor *,int,int,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
void func_0c07bed4(struct Actor *),func_0c07c0ac(struct Actor *),func_0c07c306(struct Actor *);
void func_0c07be50(struct Actor *a){a->b6++;func_0c0442fa(a);a->f56=a->f41c;a->b1f9=0;func_0c0432ca(a);a->b1a1=a->b1a3+52;a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);func_0c02a0c4(a,21,a->b1a3+6);a->s28=40;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c07bed4(a);}
void func_0c07bed4(struct Actor*a){if(--a->s28<=0){a->b6++;func_0c02a0c4(a,21,a->b1a3+10);return;}func_0c02a026(a);if(a->b141){func_0c13d8e0(a,a->b1a3);a->b141=0;}}
void func_0c07bf22(struct Actor*a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c07bf44(struct Actor*a){table_0c241724[a->b6](a);}
void func_0c07bf56(struct Actor*a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(a->f56<=a->f41c){a->f56=a->f41c;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;}}
