/* Complete 492-byte callback; five bytes differ in layer-copy and old-velocity registers. Literal pools match; not verified C credit. */
#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c1d53e4(struct LinkedActor *),func_0c0346da(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
void func_0c1b1fb0(struct LinkedActor *a,struct LinkedActor *owner)
{
    float offset,zero,distance,old_velocity;
    if(!a->b4) {
        a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
        a->b2=owner->b2;a->b1=owner->b1;
        a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
        a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;
        a->v80=owner->v80;a->b36=owner->b36;a->b49-=8;
        zero=0.0f;a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;
        offset=640.0f;a->f92=-11.666666031f;
        if(a->sdc.w130) { offset=-640.0f;a->f92=-a->f92; }
        a->f52=owner->f52+offset;a->f56=owner->f56;
        func_0c02a0c4(a,19,10);
        ((struct Actor *)a)->b0=1;func_0c1d53e4(a);return;
    }
    a->b36=owner->b36;
    if(!a->b5) {
        a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);
        distance=owner->f52-a->f52;if(distance<0.0f)distance=-distance;
        if(distance<426.66666f) {
            a->b5++;((struct Actor *)owner)->sub2a4.s12=1;
            offset=53.3333321f;a->f104=0.41666666f;
            if(a->sdc.w130){offset=-53.3333321f;a->f104=-a->f104;}
            a->f52-=offset;func_0c02a0c4(a,19,11);func_0c0346da(owner,41);
        }
        return;
    }
    if((unsigned char)a->b5==1) {
        old_velocity=a->f92;a->f52+=old_velocity;a->f92+=a->f104;
        if(a->f92*old_velocity<0.0f)a->b5++;
    }
    func_0c02a026(a);
}
