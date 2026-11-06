/* Owner-keyed overlay piece: spawner, dispatch, init picking animation 48-50 by kind/side, and a follow step that drops out when the owner's 0x158 key or id changes. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,char);
extern char func_0c029fc4(struct LinkedActor *);
extern void (*table_0c25b00c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1b458a(struct LinkedActor *);
void func_0c1b464e(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1b4548(struct LinkedActor *owner,unsigned char kind,char side)
{
    struct LinkedActor *q;
    if((q=func_0c0374da(0,3,0))){
        q->p16=func_0c1b458a;
        q->p24=owner;
        q->b32=kind;
        q->b33=side;
        q->w38=0x2a01;
    }
    return q;
}
void func_0c1b458a(struct LinkedActor *a){table_0c25b00c[a->b4](a,a->p24);}
void func_0c1b459e(struct LinkedActor *a,struct LinkedActor *o)
{
    int n;
    a->b4++;
    a->sdc=o->sdc; a->sdc.b12c=1;
    a->b2=o->b2; a->b1=o->b1;
    a->v80.x=o->v80.x; a->v80.y=o->v80.y;
    a->b1a3=o->b1a3; a->b1a4=o->b1a4; a->b48=o->b48;
    a->v80=o->v80;
    a->b36=o->b36;
    a->b49=-1;
    a->wcc.dword_value=(unsigned short)o->sdc.w158.short_value;
    if(!a->b32){
        n=48; if(a->b33) n=49;
    }else{
        if(a->b33) a->sdc.w130^=1;
        n=50;
    }
    func_0c029e70(a,27,n);
    func_0c1b464e(a,o);
}
void func_0c1b464e(struct LinkedActor *a,struct LinkedActor *o)
{
    if(a->wcc.dword_value!=(unsigned short)o->sdc.w158.short_value||a->b1!=o->b1) goto fail;
    a->b36=o->b36;
    a->f52=o->f52;
    if(!a->b32){
        a->f56=A(o)->f41c;
        a->sdc.w130=o->sdc.w130;
    }else a->f56=o->f56;
    if(func_0c029fc4(a)>=0) return;
    if(a->b32) return;
fail:
    a->b4++;
    a->sdc.b12c=0;
}
int func_0c1b46e8(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1b46f6(struct LinkedActor *a){func_0c037688(a);}
