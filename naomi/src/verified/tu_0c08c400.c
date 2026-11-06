#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void (*table_0c242784[])(struct Actor *);
extern void (*table_0c242790[])(struct Actor *);
void func_0c08c462(struct Actor *);
void func_0c08c400(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c08c422(struct Actor *a) { table_0c242784[a->b6](a); }
void func_0c08c434(struct Actor *a)
{
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b6++;
    a->f92 = a->b1d2 ? -12.5f : 12.5f;
    func_0c08c462(a);
}
void func_0c08c462(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->b159 = 2;
        a->b158 = 3;
        func_0c02a0c4(a, a->b159, a->b158);
    }
}
void func_0c08c4d4(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->b141) a->f92 = 0;
    a->f104 = 0;
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}
void func_0c08c540(struct Actor *a) { table_0c242790[a->b6](a); }
