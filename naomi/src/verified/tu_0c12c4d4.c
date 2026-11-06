/* Four actor callbacks and a shared pool. Writing f56 >= f41c selects the
 * retail float operand-load order before the state transition. */
#include "objects.h"
typedef void (*Handler_074798)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern Handler_074798 table_0c24ddbc[];
extern Handler_074798 table_0c24ddc8[];

void func_0c12c4d4(struct Actor *a)
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

void func_0c12c558(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c12c57a(struct Actor *a)
{
    table_0c24ddbc[a->b6](a);
}

void func_0c12c58c(struct Actor *a)
{
    table_0c24ddc8[a->b7](a);
}
