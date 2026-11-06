#include "objects.h"
struct ActorFlagBytes150 { char low,high; };
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0437b8(struct Actor *),func_0c1b2e10(struct Actor *,int),func_0c168fe0(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c249e44[])(struct Actor *),(*table_0c249e84[])(struct Actor *),(*table_0c249e8c[])(struct Actor *);
extern void (*table_0c249e94[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0edd04(struct Actor *a)
{
 a->b326=255;if(!(--a->s30)){a->s30=16;a->f96=-a->f96;}a->f56+=a->f96;
}
void func_0c0edd32(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,3);}else func_0c02a026(a);}
void func_0c0edd4c(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,3);}else func_0c02a026(a);}
void func_0c0edd66(struct Actor *a){table_0c249e44[a->b1e9](a);}
void func_0c0edd7a(struct Actor *a){table_0c249e84[a->b6](a);}
void func_0c0edd8c(struct Actor *a)
{
 int zero;float stopped;
 a->b6++;a->b1a1=a->b1a3?56:54;zero=0;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);func_0c0442fa(a);
 stopped=0.0f;a->f56=a->f41c;a->b1f9=zero;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 func_0c0432ca(a);func_0c02a0c4(a,21,zero);
}
void func_0c0ede0e(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(((char *)&a->w150)[1]&1){
  ((char *)&a->w150)[1]&=254;func_0c1b2e10(a,6);
 }
 if(a->b141){int zero=0;a->b141=zero;func_0c168fe0(a,zero);}
}
void func_0c0ede96(struct Actor *a){table_0c249e8c[a->b6](a);}
void func_0c0edea8(struct Actor *a){table_0c249e94[a->b7](a,&a->sub2a4);}
void func_0c0edebe(struct Actor *a,struct ActorSub2a4 *sub)
{
 void *zero;float stopped;
 a->b7++;zero=0;func_0c048bb0(a,10);func_0c0442fa(a);
 stopped=0.0f;a->f56=a->f41c;a->b1f9=(int)zero;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 if(a->b255!=3)a->b1a1=a->b1a3?52:48;else {goto stance;
stance:a->b1a1=66;}
 a->w1ac=(int)zero;a->b19e=(int)zero;*(unsigned int *)&a->p1c4=(unsigned int)zero;
 dat_0c2f83f8->arr[a->b2]++;goto reset;
reset:func_0c0432ca(a);sub->b2=(int)zero;func_0c02a0c4(a,21,1);
}
