#include "objects.h"
struct Pos_0d9ac4 {float x,y,z;};
extern void func_0c1d4610(struct Actor *,struct Pos_0d9ac4 *),func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int);
void func_0c0d9ac4(struct Actor *a){struct Pos_0d9ac4 v;struct Actor *child;child=a->p1c8;child->b1d2=child->w130=(unsigned char)a->b1d2^1;if(a->b34&1){a->b1d2=a->w130=(unsigned char)a->b1d2^1;child=a->p1c8;child->b1d2=child->w130=(unsigned char)a->b1d2^1;}v.x=33.3333321f;v.y=195.0f;v.z=0;func_0c1d4610(a,&v);a->b1a0=10;func_0c025900(a,5,5);func_0c02a0c4(a,15,0);}
void func_0c0d9b58(struct Actor *a){struct Pos_0d9ac4 v;struct Actor *child;child=a->p1c8;child->b1d2=child->w130=(unsigned char)a->b1d2^1;v.x=-80.0f;v.y=184.28571f;v.z=0;func_0c1d4610(a,&v);a->b1a0=10;func_0c025900(a,5,5);func_0c02a0c4(a,15,1);}
void func_0c0d9bb6(struct Actor *a){struct Pos_0d9ac4 v;struct Actor *child;child=a->p1c8;child->b1d2=child->w130=(unsigned char)a->b1d2^1;v.x=-23.3333321f;v.y=229.28571f;v.z=0;func_0c1d4610(a,&v);a->b1a0=10;func_0c025900(a,5,5);func_0c02a0c4(a,15,2);}
