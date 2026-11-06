#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c025900(struct Actor *,int,int),func_0c03edcc(struct Actor *,struct Actor *);
extern void (*table_0c2480bc[])(struct Actor *);
void func_0c0ce064(struct Actor *a){float stopped=0;if(!a->b6){a->b6++;if(a->b1d2)a->f92=-7.5f;else a->f92=7.5f;a->f104=stopped;a->f96=4.28571415f;a->f108=-0.2678571343422f;}if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->b141){struct Actor *child;a->b141=0;child=a->p1c8;child->p1b4=a;child->b1f6=1;child->b1f9=2;func_0c025900(a,0,0);child->b1a1=35;child->b1d2=a->b1d2;}if(!a->b140){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!(a->f56>a->f41c)){a->f56=a->f41c;a->f96=stopped;a->f108=stopped;}}}
void func_0c0ce15c(struct Actor *a){table_0c2480bc[a->b1f7&63](a);}
void func_0c0ce174(struct Actor *a){func_0c03edcc(a->p1c8,a);}
