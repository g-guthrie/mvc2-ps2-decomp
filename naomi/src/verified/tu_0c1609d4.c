/* Linked actor spawner/state unit; matches retail exactly. Tail19c views the
 * LinkedActor bytes from 0x19c (pad11 onward) that objects.h leaves as padding. */
#include "objects.h"
#define LA struct LinkedActor
#define P8(a) (*(LA **)((char *)(a) + 8))
#define B(a, o) (((unsigned char *)(a))[o])
struct Tail19c {
    char b19c, b19d, b19e, b19f, pad1a0, b1a1, pad1a2[0x1ac - 0x1a2];
    short w1ac;
    char pad1ae[0x1c4 - 0x1ae];
    int l1c4;
};
#define T(a) ((struct Tail19c *)(a)->pad11)
extern LA *func_0c0374da(LA *, int, int);
extern void (*table_0c2514cc[])(LA *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c028642(LA *);
extern char func_0c02a026(LA *);
extern void func_0c037d0c(LA *), func_0c037688(LA *);
extern void func_0c02a0c4(LA *, int, int);
extern void func_0c02a18c(LA *, int, int, int);
void func_0c160a00(LA *);
void func_0c160af4(LA *);
void func_0c160b38(LA *, LA *);
void func_0c160b98(LA *, LA *);
void func_0c160be4(LA *, LA *);
void func_0c160c58(LA *, LA *);
void func_0c160d2e(LA *, LA *);
void func_0c160d58(LA *, LA *);
void func_0c160da8(LA *, LA *, LA *);

LA *func_0c1609d4(LA *a)
{
    LA *q;
    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c160a00;
        q->p24 = a;
        q->b32 = 0;
    }
    return q;
}

void func_0c160a00(LA *a)
{
    table_0c2514cc[a->b4](a);
}

void func_0c160a12(LA *a)
{
    LA *o = a->p24;
    a->b4++;
    a->w38 = 0x1d05;
    a->sdc = o->sdc;
    a->sdc.b12c = 1;
    a->b2 = o->b2;
    a->b1 = o->b1;
    a->v80.x = o->v80.x;
    a->v80.y = o->v80.y;
    a->b1a3 = o->b1a3;
    a->b1a4 = o->b1a4;
    a->b48 = o->b48;
    a->v80 = o->v80;
    a->b36 = o->b36;
    a->sdc.b12c = 1;
    a->b36 = 10;
    B(a, 0x13c) = 32;
    B(a, 0x13d) = 32;
    B(a, 0x13e) = 32;
    B(a, 0x13f) = 32;
    if (a->sdc.w130 == 0) a->b34 = 12;
    else a->b34 = 4;
    T(a)->b19c = 66;
    T(a)->b19d = 66;
    if (!a->b32) {
        a->wcc.arrcc[1] = 0;
        a->wcc.arrcc[0] = 0;
        a->wcc.arrcc[2] = 2;
        func_0c02a0c4(a, 22, 29);
    } else if (a->wcc.arrcc[0]) func_0c02a0c4(a, 22, 42);
    else func_0c02a0c4(a, 22, 41);
    func_0c160af4(a);
}

void func_0c160af4(LA *a)
{
    LA *o = a->p24;
    if (!a->b32) func_0c160b38(a, o);
    else func_0c160c58(a, o);
}

void func_0c160b38(LA *a, LA *o)
{
    if ((unsigned short)o->sdc.w158.short_value != 0x1603 && (unsigned short)o->sdc.w158.short_value != 0x1601
        && (unsigned short)o->sdc.w158.short_value != 0x1602 && (unsigned short)o->sdc.w158.short_value != 0x161b) {
        a->b4++;
        a->sdc.b12c = 0;
        return;
    }
    if (!a->b5) func_0c160b98(a, o);
    else func_0c160be4(a, o);
    func_0c160d58(a, o);
}

void func_0c160b98(LA *a, LA *o)
{
    LA *q;
    func_0c02a026(a);
    if (!a->sdc.b141) {
        a->b5++;
        if ((q = func_0c0374da(a, 1, 2)) != 0) {
            q->p16 = func_0c160a00;
            q->p24 = a->p24;
            q->b32 = 1;
            q->wcc.arrcc[1] = 0xff;
            q->wcc.arrcc[0] = 0xff;
            q->p20 = a;
        }
    }
}

void func_0c160be4(LA *a, LA *o)
{
    LA *q;
    func_0c02a026(a);
    if ((q = func_0c0374da(a, 1, 2)) != 0) {
        q->p16 = func_0c160a00;
        q->p24 = a->p24;
        q->b32 = 1;
        q->wcc.arrcc[0] = 0;
        q->p20 = a;
        q->wcc.arrcc[1] = 0;
        if (--a->wcc.arrcc[2] == 0) {
            a->wcc.arrcc[2] = 5;
            q->wcc.arrcc[1] = 0xff;
        }
    }
}

void func_0c160c58(LA *a, LA *o)
{
    LA *x = a->p20;
    LA *p = P8(a);
    if (x->b4 >= 2 || p->b4 >= 2) goto fail;
    func_0c160da8(a, o, p);
    func_0c160d2e(a, x);
    a->b32++;
    if (!func_0c028642(a)) {
fail:
        a->b4 = 3;
        a->sdc.b12c = 0;
        return;
    }
    if (T(a)->b19f) {
        T(a)->b19f = 0;
        a->wcc.arrcc[1] = 0;
        return;
    } else if (T(a)->b19e) {
        T(a)->b19e = 0;
        a->wcc.arrcc[1] = 0;
        return;
    }
    T(a)->b19c = 66;
    if (!a->wcc.arrcc[0] && !a->wcc.arrcc[1]) T(a)->b19c = 0;
    T(a)->b1a1 = T(o)->b1a1;
    T(a)->w1ac = 0;
    T(a)->b19e = 0;
    T(a)->l1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c037d0c(a);
}

void func_0c160d1a(LA *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c160d28(LA *a)
{
    func_0c037688(a);
}

void func_0c160d2e(LA *a, LA *x)
{
    if (a->wcc.arrcc[0]) func_0c02a18c(a, 22, 42, x->sdc.b141 & 1);
    else func_0c02a18c(a, 22, 41, x->sdc.b141);
}

void func_0c160d58(LA *a, LA *o)
{
    a->f52 = o->f52 + (!o->sdc.w130 ? -0.0f : 0.0f);
    a->f56 = o->f56 + 274.28571f;
}

void func_0c160da8(LA *a, LA *o, LA *p)
{
    float f;
    if (a->wcc.arrcc[0]) { if (p->b32) goto m; f = -33.3333321f; }
    else { if (p->b32) goto m; f = -83.33333f; }
    goto d;
m:  f = -53.3333321f;
d:
    if (!o->sdc.w130) a->f52 = p->f52 + f;
    else a->f52 = p->f52 - f;
    a->f56 = p->f56;
}
