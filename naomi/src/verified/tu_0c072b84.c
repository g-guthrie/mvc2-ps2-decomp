#include "objects.h"
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
void func_0c072be2(struct Actor *);
void func_0c072b84(struct Actor *a)
{
    float offset, speed;
    a->b7++;
    a->b1f9 = 2;
    a->s28 = 32;
    a->f96 = 21.42857f;
    a->f108 = -0.66964281f;
    offset = -213.33333f;
    speed = 3.3333333f;
    if (a->b2) { offset = 213.33333f; speed = -3.3333333f; }
    a->f52 += offset;
    a->f92 = speed;
    a->f104 = 0;
    func_0c02a0c4(a, 18, 0);
    func_0c072be2(a);
}
void func_0c072be2(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        if (func_0c044e52(a)) {
            a->b6++;
            a->b7 = 0;
            a->f52 -= a->f92;
            a->b1f9 = 0;
            func_0c02a0c4(a, 18, 2);
            func_0c043324(a);
        }
    } else {
        a->b7++;
        func_0c02a0c4(a, 18, 1);
    }
}
