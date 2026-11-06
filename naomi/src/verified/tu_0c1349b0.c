/* 0x0c1349b0..0x0c134db0: spawned launch-effect child actors (create, init from owner, step states). */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct Pose_0c24e43c { short w0, w2, w4, w6; };
extern struct LinkedActor *func_0c0374da(struct LinkedActor *, int, int);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c0346da(struct LinkedActor *, int);
extern void func_0c1d53e4(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct Pose_0c24e43c table_0c24e43c[];
extern void (*table_0c24e42c[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c24e464[])(struct LinkedActor *, struct LinkedActor *);
void func_0c134a3c(struct LinkedActor *a);

struct LinkedActor *func_0c1349b0(struct LinkedActor *o)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 1, 0))) {
        a->p16 = func_0c134a3c;
        a->p24 = o;
        a->p20 = o;
        a->b1 = o->b1;
        a->b32 = 0;
        a->b33 = 0;
        a->w38 = 0x302;
        A(a)->f92 = o->f52;
    }
    return a;
}

struct LinkedActor *func_0c1349f4(struct LinkedActor *o)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(o, 1, 2))) {
        a->p16 = func_0c134a3c;
        a->p24 = o->p24;
        a->p20 = o;
        a->b1 = o->b1;
        a->b32 = o->b32 + 1;
        a->b33 = 0;
        a->w38 = 0x302;
        A(a)->f92 = o->f52;
    }
    return a;
}

void func_0c134a3c(struct LinkedActor *a)
{
    table_0c24e42c[a->b4](a, a->p24);
}

void func_0c134a50(struct LinkedActor *a, struct LinkedActor *o)
{
    register void *zero = 0;
    register struct LinkedActor *p = a->p20;
    unsigned char *q = a->pad9b;
    a->b4++;
    a->b5 = (int)zero;
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
    q[1] = 3;
    q[0] = (int)zero;
    *(int *)&A(a)->b13c = 0x60003030;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = a->b32 + 72;
    A(a)->w1ac = (int)zero;
    A(a)->b19e = (int)zero;
    A(a)->p1c4 = (int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->f52 = 80.0f;
    if (A(p)->w130)
        a->f52 = a->f52 + a->f92;
    else
        a->f52 = -a->f52 + a->f92;
    a->f56 = ((struct MeActor *)o)->f41c;
    A(a)->f92 = 0.0f;
    a->f104 = 0.0f;
    a->s28 = table_0c24e43c[a->b32].w0;
    a->s30 = table_0c24e43c[a->b32].w2;
    a->f96 = table_0c24e43c[a->b32].w4 * 2.1428571f / 256.0f;
    a->f108 = table_0c24e43c[a->b32].w6 * 2.1428571f / 256.0f;
    A(a)->b159 = 22;
    A(a)->b158 = 44;
    func_0c02a0c4(a, A(a)->b159, A(a)->b158);
    func_0c1d53e4(a);
    a->pad0 = 1;
}

void func_0c134bf2(struct LinkedActor *a)
{
    unsigned char *p = a->pad9b;
    if (A(a)->b19f) *p = 1;
    if (func_0c02a026(a) < 0) {
        a->b5++;
        func_0c0346da(a, 22);
        func_0c02a0c4(a, 22, 45);
    }
}

void func_0c134c36(struct LinkedActor *a)
{
    unsigned char *p = &a->pad9b[0];
    func_0c02a026(a);
    if (*p || A(a)->b19f || --a->s28 == 0) {
        a->b5++;
        func_0c02a0c4(a, 22, 46);
        return;
    }
    a->f56 += a->f96;
    a->f96 += a->f108;
}

void func_0c134cc4(struct LinkedActor *a)
{
    func_0c02a026(a);
    if (A(a)->b141) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c134ce8(struct LinkedActor *a, struct LinkedActor *o)
{
    struct ActorSub2a4 *s = &A(o)->sub2a4;
    a->b49 = -2;
    if (o->b5 != 0 || o->b1d0 != 29) {
        a->b4++;
        A(a)->b12c = 0;
        return;
    }
    if (a->b32 < 4 && a->s30 != 0 && --a->s30 == 0 && func_0c1349f4(a))
        s->b21++;
    table_0c24e464[(unsigned char)a->b5](a, o);
    func_0c037d0c(a);
}

void func_0c134d76(struct LinkedActor *a, struct LinkedActor *o)
{
    struct ActorSub2a4 *s = &A(o)->sub2a4;
    a->b4++;
    A(a)->b12c = 0;
    s->b21--;
}

void func_0c134d90(struct LinkedActor *a)
{
    func_0c037688(a);
}
