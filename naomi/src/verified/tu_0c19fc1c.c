#include "objects.h"
extern void func_0c029e70(struct LinkedActor *,int,int);
void func_0c19fc1c(struct LinkedActor *a)
{struct LinkedActor *parent;int one;
a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
 a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
 a->sdc.b12c=one;a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;func_0c029e70(a,27,one);}
void func_0c19fc98(struct LinkedActor *a)
{struct LinkedActor *parent;int one;
a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
 a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
 a->sdc.b12c=one;a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;a->f52=a->p24->f52;a->f52+=a->p24->sdc.w130?400.0f:-400.0f;
 a->f52+=a->p24->sdc.w130?-106.666664124f:106.666664124f;
 a->f56+=291.42856f;if(a->p24->sdc.w130)func_0c029e70(a,27,2);else func_0c029e70(a,27,3);}
void func_0c19fdb2(struct LinkedActor *a)
{struct LinkedActor *parent;int one;
a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
 a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
 a->sdc.b12c=one;a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;a->f52+=a->p24->sdc.w130?400.0f:-400.0f;
 a->f52+=a->p24->sdc.w130?-106.666664124f:106.666664124f;
 a->f56+=51.42857f;if(parent->sdc.w130)func_0c029e70(a,27,5);else func_0c029e70(a,27,6);}
