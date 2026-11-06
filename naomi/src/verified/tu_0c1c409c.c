/* Sliding display lifecycle, including all nine callback entries (exact under SHC 5.1R08). */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
void func_0c1c40e8(struct LinkedActor *);
void func_0c1c4254(struct LinkedActor *);
extern void (*table_0c25d734[])(struct LinkedActor *);
void func_0c1c409c(int flags)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,12,1))) {
        a->sdc.b12c=0;
        a->p16=func_0c1c40e8;
        a->p84=0;
        a->wcc.dword_value=0;
        a->w38=7;
        a->b32=flags&15;
        if(flags&128) func_0c1c4254(a);
    }
}
void func_0c1c40e8(struct LinkedActor *a)
{
    table_0c25d734[a->b4](a);
}

extern int func_0c026a86(struct LinkedActor *);
extern float dat_0c25d6e4[];
extern void *dat_0c25d6a4[];
extern unsigned char dat_0c25d724[];
extern void func_0c034a1c(char);
void func_0c1c4178(struct LinkedActor *);
void func_0c1c40fa(struct LinkedActor *a)
{
    char sound;
    if(func_0c026a86(a)) return;
    a->b4++; a->sdc.b12c=1; a->s28=60;
    a->f52=-dat_0c25d6e4[a->b32]/2.0f;
    a->f56=-6.25f; a->f60=0.0f;
    *(void **)((unsigned char *)a+0xd4)=dat_0c25d6a4[a->b32];
    *(int *)((unsigned char *)a+0xd8)=0;
    if((unsigned char)(sound=dat_0c25d724[a->b32])) func_0c034a1c((char)sound);
    func_0c1c4178(a);
}
extern void (*table_0c25d744[])(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c1c4294(int);
extern struct ActorFlags *dat_0c2d6f84;
void func_0c1c4178(struct LinkedActor *a)
{ table_0c25d744[(unsigned char)a->b5](a); }
void func_0c1c41aa(struct LinkedActor *);
void func_0c1c418a(struct LinkedActor *a)
{
    a->b5++; a->s28=12;
    ((struct Actor *)a)->f100=(-a->f60+-40.0f)/12.0f;
    func_0c1c41aa(a);
}
void func_0c1c41aa(struct LinkedActor *a)
{
    a->f60+=((struct Actor *)a)->f100;
    if(--a->s28<=0) { a->b5++; a->s28=60; }
}
void func_0c1c4208(struct LinkedActor *a)
{
    if(--a->s28<=0) {
        a->b5++; a->s28=12;
        ((struct Actor *)a)->f100=(-a->f60+0.0f)/12.0f;
    }
}
void func_0c1c4236(struct LinkedActor *a)
{
    a->f60+=((struct Actor *)a)->f100;
    if(--a->s28<=0) func_0c1c4254(a);
}
void func_0c1c4254(struct LinkedActor *a)
{
    a->sdc.b12c=0;
    if(a->b32==3) func_0c1c4294((signed char)dat_0c2d6f84->pad137[2]);
    func_0c037688(a);
}
