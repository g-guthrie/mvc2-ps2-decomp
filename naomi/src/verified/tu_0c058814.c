#include "objects.h"

struct C1d2 { unsigned char pad[0x1d2]; char b1d2; };

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c058814(struct Actor *a)
{
    struct Actor *p;
    int n;

    a->b1f2 = 3;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->f92 = 5.83333302f;
        a->f104 = -0.1041666642f;
        a->f96 = 12.85714245f;
        a->f108 = -0.80357140303f;
        if (((struct C1d2 *)a)->b1d2) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        func_0c02a0c4(a, 15, 33);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c025900(a, 0, 0);
        p = a->p1c8;
        p->p1b4 = a;
        p->b1f6 = 2;
        n = 68;
        if (a->b255 == 3) {
            p->b1a1 = n;
            a->b1a1 = n;
        } else {
            p->b1a1 = a->b1a3 + 67;
            a->b1a1 = a->b1a3 + 67;
        }
    }
}

void func_0c0588ca(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        func_0c043324(a);
        a->b7++;
        func_0c02a0c4(a, 15, 34);
    }
}

void func_0c058934(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
