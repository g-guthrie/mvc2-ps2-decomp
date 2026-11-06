#include "objects.h"
struct SolEvent4{char b0,b1,event,b3;};
extern void func_0c025900(struct Actor*,char,char),func_0c02a0c4(struct Actor*,int,int),func_0c0442fa(struct Actor*);
extern char func_0c02a026(struct Actor*);
void func_0c0907e0(struct Actor*a,struct SolEvent4 *sub){a->b3f8=2;a->b328=5;if(sub->event<0){a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;a->b6++;a->b7=1;sub->b3=0;func_0c025900(a,0,13);a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->f108=-0.9375f;func_0c02a0c4(a,22,6);}else if(sub->event>0)a->b7++;}
void func_0c090862(struct Actor*a){a->b3f8=2;a->b328=5;if(func_0c02a026(a)<0){struct Actor *child;float offset;a->b7++;a->s28=8;func_0c0442fa(a);child=a->p1c8;offset=53.3333321f;if(a->b1d2)offset=-53.3333321f;a->f92=(child->f52+offset-a->f52)/8.0f;a->f96=(child->f56-a->f56)/8.0f;a->f104=0.0f;a->f108=0.0f;func_0c02a0c4(a,22,1);}}
