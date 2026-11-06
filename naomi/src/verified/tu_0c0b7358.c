#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1a72d4(struct Actor *,int);
extern struct Actor *func_0c157dcc(struct Actor *,unsigned char,unsigned char),*func_0c158084(struct Actor *,unsigned char),*func_0c1a7302(struct Actor *,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2450dc[])(struct Actor *),(*table_0c2450f0[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0b743a(struct Actor *),func_0c0b76f8(struct Actor *,struct ActorSub2a4 *);
void func_0c0b7358(struct Actor *a){if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->b141){a->b328=5;if(a->b142&1)func_0c157dcc(a,0,0);}}
void func_0c0b739c(struct Actor *a){table_0c2450dc[a->b6](a);}
void func_0c0b73ae(struct Actor *a){int zero;
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;zero=0;a->f56=a->f41c;a->b1fc=zero;a->b1f9=zero;func_0c048bb0(a,5);
 a->b1a1=50;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,2);func_0c1a72d4(a,zero);func_0c0432ca(a);func_0c0b743a(a);
}
void func_0c0b743a(struct Actor *a){int zero;func_0c02a026(a);if(a->b141){a->b6++;zero=0;a->b141=zero;func_0c158084(a,0);}
 if(a->w150){if(!a->w130)a->f52+=*(short *)&a->w150*1.66666663f;else a->f52-=*(short *)&a->w150*1.66666663f;a->w150=0;}}
void func_0c0b74ec(struct Actor *a){int zero;func_0c02a026(a);if(a->b141){a->b6++;zero=0;a->b141=zero;func_0c158084(a,1);}
 if(a->w150){if(!a->w130)a->f52+=*(short *)&a->w150*1.66666663f;else a->f52-=*(short *)&a->w150*1.66666663f;a->w150=0;}}
void func_0c0b755a(struct Actor *a){int zero;func_0c02a026(a);if(a->b141){a->b6++;zero=0;a->b141=zero;func_0c158084(a,2);}
 if(a->w150){if(!a->w130)a->f52+=*(short *)&a->w150*1.66666663f;else a->f52-=*(short *)&a->w150*1.66666663f;a->w150=0;}}
void func_0c0b75c8(struct Actor *a){if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->w150){if(!a->w130)a->f52+=*(short *)&a->w150*1.66666663f;else a->f52-=*(short *)&a->w150*1.66666663f;a->w150=0;}}
void func_0c0b7640(struct Actor *a){table_0c2450f0[a->b6](a,&a->sub2a4);}
void func_0c0b7656(struct Actor *a,struct ActorSub2a4 *context){int zero;
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;zero=0;a->f56=a->f41c;a->b1fc=zero;a->b1f9=zero;context->b0=a->b525?12:24;a->s28=64;func_0c048bb0(a,5);
 a->b1a1=53;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,3);func_0c0432ca(a);func_0c0b76f8(a,context);}
void func_0c0b76f8(struct Actor *a,struct ActorSub2a4 *context){func_0c02a026(a);if(a->b140){a->b6++;a->b140=0;func_0c1a7302(a,10);func_0c1a7302(a,11);func_0c1a7302(a,12);}}
