#include "objects.h"
#define A(a) ((struct Actor *)(a))

extern struct LinkedActor *func_0c0374da(int a, int b, int c);
extern void (*table_0c250214[])(struct LinkedActor *);
extern void (*table_0c250224[])(struct LinkedActor *);
void func_0c14b984(struct LinkedActor *a);
void func_0c14c9fa(struct LinkedActor *a);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short table_0c25007c[];
extern short table_0c250080[];

extern float table_0c250184[];
extern void (*table_0c25028c[])(struct LinkedActor *);
extern void (*table_0c2502f4[])(struct LinkedActor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c0346da(struct LinkedActor *, int);
extern void func_0c02a684(struct LinkedActor *, int, int, int);
extern void func_0c1d53e4(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern short table_0c2500a4[];
extern struct Motion4 table_0c2500ac[];
extern struct Motion4 table_0c250084[];

struct LinkedActor *func_0c14b8d8(struct LinkedActor *p, unsigned char b)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c14b984;
        q->p24 = p;
        q->b32 = b;
    }
    return q;
}

struct LinkedActor *func_0c14b906(struct LinkedActor *p, unsigned char b)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c14b984;
        q->p24 = p->p24;
        q->p20 = p;
        q->b32 = b;
    }
    return q;
}

struct LinkedActor *func_0c14b940(struct LinkedActor *p, unsigned char b, unsigned char c)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da((int)p, 1, 2)) != 0) {
        q->p16 = func_0c14b984;
        q->p24 = p->p24;
        q->p20 = p;
        q->b32 = b;
        q->b35 = c;
    }
    return q;
}

void func_0c14b984(struct LinkedActor *a)
{
    table_0c250214[a->b4](a);
}

void func_0c14b996(struct LinkedActor *a)
{
    a->b4++;
    a->sdc = a->p24->sdc;
    A(a)->b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    table_0c250224[a->b32](a);
    func_0c14c9fa(a);
}

void func_0c14ba38(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    struct ActorSub2a4 *s;
    short *t;

    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f52 += a->p24->sdc.w130 ? 96 : -96;
    a->f56 += 20.0f;
    a->b36 = 11;
    s = &A(o)->sub2a4;
    s->b0 = 1;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    t = table_0c25007c;
    t += a->p24->b1a3;
    a->s28 = *t;
    func_0c14b906(a, 24);
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 28);
}

void func_0c14bacc(struct LinkedActor *a)
{
    struct Actor *o = A(a->p24);
    struct Actor *t = o->p20c;

    A(a)->b12c = 1;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->f56 += 34.2857132f;
    a->sdc.w130 = a->p20->sdc.w130;
    a->b36 = 10;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 62;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    {
        short *s = table_0c250080;

        s += a->p24->b1a3;
        a->s28 = *s;
    }
    a->s30 = 90;
    {
        struct Motion4 *r = table_0c250084;

        r += a->p24->b1a3;
        a->f92 = r->f0;
        a->f104 = r->f4;
        a->f96 = r->f8;
        a->f108 = r->f12;
    }
    A(a)->f80 = 0.400000006f;
    A(a)->f84 = 0.400000006f;
    if (a->f52 > t->f52)
        a->sdc.w130 = 0;
    else
        a->sdc.w130 = 1;
    a->f92 = a->sdc.w130 ? a->f92 : -a->f92;
    a->f104 = a->sdc.w130 ? -a->f104 : a->f104;
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 1);
}

void func_0c14bc1e(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    struct ActorSub2a4 *s;
    struct Actor *u = A(o)->p20c;

    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->sdc.w130 = a->p24->sdc.w130;
    if (a->p24->b1a3 == 0)
        a->f52 += a->sdc.w130 ? 186.66666f : -186.66666f;
    else
        a->f52 += a->sdc.w130 ? 373.333313f : -373.333313f;
    if (a->sdc.w130) {
        if (a->f52 > dat_0c2d9260.f8c)
            a->f52 = dat_0c2d9260.f8c + -80.0f;
    } else {
        if (dat_0c2d9260.f88 > a->f52)
            a->f52 = dat_0c2d9260.f88 + 80.0f;
    }
    s = &A(o)->sub2a4;
    s->b20 = 1;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 63;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b36 = 0;
    A(a)->f84 = 0.0f;
    a->s30 = 4;
    func_0c0346da(a, 76);
    func_0c02a0c4(a, 23, 31);
}

void func_0c14bd58(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->sdc.w130 = a->p20->sdc.w130;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b36 = 0;
    A(a)->f84 = 0.0f;
    A(a)->f264 = 1.0f;
    a->s30 = 3;
    func_0c02a0c4(a, 23, 32);
}

