/* Candidate: only func_0c157bb8 differs, by three temporary-register bytes: the
 * default arm of the b1a1 switch (b35 + 70) takes r1 where retail takes r3.
 * The constructor falls off the end after its allocation-failure test so the
 * allocator null result stays in r0 (as in tu_0c15632c); that makes it exact.
 * All other functions and all four pools are exact. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25073c[])(struct LinkedActor *,struct LinkedActor *);
extern float dat_0c25074c[],dat_0c250764[];
extern char dat_0c25077c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float func_0c1ebd40(int),func_0c1ec2c0(int);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c1579b6(struct LinkedActor *);
void func_0c157b30(struct LinkedActor *,struct LinkedActor *);
void func_0c1579ca(struct LinkedActor *,struct LinkedActor *);
void func_0c157ae4(struct LinkedActor *,struct LinkedActor *);
void func_0c157b2a(struct LinkedActor *);
void func_0c157b6e(struct LinkedActor *);
void func_0c157d42(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c157968(struct LinkedActor *owner,unsigned char mode)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,3,0))) {
        a->p16=func_0c1579b6;
        a->p24=owner;
        a->w38=0x1705;
        a->sdc.w130=a->p24->sdc.w130;
        a->b35=mode;
        func_0c157b30(a,owner);
        return a;
    }
}
void func_0c1579b6(struct LinkedActor *a)
{
    struct LinkedActor *q=a;
    table_0c25073c[q->b4](q,q->p24);
}
void func_0c1579ca(struct LinkedActor *a,struct LinkedActor *owner)
{
    float x;
    if (a->b35 >= 6) {func_0c037688(a);return;}
    x=dat_0c25074c[a->b35];
    if (a->sdc.w130 == 0) x=-x;
    a->f52=owner->f52+x;
    a->f56=owner->f56+dat_0c250764[a->b35];
    if(a->b35==1) ((struct Actor *)a)->i72=0xe4fb;
}
void func_0c157a40(struct LinkedActor *a,struct LinkedActor *owner)
{
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
    a->b4++;
    a->sdc.b12c=1;
    func_0c1579ca(a,owner);
    func_0c02a0c4(a,23,dat_0c25077c[a->b35]);
    a->b36=owner->b36;
    a->b49=-1;
    if (a->b35 >= 4) ((struct Actor *)a)->f264=0.40000001f;
    func_0c157ae4(a,owner);
}
void func_0c157ae4(struct LinkedActor *a,struct LinkedActor *owner)
{
    if(a->b1 != owner->b1){func_0c157b2a(a);return;}
    func_0c1579ca(a,owner);
    if(func_0c02a026(a)<0){a->b4=2;a->sdc.b12c=0;}
}
void func_0c157b1c(struct LinkedActor *a) {a->b4++;a->sdc.b12c=0;}
void func_0c157b2a(struct LinkedActor *a) {func_0c037688(a);}
void func_0c157b30(struct LinkedActor *source,struct LinkedActor *owner)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,1,1)) != 0) {
        a->p16=func_0c157b6e;
        a->p24=owner;
        a->w38=0x1705;
        a->sdc.w130=a->p24->sdc.w130;
        a->b35=source->b35;
    }
}
extern void (*table_0c250784[])(struct LinkedActor *,struct LinkedActor *);
void func_0c157b6e(struct LinkedActor *a)
{
    struct LinkedActor *q=a;
    table_0c250784[q->b4](q,q->p24);
}
void func_0c157bb8(struct LinkedActor *a,struct LinkedActor *owner)
{
    unsigned int zero;
    zero=(a->b4++,0);
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
    a->sdc.b12c=zero;
    func_0c1579ca(a,owner);
    func_0c02a0c4(a,23,20);
    a->b36=owner->b36;
    a->b49=-1;
    ((unsigned char *)a)[0x19c]=66;
    ((struct Actor *)a)->b19d=66;
    switch (a->b35) {
    case 3: ((struct Actor *)a)->b1a1=63;break;
    case 4: ((struct Actor *)a)->b1a1=66;break;
    case 5: ((struct Actor *)a)->b1a1=67;break;
    default: ((struct Actor *)a)->b1a1=a->b35+70;break;
    }
    ((struct Actor *)a)->w1ac=zero;
    ((struct Actor *)a)->b19e=zero;
    ((struct Actor *)a)->p1c4=zero;
    dat_0c2f83f8->arr[a->b2]++;
    ((struct Actor *)a)->b19f=zero;
    a->b5=zero;
    if (a->b35 !=1) goto other_mode;
    ((struct Actor *)a)->f92=a->sdc.w130 ? func_0c1ebd40(0x1b06)*23.333334f : -func_0c1ebd40(0x1b06)*23.333334f;
    a->f96=func_0c1ec2c0(0x1b06)*23.333334f;
    goto mode_end;
other_mode:
    ((struct Actor *)a)->f92=a->sdc.w130 ? 23.333334f : -23.333334f;
mode_end:
    a->s28=30;
    func_0c157d42(a,owner);
}
void func_0c157d42(struct LinkedActor *a,struct LinkedActor *owner)
{
    if (((struct Actor *)a)->b19f) a->b5++;
    if (a->s28) a->s28--;
    else a->b4=2;
    if (!a->b5) func_0c037d0c(a);
    ((struct Actor *)a)->f52+=((struct Actor *)a)->f92;
    ((struct Actor *)a)->f92+=((struct Actor *)a)->f104;
    ((struct Actor *)a)->f56+=((struct Actor *)a)->f96;
    ((struct Actor *)a)->f96+=((struct Actor *)a)->f108;
}
