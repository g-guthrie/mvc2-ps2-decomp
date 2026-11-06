/* Linked-actor launch family: spawners, b4/b32 dispatchers and the launch arcs they select. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(struct LinkedActor *, int, int);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c0344a0(struct LinkedActor *, int);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c25761c[])(struct LinkedActor *);
extern void (*table_0c25762c[])(struct LinkedActor *);
extern void (*table_0c25767c[])(struct LinkedActor *);
struct LaunchArc2 { float x, vx; };
struct LaunchArc3 { float x, y, vx; };
extern struct LaunchArc2 table_0c25763c[];
extern struct LaunchArc3 table_0c25764c[];
void func_0c190830(struct LinkedActor *a);
void func_0c190cf6(struct LinkedActor *a);

struct LinkedActor *func_0c1906c4(struct LinkedActor *owner)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c190830;
        a->p24 = owner;
        a->b32 = 0;
        a->w38 = 0x501;
    }
    return a;
}

struct LinkedActor *func_0c1906f6(struct LinkedActor *o)
{
    struct LinkedActor *a;
    int i;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c190830;
        a->p24 = o->p24;
        a->p20 = o;
        a->b32 = 1;
        a->b33 = 0;
        a->b34 = 0;
        a->w38 = 0x501;
    }
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c190830;
        a->p24 = o->p24;
        a->p20 = o;
        a->b32 = 1;
        a->b33 = 1;
        a->b34 = 1;
        a->w38 = 0x501;
    }
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c190830;
        a->p24 = o->p24;
        a->p20 = o;
        a->b32 = 2;
        a->b33 = 0;
        a->b34 = 0;
        a->w38 = 0x501;
    }
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c190830;
        a->p24 = o->p24;
        a->p20 = o;
        a->b32 = 2;
        a->b33 = 0;
        a->b34 = 1;
        a->w38 = 0x501;
    }
    i = 0;
    while (i < 3) {
        if ((a = func_0c0374da(0, 3, 0)) != 0) {
            a->p16 = func_0c190830;
            a->p24 = o->p24;
            a->p20 = o;
            a->b32 = 3;
            a->b33 = i;
            a->b34 = 0;
            a->w38 = 0x501;
        }
        if ((a = func_0c0374da(0, 3, 0)) != 0) {
            a->p16 = func_0c190830;
            a->p24 = o->p24;
            a->p20 = o;
            a->b32 = 3;
            a->b33 = i;
            a->b34 = 1;
            a->w38 = 0x501;
        }
        i++;
    }
    return a;
}

void func_0c190830(struct LinkedActor *a)
{
    table_0c25761c[a->b4](a);
}

void func_0c190842(struct LinkedActor *a)
{
    a->b4++;
    table_0c25762c[a->b32](a);
}

void func_0c19085e(struct LinkedActor *a)
{
    a->sdc = a->p24->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->b36 = 0;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    func_0c02a0c4(a, 23, 12);
}

void func_0c1908dc(struct LinkedActor *a)
{
    a->sdc = a->p20->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p20->b2;
    a->b1 = a->p20->b1;
    a->v80.x = a->p20->v80.x;
    a->v80.y = a->p20->v80.y;
    a->b1a3 = a->p20->b1a3;
    a->b1a4 = a->p20->b1a4;
    a->b48 = a->p20->b48;
    a->v80 = a->p20->v80;
    a->b36 = a->p20->b36;
    a->sdc.w130 = a->b34;
    a->b36 = 12;
    a->f52 = a->p20->f52 + (a->sdc.w130 ? -133.33333f : 133.33333f);
    a->f56 = a->p20->f56;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->sdc.w130 ? -15.0f : 15.0f;
    a->sdc.b13c = 16;
    a->sdc.b13d = 16;
    a->sdc.b13e = 48;
    a->sdc.b13f = 48;
    func_0c02a0c4(a, 23, 13);
}

void func_0c1909e2(struct LinkedActor *a)
{
    a->sdc = a->p20->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p20->b2;
    a->b1 = a->p20->b1;
    a->v80.x = a->p20->v80.x;
    a->v80.y = a->p20->v80.y;
    a->b1a3 = a->p20->b1a3;
    a->b1a4 = a->p20->b1a4;
    a->b48 = a->p20->b48;
    a->v80 = a->p20->v80;
    a->b36 = a->p20->b36;
    a->sdc.w130 = a->b34;
    a->b36 = 12;
    a->f52 = a->p20->f52 + (a->sdc.w130 ? table_0c25763c[(unsigned char)a->b33].x : -table_0c25763c[(unsigned char)a->b33].x);
    a->f56 = a->p20->f56;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->sdc.w130 ? table_0c25763c[(unsigned char)a->b33].vx : -table_0c25763c[(unsigned char)a->b33].vx;
    a->sdc.b13c = 16;
    a->sdc.b13d = 16;
    a->sdc.b13e = 48;
    a->sdc.b13f = 48;
    func_0c02a0c4(a, 23, 14);
}

void func_0c190b10(struct LinkedActor *a)
{
    a->sdc = a->p20->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p20->b2;
    a->b1 = a->p20->b1;
    a->v80.x = a->p20->v80.x;
    a->v80.y = a->p20->v80.y;
    a->b1a3 = a->p20->b1a3;
    a->b1a4 = a->p20->b1a4;
    a->b48 = a->p20->b48;
    a->v80 = a->p20->v80;
    a->b36 = a->p20->b36;
    a->sdc.w130 = a->b34;
    a->b36 = 12;
    a->f52 = a->p20->f52 + (a->sdc.w130 ? -table_0c25764c[(unsigned char)a->b33].x : table_0c25764c[(unsigned char)a->b33].x);
    a->f56 = a->p20->f56 + table_0c25764c[(unsigned char)a->b33].y;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->sdc.w130 ? table_0c25764c[(unsigned char)a->b33].vx : -table_0c25764c[(unsigned char)a->b33].vx;
    a->sdc.b13c = 16;
    a->sdc.b13d = 16;
    a->sdc.b13e = 48;
    a->sdc.b13f = 48;
    func_0c02a0c4(a, 23, 15);
}

void func_0c190c46(struct LinkedActor *a)
{
    table_0c25767c[a->b32](a);
}

void func_0c190c5a(struct LinkedActor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c190cf6(a);
        return;
    }
    if (a->sdc.b141) {
        a->sdc.b141 = 0;
        func_0c1906f6(a);
        func_0c0344a0(a, 32);
    }
}

void func_0c190cb6(struct LinkedActor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    if (!func_0c028642(a))
        func_0c190cf6(a);
}

void func_0c190cf6(struct LinkedActor *a)
{
    a->b4 = 3;
    a->sdc.b12c = 0;
    func_0c037688(a);
}
