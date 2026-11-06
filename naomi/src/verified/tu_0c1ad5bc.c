/* Owner-tracking linked actor: eases toward a side offset of the owner and counts down before handing back. */
#include "objects.h"
#define LA struct LinkedActor
struct Ctl2a4 { char pad[10]; char b10, b11; };
#define CTL(o) ((struct Ctl2a4 *)((char *)(o) + 0x2a4))
#define F41C(o) (*(float *)((char *)(o) + 0x41c))
extern char func_0c02a026(LA *);
extern void func_0c02a0c4(LA *, int, int);

void func_0c1ad5bc(LA *a, LA *o)
{
    struct Ctl2a4 *s = CTL(o);
    if (!s->b11) {
        a->b7 = 5;
        a->pad0 = 1;
        a->sdc.b12c = 1;
        a->s28 = 32;
        func_0c02a0c4(a, 25, 17);
        return;
    }
    if (!s->b10) {
        a->b7++;
        a->pad0 = 0;
        a->sdc.b12c = 0;
        return;
    }
    a->f52 += (o->f52 - a->f52) / 8.0f;
    a->f56 += (o->f56 - a->f56) / 8.0f;
}

void func_0c1ad62c(LA *a, LA *o)
{
    struct Ctl2a4 *s = CTL(o);
    if (!s->b11 || s->b10) {
        a->sdc.w130 = o->sdc.w130;
        a->f52 = o->f52;
        a->f56 = o->f56;
        a->b7 = 5;
        a->pad0 = 1;
        a->sdc.b12c = 1;
        a->s28 = 32;
        func_0c02a0c4(a, 25, 17);
    }
}

void func_0c1ad66a(LA *a, struct Actor *o)
{
    float d;
    if (--a->s28 == 0) {
        a->b7++;
        a->f56 = o->f41c;
        func_0c02a026(a);
        return;
    }
    if (!a->sdc.w130) d = o->f52 + 80.0f; else d = o->f52 + -80.0f;
    a->f52 += (d - a->f52) / 8.0f;
    a->f56 += (o->f41c - a->f56) / 8.0f;
}

void func_0c1ad6d0(LA *a)
{
    func_0c02a026(a);
    if (a->sdc.b141) {
        a->b7++;
        a->sdc.w130 ^= 1;
    }
}
