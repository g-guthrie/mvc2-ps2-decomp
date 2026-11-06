/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern void func_0c02a684(struct Src_0c1abc64 *, int, int, int);

void func_0c1aebb8(struct Host_0c1abc64 *a, struct Src_0c1abc64 *b, struct Item_0c1abc64 *c)
{
    struct Sub_0c1abc64 *s = &a->sub;

    do {
        int m;

        s->b4 = c->b0;
        m = c->b2 + b->b37 * 87;
        func_0c02a684(b, c->b1, m, c->b3);
        if (c->n == 1)
            s->b5 = 0;
        else
            s->b5 = 1;
        c += c->n;
    } while (s->b4 == 0);
    s->p = c;
}

int func_0c1aec28(struct Host_0c1abc64 *a, struct Src_0c1abc64 *b)
{
    struct Sub_0c1abc64 *s = &a->sub;
    int r = 1;

    if (--s->b4 == 0) {
        if (s->b5 != 0)
            r = 0;
        func_0c1aebb8(a, b, s->p);
    }
    return r;
}
