/* Exact 0x0c15632c..0x0c156664. Allocation-failure fallthrough intentionally preserves the allocator null result in r0 under bundled SHC; this target-specific source is not portable C. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c2506e0[])(struct LinkedActor *);
extern union LinkedActorWcc *dat_0c2fb35c;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c2d9300;
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c0344a0(struct LinkedActor *,int);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern int func_0c1ebbd0(float);
extern float func_0c1ebd40(int),func_0c1ec2c0(int);
void func_0c15637e(struct LinkedActor *);
void func_0c15650a(struct Actor *);
unsigned char func_0c156622(struct LinkedActor *);
void func_0c156646(struct LinkedActor *);

struct LinkedActor *func_0c15632c(struct LinkedActor *owner)
{
    struct LinkedActor *a;
    union LinkedActorWcc **global;
    if ((a=func_0c0374da(0,1,0)) != 0) {
        a->p16=func_0c15637e;
        global=&dat_0c2fb35c;
        a->p24=owner;
        a->w38=0x1702;
        a->sdc.w130=a->p24->sdc.w130;
        a->b7=a->p24->b1a3;
        *global=&a->wcc;
        (*global)->short_value=a->p24->sdc.w158.short_value;
        return a;
    }
}
void func_0c15637e(struct LinkedActor *a)
{
    struct LinkedActor *q=a;
    table_0c2506e0[q->b4](q);
}
void func_0c156390(struct LinkedActor *a)
{
    a->sdc=a->p24->sdc;
    a->sdc.b12c=1;
    a->b2=a->p24->b2;
    a->b1=a->p24->b1;
    a->v80.x=a->p24->v80.x;
    a->v80.y=a->p24->v80.y;
    a->b1a3=a->p24->b1a3;
    a->b1a4=a->p24->b1a4;
    a->b48=a->p24->b48;
    a->v80=a->p24->v80;
    a->b36=a->p24->b36;
    func_0c02a0c4(a,23,10);
    a->b36=0;
    *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&a->p24->f52;
    a->f52+=a->sdc.w130 ? 26.0f : -26.0f;
    a->f56+=90.0f;
    ((struct Actor *)a)->f92 = a->sdc.w130 ? func_0c1ebd40(func_0c1ebbd0(3.0f))*20.0f : -func_0c1ebd40(func_0c1ebbd0(3.0f))*20.0f;
    ((struct Actor *)a)->f96=func_0c1ec2c0(func_0c1ebbd0(3.0f))*20.0f;
    a->s28=100;
    a->s30=a->p24->b1a3 ? 7 : 4;
    a->b4=1;
    func_0c0344a0(a,33);
    func_0c15650a((struct Actor *)a);
}
void func_0c15650a(struct Actor *a)
{
    int zero;
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
    if (a->b1!=((struct LinkedActor *)a)->p24->b1) {a->b4=3;func_0c156646((struct LinkedActor *)a);return;}
    zero=0;
    if (--a->s28 < 0 || a->b19f || func_0c156622((struct LinkedActor *)a)) {
        a->b4=2;a->b12c=zero;return;
    }
    func_0c02a026((struct LinkedActor *)a);
    if (a->b141 && a->s30) {
        ((unsigned char *)a)[0x19c]=66;
        a->b19d=66;
        if (a->b7) a->b1a1=62; else {goto set; set: a->b1a1=60;}
        a->w1ac=zero;
        a->b19e=zero;
        *(void **)&a->p1c4=(void *)zero;
        dat_0c2f83f8->arr[a->b2]++;
        a->s30--;
    }
    func_0c037d0c((struct LinkedActor *)a);
}
unsigned char func_0c156622(struct LinkedActor *a)
{
    if (a->f56 >= dat_0c2d9300) return 1;
    return 0;
}
void func_0c156638(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c=0;
}
void func_0c156646(struct LinkedActor *a)
{
    func_0c037688(a);
}
