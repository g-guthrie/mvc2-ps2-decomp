#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Actor *func_0c13c4bc(struct Actor *, int);

void func_0c078828(struct Actor *a)
{
    struct ActorSub2a4Timers *s;
    float dx, dy;
    struct Actor *c;
    int off, sp; short i, n;

    s = (struct ActorSub2a4Timers *)&a->sub2a4;
    a->b3f8 = 2;
    a->b328 = 5;
    a->s28--;
    if (a->s28 <= 0) {
        a->b6++;
        a->s28 = 56;
        func_0c02a0c4(a, 21, 16);
    } else {
        func_0c02a026(a);
        s->timer20--;
        if (s->timer20 > 0)
            return;
        s->timer20 = 12;
        dx = -13.33333302f;
        dy = 227.142853f;
        if (a->b1d2)
            dx = 13.33333302f;
        s->phase40++;
        if (n = 4, s->phase40 & 1)
            sp = n;
        else
            sp = 0;
        off = 0;
        i = 0;
        do {
            c = func_0c13c4bc(a, a->s30 / 2);
            if (!c)
                break;
            c->f52 = dx + a->f52;
            c->f56 = dy + a->f56;
            c->s30 = sp;
            c->b34 = (a->s30 + (short)off) & 31;
            i++;
            off += 8;
        } while (i < n);
        if (a->b1d2)
            a->s30 -= 2;
        else
            a->s30 += 2;
        a->s30 &= 31;
    }
}
