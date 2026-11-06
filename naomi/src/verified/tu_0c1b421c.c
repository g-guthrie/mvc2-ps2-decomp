/* Two owner-pose followers: one tracks the owner while it holds pose 21, the other hovers at a fixed offset beside it. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c1b421c(struct LinkedActor *a,struct LinkedActor *o)
{
    if(!a->b4){
        a->b4++;
        a->b6=a->sdc.b141=0;
        a->sdc=o->sdc; a->sdc.b12c=1;
        a->b2=o->b2; a->b1=o->b1;
        a->v80.x=o->v80.x; a->v80.y=o->v80.y;
        a->b1a3=o->b1a3; a->b1a4=o->b1a4; a->b48=o->b48;
        a->v80=o->v80;
        a->b36=o->b36;
        a->b49=-1;
        a->sdc.b12c=1;
        func_0c02a0c4(a,23,4);
    }
    a->b36=o->b36;
    if((unsigned char)A(o)->b159!=21) goto kill;
    a->f52=o->f52; a->f56=o->f56;
    if(func_0c02a026(a)>=0) return;
kill:
    func_0c037688(a);
}
void func_0c1b42da(struct LinkedActor *a,struct LinkedActor *o)
{
    if(!a->b4){
        a->b4++;
        a->sdc=o->sdc; a->sdc.b12c=1;
        a->b2=o->b2; a->b1=o->b1;
        a->v80.x=o->v80.x; a->v80.y=o->v80.y;
        a->b1a3=o->b1a3; a->b1a4=o->b1a4; a->b48=o->b48;
        a->v80=o->v80;
        a->b36=o->b36;
        a->b49=-1;
        a->sdc.b12c=1;
        func_0c02a0c4(a,23,8);
    }
    if(!a->sdc.w130) a->f52=o->f52-23.3333321f; else a->f52=o->f52+23.3333321f;
    a->f56=o->f56+282.85715f;
    a->b36=o->b36;
    if(func_0c02a026(a)<0) func_0c037688(a);
}
