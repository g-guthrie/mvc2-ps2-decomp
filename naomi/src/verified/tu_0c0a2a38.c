/* Fresh closed span at 0x0c0a2a38 (384 bytes): code 0c0a2a38/132 and
 * 0c0a2abc/210, followed by the shared 42-byte literal/data pool. */
#include "objects.h"

struct Vec3_0c0a2a38 { float x, y, z; };

extern unsigned char dat_0c2d9260[];
extern void func_0c025900(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c1ceab2(struct Actor *, struct Vec3_0c0a2a38 *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c03489c(struct Actor *);

void func_0c0a2a38(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;

    if (a->f56 < a->f41c) {
        a->b6 = a->b6 + 1;
        a->b1f9 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        if (a->b1d2)
            a->f92 = -12.85714245f;
        else
            a->f92 = 12.85714245f;
        a->f56 = a->f41c;
    }
}

void func_0c0a2abc(struct Actor *a)
{
    struct Actor *o;
    struct Vec3_0c0a2a38 v;

    if (a->b141 != 2) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }

    if (a->b141 == 1) {
        func_0c025900(a, 0, 0);
        v.x = 0.0f;
        v.y = 0.0f;
        func_0c1ceab2(a, &v, 2);
        a->b141 = 0;
        o = a->p1c8;
        o->p1b4 = a;
        o->b1d2 = a->b1d2;
        o->b1a1 = 34;
        o->b1f6 = 3;
        dat_0c2d9260[5] = 2;
        dat_0c2d9260[6] = 1;
        func_0c03489c(o);
        return;
    }
    if (func_0c02a026(a) < 0) {
        a->b1f9 = 1;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}
