#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c241514[])(struct Actor *);
void func_0c079a20(struct Actor *a)
{
    (void)func_0c02a026(a);
    if (a->f41c > a->f56) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1fc = 0;
        func_0c0346da(a, 52);
        func_0c043324(a);
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->b1f9 = 0;
        func_0c02a0c4(a, 21, 14);
    }
}
void func_0c079a84(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c079aa6(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    table_0c241514[a->b6](a);
}
