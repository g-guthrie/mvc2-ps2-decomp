/* Range test, dispatcher and the 16-actor chain constructor 0x0c156664..0x0c156760.
 * A label before the owner-pointer statement gives retail's r2/r3 choice. The
 * allocator-failure exit leaves the allocator null result in r0 by falling off
 * the end, as in tu_0c15632c. */
#include "objects.h"
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct LinkedActor *func_0c0374da(struct LinkedActor *,int,int);
extern void (*table_0c2506f0[])(struct Actor *);
void func_0c15672a(struct Actor *);
int func_0c156664(struct Actor *a)
{
    if (a->w130 == 0) {
        if (dat_0c2d9260.f98+-160.0f > a->f52) goto one; goto zero;
    } else if (a->f52 > dat_0c2d9260.f9c+160.0f) { one: return 1; }
    zero: return 0;
}
struct LinkedActor *func_0c1566a0(struct LinkedActor *owner)
{
    struct LinkedActor *c;
    struct LinkedActor *prev;
    int n=0;
    short *w;
    goto chain; chain:
    do {
        if (n==0) {
            if ((c=func_0c0374da(0,1,0))==0) goto fail;
            c->p20=0;
            prev=0;
        } else if ((c=func_0c0374da(c,1,2))==0) goto fail;
        w=&c->wcc.short_value;
        c->p16=func_0c15672a;
        c->p24=owner;
        c->w38=0x1703;
        c->b35=n;
        c->sdc.w130=c->p24->sdc.w130;
        n++;
        c->p20=prev;
        prev=c;
        *w=c->p24->sdc.w158.short_value;
    } while (n<16);
    return c;
fail:;
}
void func_0c15672a(struct Actor *a){table_0c2506f0[a->b4](a);}
