#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c1b2e10(struct Actor *,int);
void func_0c0ed96c(struct Actor *a,struct ActorSubControlBytes *p){a->b12c=1;if(func_0c02a026(a)<0){a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f96=-1.875f;func_0c02a0c4(a,18,1);return;}if(a->b141){int zero=0;a->b141=zero;p->b4=zero;func_0c02a39a(a,zero);}}
void func_0c0ed9e2(struct Actor *a){a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(!(a->f56>a->f41c+51.42857f)){a->b6++;func_0c1b2e10(a,13);}}
void func_0c0eda34(struct Actor *a){a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,18,2);}}
void func_0c0eda90(struct Actor *a){if(func_0c02a026(a)<0)a->b5++;}
