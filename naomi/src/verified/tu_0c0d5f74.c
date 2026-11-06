#include "objects.h"
struct Position_0d5f74 {float x,y,z;};
extern void func_0c025900(struct Actor *,int,int),func_0c048ce6(struct Actor *),func_0c1d4610(struct Actor *,struct Position_0d5f74 *),func_0c02a0c4(struct Actor *,int,int);
void func_0c0d5f74(struct Actor *a){struct Position_0d5f74 v;func_0c025900(a,6,6);func_0c048ce6(a);a->b1a0=10;v.x=-80.0f;v.y=128.57143f;v.z=0;func_0c1d4610(a,&v);func_0c02a0c4(a,15,0);}
void func_0c0d5fbe(struct Actor *a){struct Position_0d5f74 v;func_0c025900(a,5,5);func_0c048ce6(a);a->b1a0=10;v.x=-80.0f;v.y=128.57143f;v.z=0;func_0c1d4610(a,&v);func_0c02a0c4(a,15,2);}
void func_0c0d6008(struct Actor *a){struct Position_0d5f74 v;func_0c025900(a,5,5);func_0c048ce6(a);a->b1a0=10;v.x=-55.0f;v.y=117.85714f;v.z=0;func_0c1d4610(a,&v);if(!(a->b34&2)){a->b1d2^=1;a->w130=(unsigned char)a->b1d2;}func_0c02a0c4(a,15,4);}
