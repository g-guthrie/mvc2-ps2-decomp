#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1898a8(struct Actor *,int),func_0c13150c(struct Actor *);
void func_0c1303b4(struct Actor *a)
{
 if(!a->b6){void (*motion)(struct Actor *,int);a->b6++;func_0c0442fa(a);func_0c0432ca(a);func_0c048bb0(a,5);
  a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->b1f9=0;a->s28=60;func_0c02a0c4(a,21,5);
  motion=func_0c1898a8;if(a->b1e9==1){motion(a,!a->b1a3?0:7);goto configured;}else{goto strength;strength:motion(a,!a->b1a3?4:3);}
configured:;
  a->b27b=0;a->b27a=16;
 }
 if(func_0c02a026(a)<0){if(!a->b141)func_0c13150c(a);}else if(--a->s28==0)func_0c02a0c4(a,21,6);
}
