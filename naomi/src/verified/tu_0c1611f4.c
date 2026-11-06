/* Linked actor drift/state handlers dispatched from table_0c25156c. */
#include "objects.h"
#define LA struct LinkedActor
#define B(a, o) (((unsigned char *)(a))[o])
extern void (*table_0c25156c[])(LA *);
extern int func_0c02850e(LA *);
extern char func_0c02a026(LA *);
extern void func_0c037d0c(LA *), func_0c037688(LA *);
void func_0c16126a(LA *, LA *);

void func_0c1611f4(LA *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (!func_0c02850e(a)) {
        a->b4++;
        a->sdc.b12c = 0;
    }
    func_0c02a026(a);
    func_0c037d0c(a);
}

void func_0c16123e(LA *a)
{
    table_0c25156c[(unsigned char)a->b5](a);
}

void func_0c161250(LA *a, LA *o)
{
    a->b5++;
    B(a, 0x13c) = 16;
    B(a, 0x13d) = 16;
    B(a, 0x13e) = 32;
    B(a, 0x13f) = 32;
    func_0c16126a(a, o);
}

void func_0c16126a(LA *a, LA *o)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!func_0c02850e(a)) {
        a->b4++;
        a->sdc.b12c = 0;
        return;
    }
    goto e;
e:
    func_0c037d0c(a);
}

void func_0c1612d4(LA *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c1612e2(LA *a)
{
    func_0c037688(a);
}
