/* Exact linked unit. Copy owner graphics and propagate animation state. */
#include "objects.h"
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
void func_0c1b2408(struct LinkedActor *q,struct LinkedActor *owner)
{
 if(!q->b4){
 q->b4++;q->sdc=owner->sdc;q->sdc.b12c=1;
 q->b2=owner->b2;q->b1=owner->b1;
 q->v80.x=owner->v80.x;q->v80.y=owner->v80.y;
 q->b1a3=owner->b1a3;q->b1a4=owner->b1a4;
 q->b48=owner->b48;q->v80=owner->v80;q->b36=owner->b36;
 q->sdc.b12c=1;q->b49=q->b33?-4:-18;
 q->f52=owner->f52;q->f56=owner->f56;
 q->s28=0;func_0c02a0c4(q,23,(unsigned char)q->b33*2);
 }
 q->b36=owner->b36;q->f52=owner->f52;q->f56=owner->f56;
 if(((char *)&((struct Actor *)owner)->w150)[1]==5||((char *)&((struct Actor *)owner)->w150)[1]==8){func_0c02a026(q);return;}
 else func_0c037688(q);
}
