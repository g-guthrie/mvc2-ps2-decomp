#include "objects.h"
struct Pos_0cdc4c {float x,y,z;};
extern void func_0c025900(struct Actor *,int,int),func_0c1d4610(struct Actor *,struct Pos_0cdc4c *),func_0c048ce6(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
void func_0c0cdc4c(struct Actor *a){struct Pos_0cdc4c v;a->b1d2^=1;a->w130=(unsigned char)a->b1d2;if(!(a->b34&2)){a->b1d2^=1;a->w130=(unsigned char)a->b1d2;}func_0c025900(a,5,5);v.x=-83.33333f;v.y=158.57143f;func_0c1d4610(a,&v);a->b1a0=10;func_0c048ce6(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c02a0c4(a,15,0);}
void func_0c0cdcd0(struct Actor *a){struct Pos_0cdc4c v;a->b1d2^=1;a->w130=(unsigned char)a->b1d2;if(!(a->b34&2)){a->b1d2^=1;a->w130=(unsigned char)a->b1d2;}func_0c025900(a,5,5);v.x=-83.33333f;v.y=158.57143f;func_0c1d4610(a,&v);a->b1a0=10;func_0c048ce6(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c02a0c4(a,15,1);}
void func_0c0cdd54(struct Actor *a){struct Pos_0cdc4c v;func_0c025900(a,5,5);v.x=-83.33333f;v.y=158.57143f;func_0c1d4610(a,&v);a->b1a0=10;func_0c048ce6(a);a->b6=0;func_0c02a0c4(a,15,4);}
