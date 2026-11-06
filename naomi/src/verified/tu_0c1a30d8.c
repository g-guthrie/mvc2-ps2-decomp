/* Owner-follow effect lifecycle callbacks (0x0c1a30d8-0x0c1a3444). Imports: __slow_mvn=0x0c1fb838, __quick_odd_mvn=0x0c1fb7a0. */
#include "objects.h"
#define LA struct LinkedActor
/* Owner control bytes at LinkedActor+0x2a4 (past the shared layout). */
struct Ctl2a4_tu_0c1a30d8 { unsigned char b0, b1; };
extern void func_0c02a0c4(LA *, int, int);
extern char func_0c02a026(LA *);
extern void func_0c1a3484(LA *, int);
extern void func_0c029f0e(LA *, int, int, int);
extern void func_0c02a18c(LA *, int, int, int);
extern void func_0c037688(LA *);
extern void (*table_0c258f94[])(LA *);

void func_0c1a30d8(LA *a)
{
    a->b4++;
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
    a->b36 = 7;
    func_0c02a0c4(a, 21, 11);
}

void func_0c1a314c(LA *a)
{
    LA *p = a->p24;
    struct Ctl2a4_tu_0c1a30d8 *c = (struct Ctl2a4_tu_0c1a30d8 *)((char *)p + 0x2a4);
    switch ((unsigned char)a->b5) {
    case 0:
        func_0c02a026(a);
        if (a->sdc.b141) {
            a->b5++;
            func_0c1a3484(a, 2);
        }
        break;
    case 1:
        if (c->b1) {
            a->b5++;
            a->f52 = a->p24->f52;
            break;
        }
        if (a->p24->b1d0 == 21 && !a->p24->b5)
            break;
        goto set3;
    case 2:
        if (a->p24->b1d0 == 21 && !a->p24->b5)
            goto chk;
    set3:
        a->b5 = 3;
        func_0c02a0c4(a, 21, 13);
        break;
    chk:
        goto l1;
    l1:
        if (0x150b == (unsigned short)a->p24->sdc.w158.short_value)
            goto adv;
        break;
    case 3:
        if (func_0c02a026(a) < 0) {
        adv:
            a->b4++;
            a->sdc.b12c = 0;
        }
        break;
    }
}

void func_0c1a341e(LA *a);

void func_0c1a3230(LA *a)
{
    unsigned char c;
    a->sdc.b12c = 0;
    if (!a->b4) {
        a->b4++;
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
        a->b1a4 = ((LA *)((struct Actor *)a->p24)->p1c8)->b1a4;
        a->b36 = 7;
        *(unsigned char *)&a->b33 = 255;
    }
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&a->p24->f52;
    c = a->p24->sdc.b140;
    if (!c || a->p24->sdc.w158.bytes[1] != 15) {
        func_0c1a341e(a);
        return;
    }
    a->sdc.b12c = 1;
    if (c != *(unsigned char *)&a->b33) {
        a->b33 = c;
        func_0c029f0e(a, 27, 0, c - 1);
    }
}

void func_0c1a3310(LA *a)
{
    table_0c258f94[a->b4](a);
}

void func_0c1a3348(LA *a)
{
    a->b4++;
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
    func_0c02a18c(a, 21, 10, 6);
    if (a->sdc.b140)
        a->l72 = -4096;
}

void func_0c1a33d6(LA *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->sdc.b12c = 0;
    } else if (a->sdc.b140)
        a->l72 = -4096;
    else
        a->l72 = 0;
}

void func_0c1a3410(LA *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c1a341e(LA *a)
{
    func_0c037688(a);
}
