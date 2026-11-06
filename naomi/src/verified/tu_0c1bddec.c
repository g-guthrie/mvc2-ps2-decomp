/* Exact 0x0c1bddec..0x0c1bdec0: inherit owner graphics state, animate the effect, and propagate its feedback flag. */
#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c1bddec(struct LinkedActor *q,struct LinkedActor *owner)
{
 if(!q->b4){
 q->b4++;q->sdc=owner->sdc;q->sdc.b12c=1;q->b2=owner->b2;q->b1=owner->b1;
 q->v80.x=owner->v80.x;q->v80.y=owner->v80.y;
 q->b1a3=owner->b1a3;q->b1a4=owner->b1a4;
 q->b48=owner->b48;q->v80=owner->v80;q->b36=owner->b36;
 q->f52=owner->f52;q->f56=owner->f56;q->b49=-8;func_0c02a0c4(q,18,12);
 }
 q->b36=owner->b36;
 if(func_0c02a026(q)<0){func_0c037688(q);return;}
 else if(q->sdc.b141){q->sdc.b141=0;owner->b6=3;}
}
