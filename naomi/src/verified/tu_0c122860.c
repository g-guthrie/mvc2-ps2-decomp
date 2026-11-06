/* Three actor motion callbacks and their shared literal pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1bc740(struct Actor *, int, int);
void func_0c122860(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f92 * a->f104 < 0.0f))
        func_0c0437b8(a);
}
void func_0c1228c2(struct Actor *a, struct ActorSub2a4 *sub)
{
    a->b6++;
    sub->w4 = (short)a->f52;
    sub->b6 = 1;
    a->b12c = 1;
    if (!a->w130)
        a->f52 += 173.33333f;
    else
        a->f52 -= 173.33333f;
    a->f56 += 480.0f;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = -4.47916651f;
    a->f96 = -5.35714245f;
    if (a->w130)
        a->f92 = -a->f92;
    func_0c02a0c4(a, 18, 0);
    func_0c1bc740(a, 0, 0);
}
void func_0c122958(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f56 > a->f41c + 205.71428f)) {
        a->f56 = a->f41c + 205.71428f;
        a->b6++;
        a->s28 = 64;
    }
}
