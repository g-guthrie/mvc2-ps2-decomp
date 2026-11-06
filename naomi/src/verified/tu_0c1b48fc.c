/* Paired owner-tracking gauge pieces: spawner, dispatch, init and a follow step that picks a frame from a per-side byte table by the owner's 0x151 level. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c029fc4(struct LinkedActor *);
extern void (*table_0c25b064[])(struct LinkedActor *,struct LinkedActor *);
extern unsigned char dat_0c25b048[],dat_0c25b056[];
extern unsigned char dat_0c2f8338[];
void func_0c1b4952(struct LinkedActor *);
void func_0c1b49e8(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1b48fc(struct LinkedActor *owner)
{
    struct LinkedActor *q;
    if((q=func_0c0374da(0,4,0))){
        q->p16=func_0c1b4952;
        q->p24=owner;
        q->b32=0;
        q->w38=0x2a03;
    }
    if((q=func_0c0374da(0,4,0))){
        q->p16=func_0c1b4952;
        q->p24=owner;
        q->b32=1;
        q->w38=0x2a03;
    }
    return q;
}
void func_0c1b4952(struct LinkedActor *a){table_0c25b064[a->b4](a,a->p24);}
void func_0c1b4966(struct LinkedActor *a,struct LinkedActor *o)
{
    a->b4++;
    a->sdc=o->sdc; a->sdc.b12c=1;
    a->b2=o->b2; a->b1=o->b1;
    a->v80.x=o->v80.x; a->v80.y=o->v80.y;
    a->b1a3=o->b1a3; a->b1a4=o->b1a4; a->b48=o->b48;
    a->v80=o->v80;
    a->b36=o->b36;
    ((struct ActorPos52 *)a)->pos=((struct ActorPos52 *)o)->pos;
    a->s28=-1;
    {unsigned char *p;char n;
    p=dat_0c25b048;n=2;
    if(a->b32){p=dat_0c25b056;n=1;}
    a->wcc.pointer_value=(struct LinkedActor *)p;a->b49=n;}
    func_0c1b49e8(a,o);
}
void func_0c1b49e8(struct LinkedActor *a,struct LinkedActor *o)
{
    short v;unsigned char *p;
    volatile short t;
    if(a->b1!=o->b1){a->b4++;a->sdc.b12c=0;return;}
    a->sdc.b12c=0;
    if(!o->sdc.b12c) return;
    ((struct ActorPos52 *)a)->pos=((struct ActorPos52 *)o)->pos;
    a->sdc.w130=o->sdc.w130;
    a->b36=o->b36;
    if((v=((signed char *)&A(o)->w150)[1])>13) goto bad;
    if(a->s28!=v){
        a->s28=v;
        p=(unsigned char *)a->wcc.pointer_value;if(!(t=p[v])){bad:a->s28=-1;return;}
        func_0c029e70(a,27,t);
    }else if(!((signed char *)dat_0c2f8338)[68]&&!(dat_0c2f8338[6]&(1<<(a->b2^1)))) func_0c029fc4(a);
    a->sdc.b12c=1;
    if(a->b32) return;
    if(v!=13) return;
    {short d;d=10;if(a->sdc.w130) d=-10;a->f52+=d*1.66666663f;}
    a->f56+=12.85714245f;
}
int func_0c1b4b10(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1b4b1e(struct LinkedActor *a){func_0c037688(a);}
