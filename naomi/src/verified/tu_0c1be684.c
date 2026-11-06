/* Exact 0x0c1be684..0x0c1be714: advance motion, validate the parent animation, and terminate invalid effects. */
#include "objects.h"
extern char func_0c029fc4(struct Actor *);
extern int func_0c028642(struct Actor *);
extern void func_0c037688(struct Actor *);
void func_0c1be6ec(struct Actor *,struct Actor *);
void func_0c1be684(struct Actor *a,struct Actor *owner)
{
 func_0c029fc4(a);a->b149=26;
 if(!a->b141){a->f52+=a->f92;a->f92+=a->f104;}
 if(a->i204!=(unsigned char)owner->b159||!func_0c028642(a)){func_0c1be6ec(a,owner);return;}
}
void func_0c1be6ec(struct Actor *a,struct Actor *owner){int zero=0;a->b4=3;a->b0=zero;a->b12c=zero;}
void func_0c1be6fa(struct Actor *a){func_0c037688(a);}
