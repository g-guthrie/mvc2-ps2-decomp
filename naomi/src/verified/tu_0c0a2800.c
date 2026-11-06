/* Fresh closed span at 0x0c0a2800 (276 bytes), with five reviewed pool
 * ranges through 0x0c0a2914. Those pool bytes are currently shared by
 * rest_028 and bulk_035; unit_spans found all readers inside this span. */
#include "objects.h"

extern void func_0c02a026(struct Actor *);

void func_0c0a2800(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f96 < 0.0f) {
        a->b6 = a->b6 + 1;
        a->b141 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f108 = -1.6071429f;
    }
    if (a->b141 != 1)
        func_0c02a026(a);
}

void func_0c0a2876(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->b6 = a->b6 + 1;
        a->b1f9 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        if (a->b1d2)
            a->f92 = -12.857142448425293f;
        else
            a->f92 = 12.857142448425293f;
        a->f56 = a->f41c;
    }
}
