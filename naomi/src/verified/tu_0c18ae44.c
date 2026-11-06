#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1899e8(struct Actor *, struct Actor *, int);

void func_0c18ae44(struct Actor *a, struct Actor *b)
{
    if (func_0c02a026(a) < 0)
        func_0c1899e8(a, b, 11);
}

void func_0c18ae6e(struct Actor *a, struct Actor *b)
{
    if (a->b6 == 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c02a026(a);
        if (a->f56 < b->f41c) {
            a->b6 = a->b6 + 1;
            a->f56 = b->f41c;
            func_0c02a0c4(a, 1, 3);
        }
    } else if (func_0c02a026(a) < 0) {
        func_0c1899e8(a, b, a->b7);
    }
}