void func_0c14bda4(struct LinkedActor *a)
{
    float *v;

    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f52 += a->p24->sdc.w130 ? 112 : -112;
    a->f56 += 176.0f;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 49;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    A(a)->w1ac |= 0x200;
    a->s28 = 80;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b36 = 0;
    v = table_0c250184;
    a->f92 = v[0];
    a->f104 = v[1];
    a->f96 = v[2];
    a->f108 = v[3];
    a->f92 = a->p24->sdc.w130 ? a->f92 : -a->f92;
    a->f104 = a->p24->sdc.w130 ? -a->f104 : a->f104;
    func_0c02a0c4(a, 23, 34);
}

void func_0c14beb4(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&a->p24->f52;
    a->f52 += a->p24->sdc.w130 ? 112 : -112;
    a->f56 += 208.0f;
    A(a)->b1a1 = 50;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->b2 ^= 1;
    A(a)->b19c = 102;
    A(a)->b19d = 6;
    a->b36 = 0;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->s28 = 60;
    A(a)->f264 = 0.7f;
    A(a)->f80 /= 1.66666663f;
    A(a)->f84 /= 2.1428571f;
    func_0c02a684(a, 2, 5, 1);
    func_0c02a0c4(a, 23, 43);
}

void func_0c14bf9e(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 61;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->b36 = 0;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a->p24)->b141 = 0;
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 35);
}

void func_0c14c016(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->b36 = 0;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 36);
}

void func_0c14c084(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f52 += a->p24->sdc.w130 ? -16 : 16;
    a->f56 += 176.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 33);
}

void func_0c14c0ee(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->b36 = 9;
    func_0c02a0c4(a, 23, (signed char)a->p24->b7 + 8);
}

void func_0c14c128(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->b36 = 11;
    A(a)->f264 = 0.5f;
    func_0c02a0c4(a, 23, (signed char)a->p24->b7 + 13);
}

void func_0c14c16a(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->b36 = 12;
    func_0c02a0c4(a, 23, (signed char)a->p24->b7 + 18);
}

void func_0c14c1a4(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f56 += 240.0f;
    a->b36 = 10;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 44);
}

void func_0c14c200(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f56 += 137.142853f;
    a->b36 = 10;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 44);
}

void func_0c14c244(struct LinkedActor *a)
{
    struct Actor *t = A(a->p24)->p20c;

    A(a)->b12c = 1;
    a->f52 = t->f52;
    a->f56 = dat_0c2d9260.f90 + 171.42856f;
    a->f60 = a->p24->f60;
    if (A(a)->w130) {
        if (a->f52 > dat_0c2d9260.f8c)
            a->f52 = dat_0c2d9260.f8c + -53.3333321f;
    } else {
        if (dat_0c2d9260.f88 > a->f52)
            a->f52 = dat_0c2d9260.f88 + 53.3333321f;
    }
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 48;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->b36 = 11;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = -1.2053571f;
    func_0c02a0c4(a, 23, 23);
}

void func_0c14c2f8(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f52 += a->p24->sdc.w130 ? 433.333344f : -433.333344f;
    a->f52 += a->p24->sdc.w130 ? 48 : -48;
    a->b36 = 9;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a684(a, 4, 4, 1);
    func_0c02a0c4(a, 23, 45);
    func_0c1d53e4(a);
    A(a)->b0 = 1;
}

void func_0c14c3c8(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->sdc.w130 = a->p24->sdc.w130;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f52 = a->sdc.w130 ? dat_0c2d9260.f88 + -400.0f : dat_0c2d9260.f8c + 400.0f;
    a->f56 += 240.0f;
    a->b36 = 14;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->f80 = 1.4f;
    A(a)->f84 = 1.4f;
    func_0c14b906(a, 17);
    func_0c14b940(a, 19, 1);
    func_0c14b940(a, 19, 0);
    func_0c02a0c4(a, 23, 2);
}

void func_0c14c488(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    A(a)->w130 = A(a->p20)->w130;
    a->f60 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->s30 = a->s28 = 0;
    A(a)->f92 = 0.0f;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 65;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->b36 = 15;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->f80 = 1.4f;
    A(a)->f84 = 1.4f;
    func_0c02a0c4(a, 23, 49);
}

