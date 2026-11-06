#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c02a39a(struct Actor *,int),func_0c047bbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c0437b8(struct Actor *),func_0c044df4(struct Actor *),func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c139ff0(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c240e50[])(struct Actor *),(*table_0c240e68[])(struct Actor *);
void func_0c06ff3e(struct Actor *);
void func_0c06fe88(struct Actor *a,struct ActorSub2a4 *s){((struct ActorSubByteState *)s)->b4=255;func_0c02a026(a);if(--a->s28<0){a->b6++;((struct ActorSubByteState *)s)->b4=0;func_0c02a39a(a,0);func_0c02a0c4(a,22,6);}}
void func_0c06fed6(struct Actor *a){if(func_0c02a026(a)<0){func_0c0344a0(a,43);a->b1f9=0;func_0c0437b8(a);}}
void func_0c06ff04(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;func_0c044df4(a);table_0c240e50[a->b6](a);}
void func_0c06ff3e(struct Actor *a){int zero;a->f92=13.33333302f;a->f104=-0.41666666f;zero=0;if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}a->w350=zero;a->w352=zero;a->s28=zero;}
void func_0c06ff78(struct Actor *a){int zero=0;a->b6++;a->b1f9=zero;func_0c02a39a(a,zero);func_0c0442fa(a);func_0c06ff3e(a);func_0c048bb0(a,10);a->b1a1=59;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c0432ca(a);func_0c02a0c4(a,20,9);}
void func_0c070020(struct Actor *a){int zero=0;if(func_0c02a026(a)>=0){if(a->b140){a->b140=zero;a->b1a1=59;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}if(a->b141){if(func_0c047bbe(a)||((a->w34e|a->w352)&864))a->s28=1;}}else{if(!a->s28){a->b6=5;func_0c02a0c4(a,20,16);}else{a->b6++;func_0c06ff3e(a);a->b1a1=60;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,20,10);}}}
void func_0c070108(struct Actor *a){int zero=0;if(func_0c02a026(a)>=0){if(a->b140){a->b140=zero;a->b1a1=59;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}if(a->b141){if(func_0c047bbe(a)||((a->w34e|a->w352)&864))a->s28=1;}}else{if(!a->s28){a->b6=5;func_0c02a0c4(a,20,16);}else{a->b6++;func_0c06ff3e(a);a->b1a1=61;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,20,11);}}}
void func_0c0701d6(struct Actor *a){if(func_0c02a026(a)>=0){if(a->b141){if(func_0c047bbe(a)||((a->w34e|a->w352)&864))a->s28=1;}}else{if(!a->s28){a->b6=5;func_0c02a0c4(a,20,16);}else{a->b6++;func_0c06ff3e(a);a->b1a1=62;a->w1ac=0;a->b19e=0;*(unsigned int*)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,20,12);}}}
void func_0c070288(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);else if(a->b141){a->b141=0;func_0c139ff0(a,3);}}
void func_0c0702c0(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0702e2(struct Actor *a){table_0c240e68[a->b6](a);}
void func_0c0702f4(struct Actor *a){int zero=0;float stopped=0;a->b6++;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->b1f9=zero;a->f56=a->f41c;func_0c02a39a(a,zero);func_0c0442fa(a);func_0c0432ca(a);a->b1a1=67;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,47);}
