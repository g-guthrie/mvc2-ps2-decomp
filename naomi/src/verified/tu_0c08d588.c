/* Four actor callbacks and their shared pool. Writing f41c < f56 makes SHC
 * load the operands in the same order as retail. */
#include "objects.h"
typedef void (*Handler_08d588)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern Handler_08d588 table_0c2428dc[];
extern Handler_08d588 table_0c2428f4[];

void func_0c08d588(struct Actor *a)
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

void func_0c08d600(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c08d622(struct Actor *a)
{
    table_0c2428dc[a->b7](a);
}

void func_0c08d634(struct Actor *a)
{
    table_0c2428f4[a->b6](a);
}
