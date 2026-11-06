#include "objects.h"

extern int func_0c1335f8(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c061360(struct Actor *a)
{
    struct ActorSub2a4 *s;

    s = &a->sub2a4;
    if (a->b141) {
        a->b141 = 0;
        func_0c1335f8(a, 1, 0);
        func_0c0344a0(a, 30);
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c)
        a->f56 = a->f41c;
    if (func_0c02a026(a) >= 0)
        return;
    a->b7++;
    ((unsigned char *)s)[12] = 0;
    if (a->b1d2)
        a->f92 = -1.66666663f;
    else
        a->f92 = 1.66666663f;
    if (a->b1d2)
        a->f104 = 0.02604166605f;
    else
        a->f104 = -0.02604166605f;
    a->f96 = 7.5f;
    a->f108 = -0.401785702f;
    func_0c02a0c4(a, 21, 4);
}
