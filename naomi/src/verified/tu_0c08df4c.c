#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c242910[])(struct Actor *, void *);
void func_0c08e008(struct Actor *, void *);
void func_0c08df4c(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f41c < a->f56)) {
        a->f56 = a->f41c;
        a->b6++;
        a->b1f9 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c043324(a);
        a->b159 = 22;
        a->b158 = 5;
        func_0c02a0c4(a, a->b159, a->b158);
    }
}
void func_0c08dfe6(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c08e008(struct Actor *a, void *context)
{
    float boundary;
    boundary = dat_0c2d9260.f88 + 53.333333023f;
    if (a->f52 < boundary) a->f52 = boundary;
    boundary = dat_0c2d9260.f8c - 53.333333023f;
    if (a->f52 > boundary) a->f52 = boundary;
}
void func_0c08e036(struct Actor *a, void *context)
{
    table_0c242910[a->b6](a, context);
    func_0c08e008(a, context);
}
