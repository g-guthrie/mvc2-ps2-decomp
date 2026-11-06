#include "objects.h"
extern struct Dat_13bb5c dat_0c2f8338;
extern struct LinkedActor *func_0c0374da(struct LinkedActor *,int,int);
extern void func_0c197836(struct LinkedActor *);
void func_0c197a90(struct LinkedActor *a,struct LinkedActor *owner,struct ActorSub2a4 *state)
{
 struct LinkedActor *c,*p;float d,k;
 if(!(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))&&((char *)state)[4])goto fail;
 p=a->p20;a->f52=p->f52;
 a->f52+=a->f92;
 a->f92+=a->f104;d=a->f92;
 if(d<0)d=-d;
 k=160.0f;
 d-=k;
 if(d<0)return;
 a->b5++;
 if(!a->sdc.w130){d=-d;k=-160.0f;}
 a->f52=p->f52+k;a->f92=k;a->f104=0;
 if(a->s28<7){if(!(c=func_0c0374da(a,3,2)))goto fail;
 goto b;b:c->w38=0xe02;c->b32=1;c->b34=0;c->f92=d;c->s28=a->s28+1;c->p24=a->p24;c->p20=a;c->p16=func_0c197836;
 a->b34=1;}return;
fail:
 a->b5=2;a->f104=26.666666031f;
 if(a->sdc.w130)a->f104=-a->f104;
}
