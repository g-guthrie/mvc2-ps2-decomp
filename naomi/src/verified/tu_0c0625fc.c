#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void (*table_0c240130[])(struct Actor *);

void func_0c0625fc(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6 = 3;
        a->b7 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c043324(a);
        func_0c02a0c4(a, 22, 12);
    }
}

void func_0c06267e(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    table_0c240130[a->b7](a);
}
