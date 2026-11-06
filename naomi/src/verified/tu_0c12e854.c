#include "objects.h"
extern int func_0c1be894(struct Actor *,int);
void func_0c12e854(struct Actor *a)
{
 if(*(int *)&a->sub2a4>0)*(int *)&a->sub2a4=*(int *)&a->sub2a4-1;
 if(!a->b1a0 && a->i204>0){if((a->i204=a->i204-1)<=0)a->b202=0;}
 if((short)a->w420<32 && !*(int *)&a->pad5ba[0]){if(func_0c1be894(a,4))*(int *)&a->pad5ba[0]=1;}
 if(a->l2c8>0)a->l2c8=a->l2c8-1;
 if(a->p20c->b1==16){if(a->p20c->b37==a->b37 && !a->b5 && a->b1d0==14 && a->b1d1==31 && a->b1a2==63)a->l2c8=120;}
}
