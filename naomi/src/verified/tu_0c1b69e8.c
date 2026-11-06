/* Owner-pose effect family at 0x0c1b69e8: spawner, kind and state dispatch, three init/step pairs, and a follow step offset by a per-character short x/y table. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
#define COPYBLOCK(a,o) \
    a->sdc=o->sdc; a->sdc.b12c=1; \
    a->b2=o->b2; a->b1=o->b1; \
    a->v80.x=o->v80.x; a->v80.y=o->v80.y; \
    a->b1a3=o->b1a3; a->b1a4=o->b1a4; a->b48=o->b48; \
    a->v80=o->v80; \
    a->b36=o->b36
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c25b4bc[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c25b4dc[])(struct LinkedActor *);
extern void (*table_0c25b4e8[])(struct LinkedActor *);
extern void (*table_0c25b4f4[])(struct LinkedActor *);
extern void (*table_0c25b500[])(struct LinkedActor *);
extern const short dat_0c25b368[];
void func_0c1b6a2a(struct LinkedActor *);
void func_0c1b6d62(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1b69e8(struct LinkedActor *owner,int kind)
{
    struct LinkedActor *q;
    if((q=func_0c0374da(0,3,1))){
        q->w38=0x2d00;
        q->b32=kind;
        ((struct ActorPos52 *)q)->pos=((struct ActorPos52 *)owner)->pos;
        q->p16=func_0c1b6a2a;
        q->p24=owner;
    }
    return q;
}
void func_0c1b6a2a(struct LinkedActor *a){table_0c25b4bc[a->b32](a,a->p24);}
void func_0c1b6a40(struct LinkedActor *a){table_0c25b4dc[a->b4](a);}
void func_0c1b6a52(struct LinkedActor *a,struct LinkedActor *o)
{
    COPYBLOCK(a,o);
    a->b4++;
    a->b36=0;
    func_0c02a0c4(a,23,0);
}
void func_0c1b6ab8(register struct LinkedActor *a,struct LinkedActor *o)
{
    register void *zero;
    char *p;
    p=(char *)&A(o)->sub2a4.b0;
    zero=0;
    if(!a->b5){
        if(o->b1d0!=11) goto fail;
        goto L0;L0:
        func_0c02a026(a);
        if(a->sdc.b141){
            a->b5++;
            a->sdc.b141=(int)zero;
        }
        return;
    }
    goto L3;L3:
    a->b36=7;
    ((struct ActorPos52 *)a)->pos=((struct ActorPos52 *)o)->pos;
    if(func_0c02a026(a)<0){
fail:
        a->b4=2;
        a->sdc.b12c=(int)zero;
        return;
    }
    goto L2;L2:
    if(a->sdc.b141){
        a->b4=2;
        a->sdc.b12c=(int)zero;
        *p=1;
    }
}
void func_0c1b6b70(struct LinkedActor *a){table_0c25b4e8[a->b4](a);}
void func_0c1b6b82(struct LinkedActor *a,struct LinkedActor *o)
{
    COPYBLOCK(a,o);
    a->b4++;
    a->b36=7;
    ((struct ActorPos52 *)a)->pos=((struct ActorPos52 *)o)->pos;
    func_0c02a0c4(a,23,1);
}
void func_0c1b6bf6(struct LinkedActor *a)
{
    if(func_0c02a026(a)<0){a->b4=2;a->sdc.b12c=0;}
}
void func_0c1b6c16(struct LinkedActor *a){table_0c25b4f4[a->b4](a);}
void func_0c1b6c28(struct LinkedActor *a,struct LinkedActor *o)
{
    COPYBLOCK(a,o);
    a->b4++;
    a->b36=o->b36;
    a->b49=-2;
    a->sdc.b12c=0;
    a->sdc.w130=o->sdc.w130;
    func_0c1b6d62(a,o);
    func_0c02a0c4(a,23,2);
}
void func_0c1b6cd0(struct LinkedActor *a,struct LinkedActor *o)
{
    struct Actor *p;
    a->b36=o->b36;
    a->b49=-2;
    a->sdc.w130=o->sdc.w130;
    func_0c02a026(a);
    if(!a->b5){
        if(o->sdc.b141){a->b5++;a->sdc.b12c=1;}
        func_0c1b6d62(a,o);
        return;
    }
    func_0c1b6d62(a,o);
    if((unsigned char)o->b5==1&&(unsigned char)A(o)->b159==15&&(unsigned char)A(o)->b158==2) return;
    a->b4=2;
    a->sdc.b12c=0;
    p=A(o)->p1c8;
    p->w130^=1;
    p->b1d2^=1;
}
void func_0c1b6d62(struct LinkedActor *a,struct LinkedActor *o)
{
    struct Actor *p=A(o)->p1c8;
    const short *t=&dat_0c25b368[p->b1<<1];
    float x,y;
    x=*t++*1.66666663f;
    y=*t*2.1428571f;
    if(!A(o)->b1d2) x=-x;
    a->f52=p->f52+x;
    a->f56=p->f56+y;
}
void func_0c1b6dac(struct LinkedActor *a,struct LinkedActor *o)
{
    struct ActorSub2a4 *s=&A(o)->sub2a4;
    if((unsigned char)A(o)->b159!=21||(signed char)s->b7<0){a->b4=2;a->sdc.b12c=0;}
    table_0c25b500[a->b4](a);
}
