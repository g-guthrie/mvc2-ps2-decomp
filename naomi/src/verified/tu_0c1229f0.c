/* Three actor phase callbacks and their shared literal pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
void func_0c1229f0(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b6++;
        a->f92 = 0.5739339f;
        a->f104 = 0.0390625f;
        a->f96 = 16.339285f;
        a->f108 = -0.90401781f;
        if (a->w130) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        func_0c02a0c4(a, 18, 1);
    }
}
void func_0c122a58(struct Actor *a, struct ActorSub2a4 *sub)
{
    func_0c02a026(a);
    if (!(a->b141 & 1)) {
        if (a->b141 & 2) {
            a->b141 &= (unsigned char)~2;
            sub->b7 = 1;
        }
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (!(a->f41c < a->f56)) {
            a->b6++;
            a->f56 = a->f41c;
            a->f52 = sub->w4;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            func_0c043324(a);
            func_0c02a0c4(a, 1, 5);
        }
    }
}
void func_0c122b1c(struct Actor *a, struct ActorSub2a4 *sub)
{
    if (func_0c02a026(a) < 0) {
        sub->b6 = 0;
        a->b5++;
    }
}
