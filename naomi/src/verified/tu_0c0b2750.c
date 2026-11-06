#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c0437b8(struct Actor *),func_0c02a39a(struct Actor *,int);
extern struct LinkedActor *func_0c1a417c(struct Actor *,unsigned char),*func_0c1a5048(struct Actor *);
extern void (*table_0c244c00[])(struct Actor *);
void func_0c0b2750(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,21,11);}
 if(a->b141>0){a->b141=0;func_0c1a417c(a,0);if(a->b19e)func_0c1a417c(a,1);}
 if(a->b141<0){a->b141=0;position.x=-85.0f;position.y=160.71428f;position.z=0;func_0c043014(a,&position);}
}
void func_0c0b27c6(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0b27e8(struct Actor *a)
{
 if(!a->b6){a->b6++;func_0c02a0c4(a,20,4);}
 else if(func_0c02a026(a)<0){func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
 else if(a->b141){a->b141=0;func_0c1a5048(a);}
}
void func_0c0b2854(struct Actor *a){table_0c244c00[a->b6](a);}
