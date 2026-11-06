/* Linked actor chase and landing states; reviewed span 0x0c17ef88..0x0c17f35c. */
#include "objects.h"
#define LA struct LinkedActor
#define A(a) ((struct Actor *)(a))
struct Range_25458c { float x, y; };
extern char func_0c02a026(LA *);
extern void func_0c037d0c(LA *);
extern void func_0c02a0c4(LA *, int, int);
extern void func_0c180e44(LA *);
extern void func_0c180b86(LA *);
extern void func_0c180be4(LA *);
extern void func_0c181030(LA *);
extern void func_0c180a8c(LA *);
extern int func_0c180b5c(LA *);
extern int func_0c180c20(LA *);
extern void func_0c180e1a(LA *);
extern int func_0c180a48(LA *, LA *);
extern void func_0c18104c(LA *);
extern void func_0c181060(LA *);
extern void func_0c18102c(LA *);
extern const struct Range_25458c dat_0c25458c[];
extern void (*table_0c254044[])(LA *);
extern void (*table_0c25404c[])(LA *);

void func_0c17ef88(LA *a)
{
    LA *o = a->p24;
    float x;
    if (((unsigned char *)o)[0x159] != 7 || ((unsigned char *)o)[0x158] != 2) {
        func_0c180e44(a);
        return;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (A(o)->f41c > a->f56) {
        a->f56 = A(o)->f41c;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
    }
    if (a->sdc.b140 >= 0) {
        a->b6++;
        a->f108 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = -2.1428571f;
        x = 6.66666651f;
        if (!A(o)->b1d2) x = -6.66666651f;
        a->f92 = x;
    }
    func_0c037d0c(a);
}

void func_0c17f04a(LA *a)
{
    LA *o = a->p24;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c180b86(a);
    func_0c180be4(a);
    if (A(o)->f41c > a->f56) {
        a->f56 = A(o)->f41c;
        a->f96 = a->f108 = 0.0f;
    }
    if (func_0c02a026(a) < 0) {
        func_0c180e44(a);
        return;
    } else {
    func_0c037d0c(a);
    }
}

void func_0c17f104(LA *a)
{
    union LinkedActorWcc *w = &a->wcc;
    LA *o = a->p24;
    struct ActorSub2a4 *g = &A(o)->sub2a4;
    LA *t = w->pointer_value;
    func_0c181030(a);
    if (!a->b6) {
        float k, d, m;
        a->b6++;
        k = -26.666666031f;
        d = a->f52 - t->f52;
        if (d > 0.0f) k = 26.666666031f;
        d += k;
        m = d;
        if (0.0f > m) m = -m;
        if (m > dat_0c25458c[t->b1].x) m = dat_0c25458c[t->b1].x;
        if (0.0f > d) m = -m;
        a->f92 = m;
        if (0.0f > (m = (d = a->f56 - t->f56) - dat_0c25458c[t->b1].y)) a->f96 = dat_0c25458c[t->b1].y;
        else a->f96 = m;
        func_0c180a8c(a);
        func_0c02a0c4(a, 25, 1);
        return;
    }
    goto g; g:
    if (!g->b3 || ((signed char *)o)[0x411]) goto kill;
    if (func_0c180b5c(a) || func_0c180c20(a)) {
        func_0c180e1a(a);
        return;
    }
    goto LB0; LB0:
    func_0c180a8c(a);
    if (func_0c02a026(a) >= 0 || func_0c180a48(a, t)) return;
kill:
    func_0c180e44(a);
}

void func_0c17f26e(LA *a)
{
    table_0c254044[(unsigned char)a->b5](a);
}

void func_0c17f280(LA *a)
{
    signed char *w = (signed char *)&a->wcc;
    if (!a->b6) {
        a->b6++;
        if (w[7] >= 0) func_0c18104c(a);
        func_0c02a0c4(a, 25, 3);
    } else {
        goto e; e:
        if (func_0c02a026(a) < 0) {
            func_0c181060(a);
            return;
        }
    }
    goto t; t:
    func_0c18102c(a);
}

void func_0c17f2d0(LA *a)
{
    signed char *w = (signed char *)&a->wcc;
    if (!a->b6) {
        a->b6++;
        if (w[7] >= 0) func_0c18104c(a);
        func_0c02a0c4(a, 25, 2);
    } else {
        goto e; e:
        if (func_0c02a026(a) < 0) {
            func_0c181060(a);
            return;
        }
    }
    goto t; t:
    func_0c18102c(a);
}

void func_0c17f320(LA *a)
{
    table_0c25404c[a->b4](a);
}
