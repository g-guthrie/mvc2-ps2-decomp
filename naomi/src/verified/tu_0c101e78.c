#include "objects.h"
extern void func_0c02a39a(struct Actor *,int),func_0c025900(struct Actor *,int,int),func_0c1b644c(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c048ce6(struct Actor *);
void func_0c101e78(struct Actor *a,struct Actor *other)
{
 struct LinkedActorVec3 position;
 int command,zero;
 func_0c02a39a(a,0);a->b1a0=10;func_0c025900(a,5,5);
 if(*(unsigned short *)&a->sub2a4&0x400){a->w130^=1;a->b1d2^=1;}
 other->b1d2=other->w130=a->b1d2^1;
 if(!a->b1f7){zero=0;command=zero;func_0c1b644c(a);}else{zero=0;*(volatile short *)&a->s28=32;command=2;a->b6=zero;}
 func_0c02a0c4(a,15,command);
 position.x=-120.0f;position.y=270.0f;
 func_0c1d4610(a,&position);func_0c048ce6(a);
}
