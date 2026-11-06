#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c0288a8(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c143dda(struct LinkedActor *);
void func_0c143da0(struct LinkedActor *a)
{
 func_0c0288a8(a,700);func_0c02a026(a);func_0c037d0c(a);
 if(A(a)->b19e||A(a)->b19f)a->b4++;
}
void func_0c143dd4(struct LinkedActor *a){a->sdc.b12c=0;func_0c143dda(a);}
void func_0c143dda(struct LinkedActor *a){a->b4++;}
void func_0c143de2(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
