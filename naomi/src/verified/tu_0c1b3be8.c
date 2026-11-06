/* Burst particles spawned by the owner's 0x229 counter: spawner, dispatch, init from the owner's 0x1b8 target, and a drifting follow that releases the counter slot on exit. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c0346da(struct LinkedActor *,int);
extern void func_0c1d330c(struct Actor *,float *,int,int);
extern int func_0c02849a(void);
extern float func_0c1ebd40(int),func_0c1ec2c0(int);
extern void (*table_0c25afc8[])(struct LinkedActor *);
#pragma inline(one)
static float one(void){return 1.0f;}
void func_0c1b3c2e(struct LinkedActor *);
void func_0c1b3cf8(struct LinkedActor *);
int func_0c1b3e28(struct LinkedActor *);
void func_0c1b3e36(struct LinkedActor *);
void func_0c1b3be8(struct Actor *o,unsigned char kind)
{
    struct LinkedActor *q;
    if(o->b229<7) if((q=func_0c0374da(0,3,0))){
        q->p16=func_0c1b3c2e;
        q->p24=(struct LinkedActor *)o;
        q->b32=kind;
        q->w38=0x2800;
        o->b229++;
    }
}
void func_0c1b3c2e(struct LinkedActor *a){table_0c25afc8[a->b4](a);}
void func_0c1b3c40(struct LinkedActor *a)
{
    struct LinkedActor *p;
    a->b4++;
    p=(struct LinkedActor *)A(a->p24)->p1b8;
    if(p->b1!=40){func_0c1b3e36(a);return;}
    a->sdc=p->sdc; a->sdc.b12c=1;
    a->b2=p->b2; a->b1=p->b1;
    a->v80.x=p->v80.x; a->v80.y=p->v80.y;
    a->b1a3=p->b1a3; a->b1a4=p->b1a4; a->b48=p->b48;
    a->v80=p->v80;
    a->b36=p->b36;
    a->p20=p;
    a->sdc.w130=p->sdc.w130;
    a->b49=-1;
    func_0c02a0c4(a,23,7);
    func_0c1b3cf8(a);
}
void func_0c1b3cf8(struct LinkedActor *a)
{
    struct Actor *o=(struct Actor *)a->p24;
    int r;
    a->b36=o->b36;
    func_0c02a026(a);
    if(o->b5!=3||o->b233!=15){
        a->b4++;
        a->b5=0;
        a->sdc.b12c=0;
        if(--o->b229<0) o->b229=0;
        if(o->b229<3){
            if(o->b229) func_0c1d330c(o,&a->f52,1,8); else func_0c1d330c(o,&a->f52,1,8);
            func_0c0346da(a,73);
        }
        return;
    }
    *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&o->f52;
    if(!a->b5){
        float two;
        a->b5++;
        two=one();two+=two;
        a->f96=o->b13c*2.1428571f/two;
        a->f108=a->f96/two;
        r=func_0c02849a()<<8;
        a->f92=a->f108*func_0c1ebd40(r)+a->f108*func_0c1ec2c0(r)/8.0f;
        a->f96+=-(a->f108*func_0c1ec2c0(r))+a->f108*func_0c1ebd40(r);
    }
    a->f52+=a->f92;
    a->f56+=a->f96;
}
int func_0c1b3e28(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1b3e36(struct LinkedActor *a){func_0c037688(a);}
