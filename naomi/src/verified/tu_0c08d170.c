/* Four actor callbacks and their shared pool. The first resets velocity on
 * a nonnegative callback result; the final dispatcher indexes the b7 state. */
#include "objects.h"
typedef void (*Handler_08d170)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern Handler_08d170 table_0c242850[];

void func_0c08d170(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        return;
    a->b7++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f108 = -0.80357140303f;
    a->b1fc = 2;
    a->b159 = 21;
    a->b158 = 12;
    func_0c02a0c4(a, a->b159, a->b158);
}

void func_0c08d202(struct Actor *a)
{
    func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c < a->f56)
        return;
    a->b7++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    func_0c043324(a);
    a->b159 = 21;
    a->b158 = 13;
    func_0c02a0c4(a, a->b159, a->b158);
}

void func_0c08d27a(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c08d29c(struct Actor *a)
{
    table_0c242850[a->b7](a);
}
