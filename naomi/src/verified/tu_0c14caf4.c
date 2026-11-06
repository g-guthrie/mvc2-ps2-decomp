/* Whole unit 0x0c14caf4..0x0c14d188. The unit's last function continues after
 * the pool at 0x0c14d09c, so the unit extends through the pool at 0x0c14d164.
 * func_0c14cee4 has a 16-byte frame in retail; the unused 12-byte local
 * reproduces it. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))

extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern float func_0c1ec2c0(int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c14fb9c(struct LinkedActor *);
extern void func_0c14b940(struct LinkedActor *, int, int);
extern struct ActorFlags *dat_0c2d6f84;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c250300[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c250314[])(struct LinkedActor *);

void func_0c14cee4(struct LinkedActor *a, struct LinkedActor *owner);

void func_0c14caf4(struct LinkedActor *a)
{
    struct LinkedActor *owner = a->p24;
    char *state = &A(owner)->sub2a4.b0;

    A(a)->f264 -= 0.06f;
    if (A(a)->f264 < 0.0f)
        A(a)->f264 = 0.0f;
    if (a->s28-- < 0) {
        a->b4++;
        A(a)->b12c = 0;
        *state = 0;
    }
}

void func_0c14cb32(struct LinkedActor *a)
{
    struct LinkedActor *owner = a->p24;
    struct ActorSub2a4 *sub;

    table_0c250300[(unsigned char)a->b5](a, owner);
    sub = &A(owner)->sub2a4;
    if (sub->b1) {
        a->b4++;
        A(a)->b12c = 0;
        sub->b0 = 0;
    }
}

void func_0c14cb6a(struct LinkedActor *a, struct LinkedActor *owner)
{
    float wave;
    struct ActorMotionFixed3 *m;
    struct Actor *p;

    if (A(a)->f80 > 1.0f) {
        A(a)->f80 = 1.0f;
        A(a)->f84 = 1.0f;
    } else {
        A(a)->f80 += 0.04f;
        A(a)->f84 += 0.04f;
    }
    if (A(a)->b19e) {
        p = A(a)->p1b0;
        if (p->b3 != 0 || p->b411 != 0 || (A(a)->b19e & 1) != 0)
            goto busy;
        m = (struct ActorMotionFixed3 *)&p->l414;
        if (!((m->x_speed & 0x07000000) | (m->y_speed & 0))) {
            a->b5 = 4;
            a->s28 = 300;
            a->s30 = 90;
            a->b35 = p->b1;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            func_0c02a0c4(a, 23, 29);
            func_0c14cee4(a, owner);
            return;
        }
busy:
        a->b5++;
        a->s28 = 40;
        func_0c02a0c4(a, 23, 29);
        return;
    }
    if (a->s28-- == 0) {
        a->b5++;
        func_0c02a0c4(a, 23, 1);
    }
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    wave = func_0c1ec2c0((int)(a->s30 * 65536.0f / 360.0f + 0.5f) & 0xffff) * 5.0f;
    a->f56 += wave;
    if ((a->s30 -= 6) == 0)
        a->s30 = 360;
    func_0c037d0c(a);
}

void func_0c14cd00(struct LinkedActor *a)
{
    if (A(a)->f80 > 1.0f) {
        A(a)->f80 = 1.0f;
        A(a)->f84 = 1.0f;
    } else {
        A(a)->f80 += 0.04f;
        A(a)->f84 += 0.04f;
    }
    func_0c02a026(a);
    if (A(a)->b143 < 0) {
        a->b5++;
        func_0c02a0c4(a, 23, 30);
    }
}

void func_0c14cd84(struct LinkedActor *a, struct LinkedActor *owner)
{
    char *state = &A(owner)->sub2a4.b0;

    goto call;
call:
    func_0c02a026(a);
    A(a)->f80 -= 0.050000001f;
    if (!(A(a)->f80 > 0.0f))
        A(a)->f80 = 0.0f;
    if (A(a)->b143 < 0) {
        a->b4++;
        A(a)->b12c = 0;
        *state = 0;
    }
}

void func_0c14cdd0(struct LinkedActor *a, struct LinkedActor *owner)
{
    float wave;
    char *state = &A(owner)->sub2a4.b0;

    if (A(a)->f80 > 1.0f) {
        A(a)->f80 = 1.0f;
        A(a)->f84 = 1.0f;
    } else {
        A(a)->f80 += 0.04f;
        A(a)->f84 += 0.04f;
    }
    func_0c02a026(a);
    if (a->s28-- == 0) {
        a->b4++;
        A(a)->b12c = 0;
        *state = 0;
        return;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    wave = func_0c1ec2c0((int)(a->s30 * 65536.0f / 360.0f + 0.5f) & 0xffff) * 5.0f;
    a->f56 += wave;
    if ((a->s30 -= 6) == 0)
        a->s30 = 360;
}

void func_0c14cee4(struct LinkedActor *a, struct LinkedActor *owner)
{
    struct Actor *p;
    struct LinkedActorVec3 unused;
    float wave;
    struct Actor *t = A(owner)->p20c;

    A(a)->b12c = 1;
    a->b36 = 9;
    func_0c02a026(a);
    if (A(a->p24)->b19f || a->s28-- == 0)
        goto stop;
    p = A(a)->p1b0;
    if (p->b411 || p->w420 == 0)
        goto stop;
    if (!A(owner)->w420) {
stop:
        a->b5 = 1;
        a->s28 = 30;
        func_0c02a0c4(a, 23, 29);
        return;
    }
    if (A(a)->f80 > 1.0f) {
        A(a)->f80 = 1.0f;
        A(a)->f84 = 1.0f;
    } else {
        A(a)->f80 += 0.04f;
        A(a)->f84 += 0.04f;
    }
    if (a->s28 % 10 == 0)
        func_0c048bb0(t, -2);
    A(a)->w130 = t->w130;
    a->f52 = t->f52;
    a->f52 += A(a)->w130 ? -53.3333321f : 53.3333321f;
    a->f56 = t->f56 + 68.57143f;
    a->f60 = t->f60;
    wave = func_0c1ec2c0((int)(a->s30 * 65536.0f / 360.0f + 0.5f) & 0xffff) * 42.85714f;
    a->f56 += wave;
    if ((a->s30 -= 3) == 0)
        a->s30 = 360;
}

void func_0c14d050(struct LinkedActor *a)
{
    table_0c250314[(unsigned char)a->b5](a);
    if (a->b1 != a->p24->b1)
        func_0c14fb9c(a);
}

void func_0c14d080(struct LinkedActor *a)
{
    float one;
    if (A(a)->b141 == 1) {
        func_0c02a026(a);
        return;
    }
    if (dat_0c2d6f84->flags % 14 == 0 && (unsigned char)a->b35 <= 3) {
        A(a)->b19c = 66;
        A(a)->b19d = 66;
        A(a)->b1a1 = 63;
        A(a)->w1ac = 0;
        A(a)->b19e = 0;
        A(a)->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
    func_0c02a026(a);
    A(a)->f84 += 0.200000003f;
    one = 1.0f;
    if (!(one > A(a)->f84)) {
        a->b5++;
        func_0c14b940(a, 3, 0);
    }
    A(a)->f80 = one;
    if (!(dat_0c2d6f84->flags & 1))
        A(a)->f80 = 0.800000012f;
    func_0c037d0c(a);
}
