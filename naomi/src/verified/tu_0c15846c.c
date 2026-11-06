#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct Spawn8_0c2507e8 { short x, y; unsigned char b4, b5; char b6; unsigned char b7; };
struct Offset6_0c250834 { short x, y, z; };
extern struct LinkedActor *func_0c0374da(int, int, int);
extern void (*table_0c250808[])(struct LinkedActor *);
extern void (*table_0c250818[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c250828[])(struct LinkedActor *);
extern void (*table_0c25084c[])(struct LinkedActor *);
extern struct Spawn8_0c2507e8 dat_0c2507e8[];
extern struct Offset6_0c250834 dat_0c250834[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c037688(struct LinkedActor *), func_0c02a0c4(struct LinkedActor *, int, int), func_0c037d0c(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c1a72d4(struct LinkedActor *, int);
void func_0c1584a0(struct LinkedActor *);
void func_0c158610(struct LinkedActor *);
void func_0c158770(struct LinkedActor *, struct LinkedActor *);
void func_0c1587f2(struct LinkedActor *);
struct LinkedActor *func_0c15846c(struct LinkedActor *owner, struct LinkedActor *other, char mode)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 1, 0))) {
        a->p16 = func_0c1584a0;
        a->p24 = owner;
        a->p20 = other;
        a->b32 = mode;
    }
    return a;
}
void func_0c1584a0(struct LinkedActor *a)
{
    table_0c250808[a->b4](a);
}
void func_0c1584b2(struct LinkedActor *a)
{
    struct LinkedActor *p, *q;
    struct Spawn8_0c2507e8 *t;
    p = a->p24;
    a->b4++;
    a->w38 = 0x1802;
    a->sdc = p->sdc;
    a->sdc.b12c = 1;
    a->b2 = p->b2;
    a->b1 = p->b1;
    a->v80.x = p->v80.x;
    a->v80.y = p->v80.y;
    a->b1a3 = p->b1a3;
    a->b1a4 = p->b1a4;
    a->b48 = p->b48;
    a->v80 = p->v80;
    a->b36 = p->b36;
    a->sdc.b12c = 1;
    t = &dat_0c2507e8[a->b32];
    a->b36 = t->b4;
    if (a->b32 == 0 || a->b32 == 1) q = a->p24;
    else q = a->p20;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&q->f52;
    if (A(q)->w130 == 0) a->f52 += t->x * 1.66666663f;
    else a->f52 += -(t->x * 1.66666663f);
    a->f56 += t->y * 2.1428571f;
    ((unsigned char *)a)[0x19c] = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = t->b7;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 23, t->b6);
    func_0c158610(a);
}
void func_0c158610(struct LinkedActor *a)
{
    struct LinkedActor *p = a->p24;
    if (p->b4 >= 2) {
        a->b4++;
        a->sdc.b12c = 0;
        return;
    }
    table_0c250818[a->b32](a, p);
}
void func_0c158646(struct LinkedActor *a)
{
    table_0c250828[(unsigned char)a->b5](a);
}
void func_0c158658(struct LinkedActor *a, struct LinkedActor *b)
{
    struct Offset6_0c250834 *t;
    float k;
    if (A(b)->b141 == 0 || A(b)->b1d0 != 21 || A(b)->b1e9 != 0) {
        a->b4++;
        a->sdc.b12c = 0;
        return;
    }
    k = 1.66666663f;
    t = dat_0c250834;
    if ((a->sdc.w130 = b->sdc.w130) == 0) a->f52 = b->f52 + t[b->sdc.b140].x * k;
    else a->f52 = b->f52 - t[b->sdc.b140].x * k;
    a->f56 = b->f56 + t[b->sdc.b140].y * 2.1428571f;
    A(a)->i72 = t[b->sdc.b140].z;
    if (A(b)->b141 == 2) {
        a->b5++;
        a->b36 = 11;
        func_0c1a72d4(b, 17);
        func_0c158770(a, b);
    }
}
void func_0c158770(struct LinkedActor *a, struct LinkedActor *b)
{
    func_0c02a026(a);
    if (A(a)->b141) {
        a->b5++;
        func_0c15846c(b, a, A(b)->b1a3 + 2);
    }
    func_0c037d0c(a);
}
void func_0c1587a8(struct LinkedActor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->sdc.b12c = 0;
    }
}
void func_0c1587ca(struct LinkedActor *a)
{
    table_0c25084c[(unsigned char)a->b5](a);
}
void func_0c1587dc(struct LinkedActor *a, struct LinkedActor *b)
{
    a->b5++;
    a->f56 = A(b)->f41c;
    A(a)->f84 = 1.5f;
    func_0c1587f2(a);
}
void func_0c1587f2(struct LinkedActor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->sdc.b12c = 0;
        return;
    }
    func_0c037d0c(a);
}
void func_0c158824(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}
void func_0c158832(struct LinkedActor *a)
{
    func_0c037688(a);
}
