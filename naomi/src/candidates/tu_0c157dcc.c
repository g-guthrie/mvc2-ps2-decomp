/* Candidate: spark spawner group 0x0c157dcc-0x0c158084. 0c157de0, 0c157f8a, 0c158020 and later leaves
 * match; the init 0c157e34 spells the random index modulo explicitly, which costs four
 * bytes against retail (retail keeps the call result in r0 and uses and #3 / not-add
 * negation), shifting the first pool; the dispatcher keeps the target in r3 not r0 and
 * 0c157f9e loads owner f41c through fr2 not fr3. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern void (*table_0c250794[])(struct LinkedActor *,unsigned char);
extern void (*table_0c250798[])(struct LinkedActor *);
extern void (*table_0c2507a8[])(struct LinkedActor *,struct LinkedActor *);
extern float dat_0c22f6a8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern int func_0c02849a(void);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c157e22(struct LinkedActor *);
void func_0c157f8a(struct LinkedActor *);
void func_0c157dcc(struct LinkedActor *a,unsigned char kind)
{
    ((void (**)(struct LinkedActor *,unsigned char))table_0c250794)[kind](a,kind);
}
struct LinkedActor *func_0c157de0(struct LinkedActor *owner,unsigned char p,unsigned char q)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,1,0))) {
        a->p16=func_0c157e22;
        a->p24=owner;
        a->b32=p;
        a->b33=q;
        a->b35=0;
    }
    return a;
}
void func_0c157e22(struct LinkedActor *a)
{
    table_0c250798[a->b4](a);
}
void func_0c157e34(struct LinkedActor *a)
{
    struct LinkedActor *o=a->p24;
    float *speeds=dat_0c22f6a8;
    int r;
    a->b4++;
    a->sdc=o->sdc;
    a->sdc.b12c=1;
    a->b2=o->b2;
    a->b1=o->b1;
    a->v80.x=o->v80.x;
    a->v80.y=o->v80.y;
    a->b1a3=o->b1a3;
    a->b1a4=o->b1a4;
    a->b48=o->b48;
    a->v80=o->v80;
    a->b36=o->b36;
    a->b36=9;
    r=func_0c02849a()-128;
    {float t=(float)((r*640)>>8);a->f52=A(o)->p20c->f52+t;}
    a->f56=A(o)->p20c->f56+300.0f;
    a->f60=A(o)->p20c->f60;
    A(a)->i72=0xb000;
    {int i;r=func_0c02849a();
    i=r;
    if (r>=0) i&=3; else i=-(-i&3);
    a->v80.x=speeds[i];
    a->v80.y=speeds[i];}
    A(a)->b19c=66;
    A(a)->b19d=66;
    A(a)->b1a1=49;
    A(a)->w1ac=0;
    A(a)->b19e=0;
    A(a)->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a,23,1);
    func_0c157f8a(a);
}
void func_0c157f8a(struct LinkedActor *a)
{
    table_0c2507a8[A(a)->b5](a,a->p24);
}
void func_0c157f9e(struct LinkedActor *a,struct LinkedActor *b)
{
    if (func_0c02a026(a) < 0) {
        a->b5++;
        if (a->sdc.w130) ;
        a->f52-=106.666664124f;
        a->f56=A(b)->f41c;
        A(a)->i72=0;
        func_0c02a0c4(a,23,2);
        a->v80.x*=0.25f;
        a->v80.y*=0.375f;
        return;
    }
    func_0c037d0c(a);
}
void func_0c158020(struct LinkedActor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->sdc.b12c=0;
    }
}
void func_0c158042(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c=0;
}
void func_0c158050(struct LinkedActor *a)
{
    func_0c037688(a);
}
