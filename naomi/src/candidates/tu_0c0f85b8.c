/* Candidate: one scratch register (r1 vs r2) for the 0x2a9 byte test differs; size exact. */
#include "objects.h"
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a684(struct Actor *, int, int, int);
void func_0c0f85b8(struct Actor *a);

#define E(a) ((union ActorSubEffectState *)&(a)->sub2a4)
#define B(a) ((struct ActorSubByteState *)&(a)->sub2a4)

void func_0c0f85b8(struct Actor *a)
{
    int z = 0;
    if (a->sub2a4.b0 && *(unsigned short *)&a->b158 != 0x1600) {
        a->sub2a4.b0 = z;
        func_0c02a39a(a, 0);
    }
    a->w3e4 = 2;
    if (!E(a)->bytes[4]) {
        if (!E(a)->bytes[5]) return;
        E(a)->bytes[4]++;
        a->b19e = z;
        {struct ActorSub2a4 *s = &a->sub2a4; s->b6 = z; s->b7 = z;}
    }
    if (!E(a)->bytes[4]) return;
    if (a->w420 == 0 || (E(a)->bytes[5] == 0 && (E(a)->bytes[6] != 0 || (a->b14a & 0xe0) == 0))) {
        {union ActorSubEffectState *e = E(a); e->bytes[5] = z; e->bytes[4] = z;}
        a->b205 = z;
        func_0c02a39a(a, 0);
        return;
    }
    if (a->b19e) {
        a->b205 = z;
        B(a)->b6 = -1;
    }
    B(a)->b7++;
    B(a)->b7 &= 7;
    func_0c02a684(a, 0, (char)B(a)->b7 + a->b37 * 10 + 2, 1);
}
