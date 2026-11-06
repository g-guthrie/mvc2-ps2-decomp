#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int);
void func_0c0d66b4(struct Actor *a){struct Actor *child;func_0c02a026(a);if(a->b141){a->b6++;a->b141=0;child=a->p1c8;child->p1b4=a;child->b1f6=1;child->b1a1=36;func_0c025900(a,0,0);}}
void func_0c0d66fa(struct Actor *a){func_0c02a026(a);if(a->b141){a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;if(a->b1d2)a->f92=-3.3333333f;else a->f92=3.3333333f;a->f108=-0.9375f;if(a->b1d2)a->f52-=40.0f;else a->f52+=40.0f;a->f56+=25.714285f;}}
void func_0c0d6772(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,15,5);}}
