#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c257b64[])(struct LinkedActor *,void *);
void func_0c193768(struct LinkedActor *);
struct LinkedActor *func_0c193660(struct LinkedActor *parent,unsigned char b32,unsigned char b33)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,3,1))){
        short *slot;
        a->p16=func_0c193768;
        a->p24=parent;
        a->b32=b32; a->b33=b33;
        a->w38=0x0b00;
        a->sdc.b12c=0;
        slot=(short *)((char *)a+0x88);
        *slot=parent->sdc.w158.short_value;
    }
    return a;
}
struct LinkedActor *func_0c1936ba(struct LinkedActor *parent,unsigned char b32,unsigned char b33)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,4,1))){
        short *slot;
        a->p16=func_0c193768;
        a->p24=parent;
        a->b32=b32; a->b33=b33;
        a->w38=0x0b00;
        a->sdc.b12c=0;
        slot=(short *)((char *)a+0x88);
        *slot=parent->sdc.w158.short_value;
    }
    return a;
}
struct LinkedActor *func_0c193714(struct LinkedActor *parent,unsigned char b32,unsigned char b33)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,3,1))){
        a->p16=func_0c193768;
        a->p24=parent->p24;
        a->p20=parent;
        a->b32=b32; a->b33=b33;
        a->w38=0x0b00;
        a->sdc.b12c=0;
    }
    return a;
}
void func_0c193768(struct LinkedActor *a)
{
    struct LinkedActor *parent=a->p24;
    a->b36=parent->b36;
    table_0c257b64[a->b4](a,(char *)a+0x88);
}

/* Exact extension through 0c193bd0. */
extern short table_0c257bf4[][3];
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern int func_0c1ec190(void);
extern short table_0c257b74[][4];
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c19379c(struct LinkedActor *a)
{
    struct LinkedActor *owner=a->p24;
    float offset;
    int zero=0;
    a->b49=-2;a->s28=40;offset=800.0f;
    a->f92=-3.3333333f;a->f104=-0.20833333f;
    a->f96=-4.28571415f;a->f108=0.13392857f;
    if(!owner->sdc.w130){a->f92=-a->f92;a->f104=-a->f104;offset=-800.0f;}
    a->f52=owner->f52+offset;a->f56=owner->f56+480.0f;
    a->sdc.b12c=zero;a->b5=zero;func_0c02a0c4(a,19,8);
}
void func_0c193810(struct LinkedActor *a)
{
    struct LinkedActor *parent=a->p20;
    int zero=0;
    a->sdc.b12c=zero;a->b5=zero;a->s28=zero;
    a->sdc.w130=parent->sdc.w130;a->b49=-2;
    a->f52=parent->f52;a->f56=parent->f56;
    func_0c02a0c4(a,23,27);
}
void func_0c193840(struct LinkedActor *a)
{
    struct LinkedActor *owner=a->p24;
    int index;
    float scale_x,scale_y,duration;
    a->b49=-2;
    index=func_0c1ec190()&15;scale_x=1.66666663f;duration=256.0f;
    a->f92=table_0c257b74[(short)index][0]*scale_x/duration;a->f104=table_0c257b74[(short)index][1]*scale_x/duration;
    scale_y=2.1428571f;
    a->f96=table_0c257b74[(short)index][2]*scale_y/duration;a->f108=table_0c257b74[(short)index][3]*scale_y/duration;
    if(a->sdc.w130)a->f52=dat_0c2d9260.f88-26.666666031f;
    else{a->f52=dat_0c2d9260.f8c+26.666666031f;a->f92=-a->f92;a->f104=-a->f104;}
    a->f56=(((struct Actor *)owner)->f41c-(((int)func_0c1ec190()&127)<<8)*scale_y/duration)+171.42856f;
    func_0c02a0c4(a,23,29);
}
void func_0c193966(struct LinkedActor *a)
{
    int zero=0;
    a->sdc.b12c=zero;a->b5=zero;func_0c02a0c4(a,23,30);
}
void func_0c19397a(struct LinkedActor *a)
{
    struct LinkedActor *owner=a->p24;
    int zero=0;
    a->sdc.b12c=zero;a->b5=zero;
    a->f92=table_0c257bf4[(unsigned char)a->b33][0]*1.66666663f/256.0f;
    a->f96=table_0c257bf4[(unsigned char)a->b33][1]*2.1428571f/256.0f;
    a->sdc.w158.bytes[0]=table_0c257bf4[(unsigned char)a->b33][2];
    if(!owner->sdc.w130)a->f92=-a->f92;
    a->f52=owner->f52+a->f92;
    a->f56=owner->f56+a->f96;
    func_0c02a0c4(a,23,(signed char)a->sdc.w158.bytes[0]);
}

extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c193768(struct LinkedActor *);
void func_0c193a26(struct LinkedActor *a)
{
    struct LinkedActor *owner=a->p24,*child;
    int zero=0;
    a->b5=zero;a->sdc.b12c=zero;
    if(!a->b33){
        a->sdc.w130=zero;
        if(!owner->b2)a->sdc.w158.bytes[0]=35;
        else a->sdc.w158.bytes[0]=36;
        func_0c02a0c4(a,23,(signed char)a->sdc.w158.bytes[0]);
        if((child=func_0c0374da((int)a,3,2))!=0){
            child->p16=func_0c193768;child->p24=a->p24;child->p20=a;
            child->b32=5;child->b33=1;child->w38=0x0b00;
            child->sdc.b12c=zero;
        }
    }else{
        if(!owner->b2)a->sdc.w158.bytes[0]=37;
        else a->sdc.w158.bytes[0]=38;
        func_0c02a0c4(a,23,(signed char)a->sdc.w158.bytes[0]);
    }
}
void func_0c193af2(struct LinkedActor *a)
{
    a->b5=0;a->f92=58.3333321f;a->f96=285.0f;
    func_0c02a0c4(a,23,40);
}
/* Retail entry is exactly RTS followed by its NOP delay slot. */
void func_0c193b0e(void){}
void func_0c193b12(struct LinkedActor *a)
{
    struct LinkedActor *owner=a->p24;
    int zero=0;
    a->b5=zero;a->sdc.b12c=zero;
    a->f92=138.33333f;a->f96=150.0f;
    if(!owner->sdc.w130)a->f92=-a->f92;
    a->f52=owner->f52+a->f92;a->f56=owner->f56+a->f96;
    func_0c02a0c4(a,23,39);
}
void func_0c193b60(struct LinkedActor *a)
{
    struct LinkedActor *owner=a->p24;
    int zero=0;
    a->b5=zero;a->sdc.b12c=zero;
    if(!a->b33)a->sdc.w158.bytes[0]=41;
    else a->sdc.w158.bytes[0]=42;
    func_0c02a0c4(a,23,(signed char)a->sdc.w158.bytes[0]);
    a->f52=owner->f52;a->f56=owner->f56;
}
