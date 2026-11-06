/* Latches a throw request from the button words at 0x34a/0x34e and later
 * commits it: links the partner, plays its effect and snaps the effect to
 * the partner position. */
#include "objects.h"
/* Throw-input view of the per-actor record at actor+0x2a4 (see ActorSub2a4):
 * a timer word at 0, the held flag at 17 and the latched request at 18..22. */
struct ThrowInput { unsigned short w0; unsigned char pad2[15]; char b17; short s18; unsigned short w20; short s22; };
extern void func_0c04b02a(struct Actor *), func_0c1d1622(struct LinkedActorVec3 *, int);
void func_0c1768a0(struct Actor *a, struct ThrowInput *in)
{
    int mode;
    if ((signed char)a->p1c8->b23a >= 1)
        return;
    if (!(a->w34a & 0x3c00))
        return;
    if (a->w34e & 0x300)
        mode = 0;
    else if (a->w34e & 0x60)
        mode = 1;
    else
        return;
    a->p1c8->b23a += 2;
    in->s22 = mode;
    in->w20 = a->w34a;
    in->s18 = 1;
}
void func_0c1768f8(struct Actor *self, struct Actor *a, struct ThrowInput *in)
{
    struct LinkedActorVec3 v;
    char held;
    if (!in->s18)
        return;
    in->s18 = 0;
    held = 0;
    if (in->w0 < 10) {
        held = 1;
        if (in->w20 & 0xc00)
            in->w20 ^= 0xc00;
    }
    in->b17 = held;
    a->p1c8->p1b4 = a;
    a->p1c8->b1a1 = 56;
    func_0c04b02a(a);
    if (!a->p1c8->w420)
        return;
    v = *(struct LinkedActorVec3 *)&a->p1c8->f52;
    v.y = a->p1c8->f41c;
    func_0c1d1622(&v, a->p1c8->b2);
    self->b5 = 3;
    a->b6 = 11;
}
