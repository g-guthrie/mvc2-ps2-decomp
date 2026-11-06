#include "objects.h"

extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c0dc968(struct Actor *a)
{
    if (a->f56 < a->f41c) {
        a->b6 = a->b6 + 1;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f56 = a->f41c;
        func_0c02a0c4(a, 21, 5);
        func_0c043324(a);
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
}

void func_0c0dc9ec(struct Actor *a)
{
    a->f92 += a->f104;
    a->f52 += a->f92;
    if (func_0c02a026(a) >= 0)
        return;
    func_0c0437b8(a);
}