void func_0c14c510(struct LinkedActor *a)
{
    struct Actor *t;
    struct LinkedActor *o = a->p24;

    t = A(o)->p20c;
    A(a)->b12c = 0;
    A(a)->w130 = A(a->p20)->w130;
    a->f52 = t->f52;
    a->f56 = a->p20->f56;
    a->f60 = t->f60;
    a->f56 += 34.2857132f;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    if (a->b35)
        A(a)->b1a1 = 67;
    else {
        goto set;
set:
        A(a)->b1a1 = 68;
    }
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->s28 = 28;
    goto s23;
s23:
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 4);
}

void func_0c14c5c4(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    A(a)->w130 = A(a->p20)->w130;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->b36 = 13;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->f80 = 1.4f;
    A(a)->f84 = 1.4f;
    a->f56 -= 95.9999924f;
    if (a->b35) {
        float c = 112.0f;

        a->f52 += A(a)->w130 ? c : -112.0f;
        func_0c02a0c4(a, 23, 3);
    } else {
        float d = -18.666666031f;

        a->f52 += A(a)->w130 ? d : 18.666666031f;
        func_0c02a0c4(a, 23, 60);
    }
}

void func_0c14c668(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    A(a)->w130 = A(a->p20)->w130;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    {
        float c = 74.666664124f;

        a->f52 += A(a)->w130 ? c : -74.666664124f;
    }
    a->f56 -= 11.99999905f;
    a->b36 = 12;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->f80 = 1.4f;
    A(a)->f84 = 1.4f;
    func_0c02a0c4(a, 23, 55);
}

void func_0c14c70c(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->b36 = 10;
    A(a)->f264 = 1.0f;
    func_0c02a0c4(a, 23, (signed char)a->p24->b7 + 50);
}

void func_0c14c74c(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    struct ActorSub2a4 *s;
    short *t;

    A(a)->b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f52 += a->p24->sdc.w130 ? 96 : -96;
    a->f56 += 20.0f;
    a->b36 = 11;
    s = &A(o)->sub2a4;
    s->b1 = 1;
    A(a)->f80 = 1.5f;
    A(a)->f84 = 1.5f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    t = table_0c25007c;
    t += a->p24->b1a3;
    a->s28 = *t;
    func_0c14b906(a, 25);
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 58);
}

void func_0c14c80c(struct LinkedActor *a)
{
    struct Actor *o = A(a->p24);
    struct Actor *u = o->p20c;

    A(a)->b12c = 1;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->f56 += 34.2857132f;
    A(a)->w130 = A(a->p20)->w130;
    a->b36 = 10;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 64;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b33 = 0;
    {
        short *t = table_0c2500a4;

        t += a->p24->b1a3;

        a->s28 = *t;
    }
    a->s30 = 90;
    {
        struct Motion4 *r = table_0c2500ac;

        r += a->b35;

        A(a)->f92 = r->f0;
        a->f104 = r->f4;
        A(a)->f96 = r->f8;
        a->f108 = r->f12;
    }
    A(a)->f80 = 0.400000006f;
    A(a)->f84 = 0.400000006f;
    A(a)->f92 = A(a)->w130 ? A(a)->f92 : -A(a)->f92;
    a->f104 = A(a)->w130 ? -a->f104 : a->f104;
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 57);
}

void func_0c14c91a(struct LinkedActor *a)
{
    short *t;

    A(a)->b12c = 1;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->b36 = 9;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    t = table_0c25007c;
    t += a->p24->b1a3;
    a->s28 = *t;
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 56);
}

void func_0c14c998(struct LinkedActor *a)
{
    short *t;

    A(a)->b12c = 1;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->b36 = 9;
    A(a)->f80 = 1.5f;
    A(a)->f84 = 1.5f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    t = table_0c25007c;
    t += a->p24->b1a3;
    a->s28 = *t;
    A(a)->b159 = 23;
    func_0c02a0c4(a, A(a)->b159, 59);
}

void func_0c14c9fa(struct LinkedActor *a)
{
    table_0c25028c[a->b32](a);
}

void func_0c14ca0e(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    struct ActorSub2a4 *s;

    table_0c2502f4[(unsigned char)a->b5](a);
    s = &A(o)->sub2a4;
    if (s->b1) {
        a->b4++;
        A(a)->b12c = 0;
        s->b0 = 0;
    }
}

void func_0c14ca4a(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;

    if (o->b5) {
        a->b5 = 2;
        a->s28 = 10;
        return;
    }
    func_0c02a026(a);
    if (A(a)->b141) {
        a->b5++;
        func_0c14b940(a, 1, 0);
    }
}

void func_0c14ca8e(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;

    if (o->b5) {
        a->b5 = 2;
        a->s28 = 10;
        return;
    }
    func_0c02a026(a);
    if (A(a)->b143 < 0) {
        a->b4++;
        A(a)->b12c = 0;
    }
}
