/* Four actor callbacks and a shared pool. Writing f56 >= f41c selects the
 * retail float operand-load order before the state transition. */
#include "objects.h"
typedef void (*Handler_074798)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern Handler_074798 table_0c2411e8[];
extern Handler_074798 table_0c2411f4[];

void func_0c074798(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 >= a->f41c)
        return;
    a->b6++;
    a->b7 = 0;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c043324(a);
    func_0c02a0c4(a, 22, 3);
}

void func_0c07481c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c07483e(struct Actor *a)
{
    table_0c2411e8[a->b6](a);
}

void func_0c074850(struct Actor *a)
{
    table_0c2411f4[a->b7](a);
}
