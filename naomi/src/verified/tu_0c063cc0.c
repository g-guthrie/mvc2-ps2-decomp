#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c03489c(struct Actor *);
void func_0c063cc0(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (func_0c044e52(a)) func_0c044f1c(a);
}
void func_0c063d20(struct Actor *a)
{
    struct Actor *child;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->f92 = 10.0f;
        a->f104 = 0;
        a->f96 = 21.42857f;
        a->f108 = -1.07142854f;
        if (a->w130) a->f92 = -a->f92;
        func_0c02a0c4(a, 15, 4);
        child = a->p1c8;
        child->p1b4 = a;
        child->b1f6 = 2;
        child->b1a1 = 33;
        child->b1d2 = a->b1d2 ^ 1;
        func_0c025900(a, 0, 0);
        func_0c03489c(a);
    }
}
