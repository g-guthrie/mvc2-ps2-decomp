/* Candidate: homing spark group 0x0c158084-0x0c15846c. Spawner, dispatchers, init 0c1580c4,
 * 0c158250, 0c158284 and leaves match. 0c158338 differs in scheduling of the three
 * approach updates (retail recomputes each member address after the constant load);
 * 0c1583e0 swaps r4/r5 for the direction byte. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
#define B13D(x) (*((unsigned char *)(x)+0x13d))
struct SparkRow_0c2507b0 { unsigned char angle; unsigned char pad; short dx, dy; char anim; unsigned char prio; };
extern struct SparkRow_0c2507b0 dat_0c2507b0[];
extern void (*table_0c2507c8[])(struct LinkedActor *);
extern void (*table_0c2507d8[])(struct LinkedActor *);
extern void (*table_0c2507e0[])(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c0288a8(struct LinkedActor *,int);
extern int func_0c02850e(struct LinkedActor *);
extern unsigned char func_0c02887e(float *,float *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c1580b2(struct LinkedActor *);
void func_0c158250();
void func_0c1583e0(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c158084(struct LinkedActor *owner,unsigned char kind)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,1,0))) {
        a->p16=func_0c1580b2;
        a->p24=owner;
        a->b32=kind;
    }
    return a;
}
void func_0c1580b2(struct LinkedActor *a)
{
    table_0c2507c8[a->b4](a);
}
void func_0c1580c4(struct LinkedActor *a)
{
    struct LinkedActor *o;
    struct SparkRow_0c2507b0 *row;
    a->b4++;
    a->w38=0x1801;
    o=a->p24;
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
    a->sdc.b12c=1;
    a->sdc.w130=0;
    A(a)->b13c=16;
    B13D(a)=16;
    A(a)->b13e=16;
    A(a)->b13f=16;
    a->s28=1;
    a->s30=100;
    row=&dat_0c2507b0[a->b32];
    a->b34=row->angle;
    *(struct LinkedActorVec3 *)((char *)a+52)=*(struct LinkedActorVec3 *)((char *)o+52);
    if (o->sdc.w130==0) {
        a->f52+=(float)row->dx*1.66666663f;
    } else {
        a->f52+=-((float)row->dx*1.66666663f);
        a->b34=32-a->b34&31;
    }
    a->f56+=(float)row->dy*2.1428571f;
    a->f104=0.0f;
    a->f108=0.0f;
    A(a)->b19c=66;
    A(a)->b19d=66;
    A(a)->b1a1=row->prio;
    A(a)->w1ac=0;
    A(a)->b19e=0;
    A(a)->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a,23,row->anim);
    func_0c158250(a);
}
void func_0c158250(struct LinkedActor *a,struct LinkedActor *o)
{
    o=a->p24;
    if (o->b4>=2) {
        a->b4++;
        a->sdc.b12c=0;
        return;
    }
    table_0c2507d8[A(a)->b5](a);
}
void func_0c158284(struct LinkedActor *a,struct LinkedActor *b)
{
    if (A(a)->b19e || A(a)->b19f) {
        a->b5++;
        a->b6=0;
        return;
    }
    func_0c02a026(a);
    func_0c1583e0(a,b);
    func_0c0288a8(a,0x12c);
    if (func_0c02850e(a)==0) {
        a->b4++;
        a->sdc.b12c=0;
        return;
    }
    func_0c037d0c(a);
}
void func_0c1582f6(struct LinkedActor *a)
{
    table_0c2507e0[a->b6](a);
}
void func_0c158338(struct LinkedActor *a)
{
    a->b6++;
    a->s28=10;
    a->v80.x=a->v80.y=A(a)->f264=1.0f;
    a->v80.x+=(3.0f-a->v80.x)/(float)a->s28;
    a->v80.y+=(3.0f-a->v80.y)/(float)a->s28;
    A(a)->f264+=(0.0f-A(a)->f264)/(float)a->s28;
    if (--a->s28==0) {
        a->b4++;
        a->sdc.b12c=0;
    }
}
void func_0c1583cc(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c=0;
}
void func_0c1583da(struct LinkedActor *a)
{
    func_0c037688(a);
}
void func_0c1583e0(struct LinkedActor *a,struct LinkedActor *b)
{
    if (--a->s28==0) {
        struct Actor *t=A(b)->p20c;
        unsigned char dir=func_0c02887e(&a->f52,&t->f52)>>3;
        if (dir!=a->b34) {
            if ((dir-a->b34&31)<=15) a->b34++;
            else a->b34--;
            a->b34&=31;
        }
        a->s28=--a->s30==0?-1:5;
    }
}
