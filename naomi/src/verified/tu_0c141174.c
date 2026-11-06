/* Linked effect actors spawned from an owner: spawner, step dispatcher and
 * per-state handlers. The scatter setup at 0x0c1414bc reuses one short `d`
 * for both random offsets and the direction (retail keeps it live through the
 * switch's fallthrough path), and indexes the velocity table as a flat
 * short array (n * 3 + k) with the 65536.0f divisor held in a local. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))

typedef void (*Step141174)(struct LinkedActor *, struct LinkedActor *);

extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c02849a(void);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c1d58cc(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct Dat_13bb5c dat_0c2f8338;
extern Step141174 dat_0c24f758[], dat_0c24f764[], dat_0c24f774[], dat_0c24f780[];
extern Step141174 dat_0c24f790[], dat_0c24f798[], dat_0c24f7a8[];
extern short dat_0c24f6e8[][3];
extern struct OffsetXY16 dat_0c24f748[];

struct LinkedActor *func_0c141174(struct LinkedActor *owner, unsigned char mode, unsigned char value);
void func_0c1411c2(struct LinkedActor *a);
void func_0c1411d8(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1411ea(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1412b8(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c14131c(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c14139c(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c141480(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1414aa(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1414bc(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c141642(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c14165c(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c14167e(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1416e2(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c141710(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1417f4(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c14181e(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1418d4(struct LinkedActor *a, struct LinkedActor *owner);
void func_0c1418e2(struct LinkedActor *a);

struct LinkedActor *func_0c141174(struct LinkedActor *owner, unsigned char mode, unsigned char value)
{
    struct LinkedActor *a;

    if ((a = func_0c0374da(0, 1, 0))) {
        a->p16 = (void (*)(struct LinkedActor *))func_0c1411c2;
        a->w38 = 0x0d00;
        a->p24 = owner;
        a->b1 = owner->b1;
        *(&a->b32) = mode;
        *(&a->b33) = value;
    }
    return a;
}

void func_0c1411c2(struct LinkedActor *a)
{
    dat_0c24f758[a->b32](a, a->p24);
}

void func_0c1411d8(struct LinkedActor *a, struct LinkedActor *owner)
{
    dat_0c24f764[a->b4](a, owner);
}

void func_0c1411ea(struct LinkedActor *a, struct LinkedActor *owner)
{
    a->b4++;
    a->sdc = owner->sdc;
    a->sdc.b12c = 1;
    a->b2 = owner->b2;
    a->b1 = owner->b1;
    a->v80.x = owner->v80.x;
    a->v80.y = owner->v80.y;
    a->b1a3 = owner->b1a3;
    a->b1a4 = owner->b1a4;
    a->b48 = owner->b48;
    a->v80 = owner->v80;
    a->b36 = owner->b36;
    a->sdc.b12c = 1;
    a->b49 = 1;
    A(a)->b1a1 = owner->b32 + 63;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    a->f52 = owner->f52;
    a->f56 = owner->f56;
    a->f60 = owner->f60;
    func_0c02a0c4(a, 22, (signed char)owner->b32 + 6);
    a->s30 = 0;
    func_0c1412b8(a, owner);
}

void func_0c1412b8(struct LinkedActor *a, struct LinkedActor *owner)
{
    a->b36 = owner->b36;
    if ((unsigned char)A(owner)->b159 != 22) {
        a->b4++;
        func_0c1418d4(a, owner);
        return;
    }
    dat_0c24f774[(unsigned char)a->b5](a, owner);
}

void func_0c14131c(struct LinkedActor *a, struct LinkedActor *owner)
{
    a->f52 = owner->f52;
    a->f56 = owner->f56;
    a->f60 = owner->f60;
    if (a->s30 == 0) {
        goto call;
call:
        func_0c037d0c(a);
        if (A(a)->b19e) {
            A(owner)->b1a0 = A(a)->b1a0;
            a->s30 = 1;
        }
    }
    if (!(owner->f56 > A(owner)->f41c + 480.0f)) {
        A(a)->b1a1 = 87;
        A(a)->w1ac = 0;
        A(a)->b19e = 0;
        A(a)->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b5++;
    }
}

void func_0c14139c(struct LinkedActor *a, struct LinkedActor *owner)
{
    struct ActorSub2a4 *s = &A(owner)->sub2a4;

    a->f52 = owner->f52;
    a->f56 = owner->f56;
    a->f60 = owner->f60;
    if (dat_0c2f8338.w3c & (1 << dat_0c2f8338.b3b))
        return;
    if (A(a)->b1a0) {
        A(owner)->b1a0 = A(a)->b1a0;
        A(a)->b1a0--;
    } else {
        A(a)->b1a1 = 87;
        A(a)->w1ac = 0;
        A(a)->b19e = 0;
        A(a)->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        A(a)->w1ac |= 64;
        func_0c037d0c(a);
    }
    if (s->b1) {
        a->b5++;
        A(a)->b1a1 = owner->b32 + 63;
        A(a)->w1ac = 0;
        A(a)->b19e = 0;
        A(a)->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
}

void func_0c141480(struct LinkedActor *a, struct LinkedActor *owner)
{
    struct ActorSub2a4 *s = &A(owner)->sub2a4;

    func_0c037d0c(a);
    if (s->b0)
        a->b4++;
}

void func_0c1414aa(struct LinkedActor *a, struct LinkedActor *owner)
{
    dat_0c24f780[a->b4](a, owner);
}

void func_0c1414bc(struct LinkedActor *a, struct LinkedActor *owner)
{
    register float ky, kx;
    short d;
    unsigned char n;

    a->b4++;
    a->sdc = owner->sdc;
    a->sdc.b12c = 1;
    a->b2 = owner->b2;
    a->b1 = owner->b1;
    a->v80.x = owner->v80.x;
    a->v80.y = owner->v80.y;
    a->b1a3 = owner->b1a3;
    a->b1a4 = owner->b1a4;
    a->b48 = owner->b48;
    a->v80 = owner->v80;
    a->b36 = owner->b36;
    a->b49 = -1;
    a->sdc.b12c = 0;
    a->f52 = owner->f52;
    a->f56 = owner->f56;
    a->f60 = owner->f60;
    d = func_0c02849a() & 127;
    kx = 1.66666663f;
    a->f52 += (64 - d) * kx;
    d = func_0c02849a() & 127;
    ky = 2.1428571f;
    a->f56 += (64 - d) * ky;
    switch (owner->b32) {
    case 0:
        d = -106;
        break;
    case 1:
        d = 106;
        break;
    }
    if (A(owner)->b1d2)
        d = -d;
    a->f52 += d;
    n = func_0c02849a() & 15;
    {
        float s = 65536.0f;
        A(a)->f92 = ((&dat_0c24f6e8[0][0])[n * 3] << 8) * kx / s;
        A(a)->f96 = ((&dat_0c24f6e8[0][0])[n * 3 + 1] << 8) * ky / s;
        A(a)->f108 = ((&dat_0c24f6e8[0][0])[n * 3 + 2] << 8) * ky / s;
    }
    a->s28 = (func_0c02849a() & 15) + 1;
    func_0c02a0c4(a, 23, (func_0c02849a() & 7) + 11);
    func_0c141642(a, owner);
}

void func_0c141642(struct LinkedActor *a, struct LinkedActor *owner)
{
    a->b36 = owner->b36;
    dat_0c24f790[(unsigned char)a->b5](a, owner);
}

void func_0c14165c(struct LinkedActor *a, struct LinkedActor *owner)
{
    if (a->s28-- == 0) {
        a->b5++;
        a->sdc.b12c = 1;
        a->s28 = 60;
    }
}

void func_0c14167e(struct LinkedActor *a, struct LinkedActor *owner)
{
    if (--a->s28 == 0) {
        a->b4++;
        func_0c1418d4(a, owner);
        return;
    }
    func_0c02a026(a);
    a->f52 += A(a)->f92;
    A(a)->f92 += A(a)->f104;
    a->f56 += A(a)->f96;
    A(a)->f96 += A(a)->f108;
}

void func_0c1416e2(struct LinkedActor *a, struct LinkedActor *owner)
{
    dat_0c24f798[a->b4](a, owner);
}

void func_0c141710(struct LinkedActor *a, struct LinkedActor *owner)
{
    short *p;
    int x, y;

    a->b4++;
    a->sdc = owner->sdc;
    a->sdc.b12c = 1;
    a->b2 = owner->b2;
    a->b1 = owner->b1;
    a->v80.x = owner->v80.x;
    a->v80.y = owner->v80.y;
    a->b1a3 = owner->b1a3;
    a->b1a4 = owner->b1a4;
    a->b48 = owner->b48;
    a->v80 = owner->v80;
    a->b36 = owner->b36;
    a->b49 = -1;
    a->sdc.b12c = 0;
    a->f52 = owner->f52;
    a->f56 = owner->f56;
    a->f60 = owner->f60;
    p = (short *)dat_0c24f748 + (unsigned char)a->b33 * 2;
    x = p[0] << 16;
    y = p[1] << 16;
    A(a)->f92 = x * 1.66666663f / 65536.0f;
    A(a)->f96 = y * 2.1428571f / 65536.0f;
    if (owner->b32 == 1)
        a->sdc.w130 ^= 1;
    func_0c02a0c4(a, 23, 19);
    a->s28 = 0;
    func_0c1417f4(a, owner);
}

void func_0c1417f4(struct LinkedActor *a, struct LinkedActor *owner)
{
    if ((unsigned char)A(owner)->b159 != 22) {
        a->b4++;
        func_0c1418d4(a, owner);
        return;
    }
    dat_0c24f7a8[(unsigned char)a->b5](a, owner);
}

void func_0c14181e(struct LinkedActor *a, struct LinkedActor *owner)
{
    struct ActorSub2a4 *s = &A(owner)->sub2a4;

    if (s->b0) {
        a->b4++;
        func_0c1418d4(a, owner);
        return;
    }
    a->f52 = owner->f52;
    a->f56 = owner->f56;
    a->f60 = owner->f60;
    a->f52 += A(a)->f92;
    a->f56 += A(a)->f96;
    if (!(a->s28 & 15)) {
        struct LinkedActorVec3 v;

        v.x = a->f52;
        v.y = a->f56;
        v.z = 0.0f;
        func_0c1d58cc(owner);
    }
    a->s28++;
}

void func_0c1418d4(struct LinkedActor *a, struct LinkedActor *owner)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c1418e2(struct LinkedActor *a)
{
    a->sdc.b12c = 0;
    func_0c037688(a);
}
