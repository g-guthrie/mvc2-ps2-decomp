#include "objects.h"
struct Pos_0d2444 {float x,y,z;};
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int),func_0c1ceafe(struct Actor *,struct Pos_0d2444 *),func_0c0346da(struct Actor *,int),func_0c1cea66(struct Actor *,struct Pos_0d2444 *,int),func_0c0348ca(struct Actor *),func_0c0437b8(struct Actor *);
void func_0c0d2444(struct Actor *a){struct Pos_0d2444 v;float x;if(func_0c02a026(a)<0){func_0c025900(a,0,0);a->b6++;a->f92=2.91666651f;a->f104=0;a->f96=10.714285f;a->f108=-0.66964281f;if(!a->w130)a->f92=-a->f92;a->p1c8->p1b4=a;a->p1c8->b1f6=1;a->p1c8->b1a1=32;func_0c02a0c4(a,15,1);}x=45.0f;if(a->b141&1){a->b141=0;v.x=x;v.y=145.71428f;func_0c1ceafe(a,&v);}if(a->b141&2){a->b141=0;func_0c0346da(a,6);v.x=x;v.y=154.28571f;func_0c1cea66(a,&v,9);}}
void func_0c0d2514(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(a->f96<0 && a->f41c>a->f56){a->f56=a->f41c;func_0c0348ca(a);func_0c0437b8(a);}}
