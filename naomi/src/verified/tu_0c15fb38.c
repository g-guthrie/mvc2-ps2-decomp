#include "objects.h"
#pragma section n15fb38
void func_0c15fb38(struct LinkedActor *p,struct LinkedActor *q)
{
 if(q->b7==1){p->b6=1;goto clear;}
 if(q->b7==2){p->b6=2;goto clear;}
 if(q->b7==7){*(volatile unsigned char *)&p->b6=3;
clear:p->b7=0;}
}
