/* Exact 0x0c0ae834..0x0c0ae924: reset attack feedback, emit effects, and select movement timing. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1a3444(struct Actor *,int);
void func_0c0ae834(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
 struct ActorSub2a4 *state=&a->sub2a4;int zero=0;
 a->b6++;
 if(a->b1f9==2)a->b1f5=3;
 a->b141=zero;state->b2=zero;state->b3=zero;a->b142=1;
 func_0c02a026(a);
 func_0c1a3444(a,1);func_0c1a3444(a,3);func_0c1a3444(a,4);func_0c1a3444(a,5);func_0c1a3444(a,6);func_0c1a3444(a,7);
 if(!a->b1f9)func_0c1a3444(a,8);
 goto strength;strength:if(!a->b1a3){a->s28=38;a->f92=-25.0f;a->f104=1.25f;}
 else {a->s28=50;a->f92=-33.3333321f;a->f104=1.4583333f;}
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 }
}
