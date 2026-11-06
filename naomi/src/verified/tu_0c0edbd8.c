#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c0344a0(struct Actor *,int);
void func_0c0edbd8(struct Actor *a){struct ActorSubByteState *sub=(struct ActorSubByteState *)&a->sub2a4;a->b326=255;if(((char *)&a->w150)[1])sub->b4=1;if(a->b141)a->b141=0;if(func_0c02a026(a)<0){a->b6++;a->s30=10;a->b12c=0;a->b1f5=1;}}
void func_0c0edc2c(struct Actor *a){int one=1;a->b326=255;a->b12c=0;a->b1f5=one;if(--a->s30<0){a->b6++;a->b12c=one;a->f56=a->f41c+137.142853f;func_0c02a0c4(a,21,6);}}
void func_0c0edc6e(struct Actor *a){struct ActorSubByteState *sub=(struct ActorSubByteState *)&a->sub2a4;a->b326=255;if(((char *)&a->w150)[1])sub->b4=1;if(a->b141){a->b141=0;func_0c02a39a(a,0);}if(func_0c02a026(a)<0){a->b6++;a->s30=16;a->f96=2.1428571f;func_0c0344a0(a,15);func_0c02a0c4(a,19,4);}}
