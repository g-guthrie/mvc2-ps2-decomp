/* Three functions sharing the literal pool at 0x0c07436a. */
#include "objects.h"

struct Vec_tu1_09 { float x, y, z; };

struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };

extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *a);
extern void func_0c0432ca(struct Actor *a);
extern void func_0c02a0c4(struct Actor *a, int b, int c);
extern void func_0c02a026(struct Actor *a);
extern void func_0c0429a4(struct Actor *a, struct Vec_tu1_09 *v, int m);
extern void func_0c191980(struct Actor *a, int n);

void func_0c074228(struct Actor *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b7++;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 0);
}

void func_0c0742ac(struct Actor *a)
{
    struct Vec_tu1_09 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141 & 2) {
        a->b7++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 3.3333333f;
        v.y = 102.85714263916016f;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c074316(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141 & 1) {
        a->b6++;
        a->b7 = 0;
        a->f92 = -40.0f;
        if (a->b1d2)
            a->f92 = -a->f92;
        func_0c191980(a, 5);
    }
}
