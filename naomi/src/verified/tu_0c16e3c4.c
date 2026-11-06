#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c1b526c(struct Actor *,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
void func_0c16e3c4(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(owner->b5 ||A(owner)->b1d0!=29){a->b4=2;goto deactivate;}
 a->b36=owner->b36;a->b49+=a->b32?4:-4;
 if(func_0c02a026(a)<0){a->b4++;deactivate:a->sdc.b12c=0;return;}
 goto feedback;feedback:if(!a->b33 &&A(a)->b19e){func_0c1b526c(A(owner),0);func_0c1b526c(A(owner),1);a->b33=1;}
 if(!a->b32 &&!a->b33)func_0c037d0c(a);
}
void func_0c16e464(struct LinkedActor *a){func_0c037688(a);}
