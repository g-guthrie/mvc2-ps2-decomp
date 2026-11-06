#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c249f5c[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0ef06c(struct Actor *a){if(func_0c02a026(a)>=0)return;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
void func_0c0ef09e(struct Actor *a){table_0c249f5c[a->b6](a,&a->sub2a4);}
void func_0c0ef0b4(struct Actor *a,struct ActorSubControlBytes *p){if(a->b255==6){a->b3f0=255;a->b3f1=16;}a->b6++;func_0c0442fa(a);a->f56=a->f41c;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0344a0(a,22);func_0c0432ca(a);p->b12=0;func_0c02a0c4(a,21,16);}
void func_0c0ef124(struct Actor *a,struct ActorSubControlBytes *p){a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;if(((char *)&a->w150)[1])p->b4=1;if(a->b141==2)a->b141=0;if(func_0c02a026(a)<0){a->b6++;a->s28=2;a->b12c=0;a->b1f5=1;}}
