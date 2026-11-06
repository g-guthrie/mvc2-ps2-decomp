/* Exact 0x0c1573a8..0x0c1578a0: the failed-allocation branch preserves the allocator's null result in r0 through the epilogue. The matching C intentionally falls through on that path under bundled SHC 5.0r31; this is compiler-dependent and not portable C. Adding a defined final return introduces a different branch or extra instructions. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c250720[])(struct LinkedActor *,struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c1a6308(struct Actor *,struct Actor *,int);
extern int func_0c0447bc(struct Actor *),func_0c028642(struct Actor *);
extern void func_0c037d0c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c1a6d1c(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern void func_0c157968(struct Actor *,int);
void func_0c1573e6(struct LinkedActor *a);
struct LinkedActor *func_0c1573a8(struct LinkedActor *owner)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,1,0))) {
        a->p16=func_0c1573e6;
        a->p24=owner;
        a->w38=0x1705;
        a->sdc.w130=a->p24->sdc.w130;
        a->b1=owner->b1;
        *(int *)&((struct Actor *)owner)->pad10c[4]=1;
        return a;
    }
}
void func_0c1573e6(struct LinkedActor *a)
{
    struct LinkedActor *q=a;
    table_0c250720[q->b4](q,q->p24);
}
void func_0c1573fa(struct LinkedActor *a,struct LinkedActor *owner)
{
    a->b4++;
    a->sdc=owner->sdc;
    a->sdc.b12c=1;
    a->b2=owner->b2;
    a->b1=owner->b1;
    a->v80.x=owner->v80.x;
    a->v80.y=owner->v80.y;
    a->b1a3=owner->b1a3;
    a->b1a4=owner->b1a4;
    a->b48=owner->b48;
    a->v80=owner->v80;
    a->b36=owner->b36;
    a->sdc.b12c=1;
    ((struct Actor *)a)->f264=0.7f;
    *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
    a->f52 += owner->sdc.w130 ? -60.0f : 60.0f;
    a->b36=0;
    ((unsigned char *)a)[0x19c]=66;
    ((struct Actor *)a)->b19d=66;
    ((struct Actor *)a)->b1a1=64;
    ((struct Actor *)a)->w1ac=0;
    ((struct Actor *)a)->b19e=0;
    ((struct Actor *)a)->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a,23,18);
    ((struct Actor *)a)->f92=0.0f;
    a->f96=0.0f;
    ((struct Actor *)a)->f104=0.0f;
    ((struct Actor *)a)->f108=0.0f;
    ((struct Actor *)a)->f92=-4.0f;
    ((struct Actor *)a)->f92=-13.33333302f;
    if(a->sdc.w130) ((struct Actor *)a)->f92=-((struct Actor *)a)->f92;
    ((struct Actor *)owner)->b1f1=2;
    *(int *)&((struct Actor *)owner)->pad10b[4]=3;
    a->s28=24;
}
void func_0c15754a(struct Actor *a,struct Actor *owner)
{
    int two=2;
    unsigned int zero;
    float stopped;
    switch ((unsigned char)owner->b5) {case 3: goto reset;}
    if (owner->b411) {
        a->b4=two;
        func_0c1a6308(a,owner,3);
        return;
    }
    zero=0;
    if (a->b19e == 0) goto moving;
    if (a->p1b0->b3) {
        a->b1a1=64;
        a->w1ac=zero;
        a->b19e=zero;
        *(void **)&a->p1c4=(void *)zero;
        dat_0c2f83f8->arr[a->b2]++;
        goto moving;
    }
    *(int *)&owner->pad10c[0]=zero;
    if ((a->b19e & 0x11) == 0) {} else goto reset;
    if (!func_0c0447bc(a)) goto reset;
    a->b5++;
    stopped=0.0f;
    a->f92=stopped;
    a->f96=stopped;
    a->f104=stopped;
    a->f108=stopped;
    *(int *)&owner->pad10c[8]=1;
    func_0c02a0c4((struct LinkedActor *)a,23,12);
    {struct Actor *target=a->p1b0;
    target->b1f9=zero;
    target->f56=owner->f41c;
    ((struct LinkedActorVec3 *)&a->i204)->x=106.666664124f;
    if(a->w130){float *v=&((struct LinkedActorVec3 *)&a->i204)->x;*v=-*v;} target->f52=a->f52-((struct LinkedActorVec3 *)&a->i204)->x;
    }
    *(struct Actor **)&a->pad5ba[0]=a->p1b0;
    if(a->b19e & 0x11) ((struct LinkedActorVec3 *)&a->i204)->x=stopped;
    a->b34=zero;
    return;
moving:
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
    if (!func_0c028642(a)) {
        *(int *)&owner->pad10c[0]=zero;
reset:
        func_0c1a6308(a,owner,3);
        a->b4=two;
        return;
    }
    if (--a->s28 < 0) {
        *(int *)&owner->pad10c[0]=zero;
        a->b5=two;
        a->f104=0.625f;
        if(a->w130) a->f104=-a->f104;
        func_0c02a0c4((struct LinkedActor *)a,2,2);
        return;
    }
    func_0c037d0c(a);
}
void func_0c157766(struct Actor *a,struct Actor *owner)
{
    int zero=0;
    if ((unsigned char)owner->b5==3) {
        func_0c1a6308(a,owner,3);
        a->b4=2;
        a->b12c=zero;
        return;
    }
    if (func_0c02a026(a)<0) {
        func_0c1a6308(a,owner,2);
        a->b4=2;
        return;
    }
    owner=*(struct Actor **)&a->pad5ba[0];
    if (a->b34 && a->b19e) {
        if (a->b19e & 0x11) {a->b1a0=8;owner->b1a0=8;}
        a->b34=zero;
    }
    if (a->b14b) {
        a->b1a1=a->b14b;
        a->w1ac=zero;
        a->b19e=zero;
        *(void **)&a->p1c4=(void *)zero;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b=zero;
        a->b34=1;
    }
    if (a->b141==2) {
        a->b141=zero;
        func_0c157968(a,4);
        func_0c1a6d1c(a,7);
        func_0c0344a0(a,36);
    }
    if (a->b141==15) {
        a->b141=zero;
        func_0c157968(a,5);
        func_0c1a6d1c(a,7);
        func_0c0344a0(a,36);
    }
    if (a->b141==3) {
        a->b141=zero;
        func_0c1a6d1c(a,6);
    }
    func_0c037d0c(a);
}
