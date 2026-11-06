#include "objects.h"
extern void func_0c045248(struct Actor *,int);
void func_0c07a7ec(struct Actor *a)
{
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 1:a->b1e9=zero;break;case 0:case 2:{struct ActorSubTimers *t=(struct ActorSubTimers *)&a->sub2a4;a->b1e9=1;t->s34=1;}break;}
 a->b1a3=1;
 func_0c045248(a,21);
}
