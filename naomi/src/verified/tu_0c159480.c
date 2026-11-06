/* Projectile/grab unit 0x0c159480-0x0c159ae0. The bare-file extent stops at the pool 0x0c159a8c;
 * the registered section also covers the tail of func_0c159a26 after that pool. */
#include "objects.h"
#define AP(a,o) (*(struct Actor **)((char *)(a)+(o)))
#define AI(a,o) (*(int *)((char *)(a)+(o)))
struct Pair_0c250914 { float x, y; };
extern struct Pair_0c250914 dat_0c250914[],dat_0c250918[];
extern float dat_0c25092c[];
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c037d0c(struct Actor *);
extern void func_0c037688(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c0445fe(struct Actor *,struct Actor *);
extern void func_0c0426c2(struct Actor *,int);
extern int func_0c042728(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c04392e(struct Actor *);
void func_0c159988();
void func_0c1599b4(struct Actor *);
void func_0c159a26(struct Actor *,struct Actor *);
#define A(x) ((struct Actor *)(x))
extern short dat_0c2508e8[];
extern void (*table_0c250900[])(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c159588();
void func_0c159480(struct LinkedActor *a)
{
    struct LinkedActor *o=a->p24;
    float v;
    a->b4++;
    a->w38=0x1900;
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
    a->sdc.w130=0;
    a->b36=10;
    a->b49=0;
    a->b33=0;
    a->b32=0;
    A(a)->f100=a->v80.x;
    A(a)->f112=a->v80.y;
    v=(float)dat_0c2508e8[a->b35]*1.66666663f;
    if (o->sdc.w130) v=-v;
    a->f52=dat_0c2d9260.f12+v;
    a->f56=A(o)->f41c;
    A(a)->b19c=68;
    A(a)->b19d=68;
    A(a)->b1a1=48;
    A(a)->w1ac=0;
    A(a)->b19e=0;
    A(a)->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    A(a)->w1ac|=0x200;
    func_0c02a0c4((struct Actor *)a,23,3);
    func_0c159588(a);
}
void func_0c159588(struct LinkedActor *a,struct LinkedActor *o)
{
    o=a->p24;
    if (o->b4>=2) {
        a->b4++;
        a->sdc.b12c=0;
        return;
    }
    table_0c250900[A(a)->b5](a);
}
void func_0c1595f0(struct Actor *a,struct Actor *b)
{
    if (func_0c02a026(a) < 0) {
        float v;
        a->b5++;
        a->s28=180;
        a->f52+=25.0f;
        a->f56+=246.42856f;
        v=dat_0c250914[a->b35].x;
        if (a->b35==0) { if (a->f52 < b->p20c->f52) goto neg; } else if (b->w130) { neg: v=-v; }
        a->f92=v;
        a->f96=dat_0c250918[a->b35].x;
        a->f104=0.0f;
        a->f108=-0.2678571343422f;
        func_0c02a0c4(a,23,4);
    }
    func_0c037d0c(a);
}
void func_0c15969a(struct Actor *a,struct Actor *b)
{
    if (b->b5 || a->b19f || AI(b,0x2e4)) goto out; {
        if (a->b19e) {
            if (func_0c0447bc(a)) {
                a->b5++;
                AI(b,0x2e4)++;
                func_0c159988(a,b);
                return;
            }
        } else {
            a->f52+=a->f92;
            a->f92+=a->f104;
            a->f56+=a->f96;
            a->f96+=a->f108;
            if (--a->s28==0) goto out;
            func_0c159a26(a,b);
            func_0c1599b4(a);
            func_0c037d0c(a);
            return;
        }
    }
out:
    a->b5=4;
    a->b6=0;
}
void func_0c159782(struct Actor *a,struct Actor *b)
{
    struct Actor *c=a->p1b0;
    if (c->b1a0==0) {
        a->b5++;
        a->f80=a->f100;
        a->f84=a->f112;
        func_0c02a0c4(c,14,0);
        func_0c0445fe(a,c);
        *(struct Actor **)&a->pad5ba[0]=b->p1c8;
        a->s28=180;
        func_0c0426c2(b->p1c8,1);
        c->b1f6=6;
        c->b1f7=b->b1f7=0xc0;
        b->b1ea=1;
        b->b15a=-1;
        if (c->b1f9==2) {
            c->f92=c->f104=c->f96=c->f108=0.0f;
        }
    }
}
void func_0c159838(struct Actor *a)
{
    struct Actor *c=*(struct Actor **)&a->pad5ba[0];
    if ((*(struct Actor **)&(*(struct Actor **)&a->pad7e[0])->pad7e[0])!=a || c->b5!=2) goto other;
    if (c->b19f && c->b5==3) goto other;
    {
        func_0c159988(a);
        if (func_0c042728(c)) a->s28-=3;
        if (--a->s28 < 0) {
            c->b1f6=0;
            c->b1ef=8;
            if (!c->w420) c->b1f6=7;
            else if (c->b1f9!=2) func_0c0437b8(c);
            else func_0c04392e(c);
            a->b4++;
            a->b12c=0;
        }
        return;
    }
other:
        a->b5++;
        a->b6=0;
}
void func_0c1598e0(struct Actor *a)
{
    if (a->b6==0) {
        a->b6++;
        a->b36=10;
        ((struct LinkedActor *)a)->b49=0;
        a->f80=1.20000005f*a->f100;
        a->f84=1.20000005f*a->f112;
        a->f264=0.5f;
        func_0c02a0c4(a,23,5);
    }
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->b12c=0;
    }
}
void func_0c159974(struct Actor *a)
{
    a->b4++;
    a->b12c=0;
}
void func_0c159982(struct Actor *a)
{
    func_0c037688(a);
}
void func_0c159988(struct Actor *a)
{
    struct Actor *c=a->p1b0;
    a->f52=c->f52;
    a->f56=c->f56+2.1428571f*(float)(c->b13c/2);
}
void func_0c1599b4(struct Actor *a)
{
    if (a->b32) {
        a->f80=dat_0c25092c[a->b32-1]*a->f100;
        if (++a->b32 > 30) {
            a->b32=0;
            a->f80=a->f100;
        }
    }
    if (a->b33) {
        a->f84=dat_0c25092c[a->b33-1]*a->f112;
        if (++a->b33 > 30) {
            a->b33=0;
            a->f84=a->f112;
        }
    }
}
void func_0c159a26(struct Actor *a,struct Actor *b)
{
    int n=0;
    if (a->f92 < 0.0f) {
        goto s1; s1: if (a->f52 < dat_0c2d9260.f88+80.0f) goto flipx;
    } else { goto s2; s2: if (a->f52 > dat_0c2d9260.f8c+-80.0f) {
flipx:
        a->f92=-a->f92;
        n++;
        a->b32=1;
    }}
    if (a->f96 >= 0.0f) {
        goto s3; s3: if (a->f56 > dat_0c2d9260.f90+-102.85714f) goto flipy;
    } else { goto s4; s4: if (b->f41c+102.85714f > a->f56) {
flipy:
        a->f96=-a->f96;
        n++;
        a->b33=1;
    }}
    if (n) ;
}
