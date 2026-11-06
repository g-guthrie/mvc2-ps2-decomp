#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c04bfe0(struct Actor *),func_0c04ac78(struct Actor *),func_0c040b08(struct Actor *),func_0c040b3a(struct Actor *),func_0c03cbee(struct Actor *),func_0c04a730(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c23bb48[])(struct Actor *);
void func_0c03df98(struct Actor *);
void func_0c03dec4(struct Actor *a){float stopped;a->b6++;a->b23a++;func_0c04bfe0(a);a->p1bc=a->p1c8->p174+(a->b1a1&127)*28;func_0c04ac78(a);a->b239=a->b232;a->w130=a->b1d2;a->b1f9=2;if(a->b1a1&128){a->b22e=a->p1c8->b34;if(a->p1c8->w130)a->b22e=(32-a->b22e)&31;}a->b12c=1;a->i72=0;*(struct LinkedActorVec3 *)((char*)a+80)=*(struct LinkedActorVec3 *)((char*)a+0x284);a->f264=1.0f;func_0c040b08(a);stopped=0;a->f92=stopped;a->f104=stopped;a->f96=2.1428571f;a->f108=-0.016741071f;a->s28=0;func_0c03df98(a);}
void func_0c03df98(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!a->s28&&!(a->f96>0)){a->s28=1;func_0c040b3a(a);}if(a->b233!=2&&--a->b239<0&&a->w420){a->b6=3;*(char *)&a->b1d6=-1;a->b1fc=1;func_0c02a0c4(a,13,30);func_0c03cbee(a);return;}if(!(a->f96>0)&&func_0c044e52(a)){a->b6++;a->b1eb=2;a->s278=5;a->b1f9=2;func_0c02a0c4(a,13,26);}}
void func_0c03e0ba(struct Actor *a){table_0c23bb48[a->b6](a);}
void func_0c03e0cc(struct Actor *a){unsigned char zero=0;a->b6++;a->b23a++;a->b238=zero;func_0c04bfe0(a);a->p1bc=a->p1c8->p174+(a->b1a1&127)*28;func_0c04ac78(a);if(((struct AnimationFrame20 *)a->p1bc)->event&32)a->b235=1;a->b239=a->b232;a->w130=a->b1d2;a->b1f9=2;a->b12c=1;a->i72=zero;*(struct LinkedActorVec3 *)((char*)a+80)=*(struct LinkedActorVec3 *)((char*)a+0x284);a->f264=1.0f;func_0c040b08(a);func_0c04a730(a);a->f92=a->f218;a->f96=a->f21c;a->f108=-1.2053571f;a->s28=zero;a->s30=320;}
