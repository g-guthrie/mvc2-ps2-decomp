#include "objects.h"

struct C1d2 { unsigned char pad[0x1d2]; char b1d2; };

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
typedef void (*Handler_0c0778b0)(struct Actor *);
extern Handler_0c0778b0 table_0c241448[];

void func_0c077992(struct Actor *a);

void func_0c0778b0(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        func_0c02a0c4(a, 2, 2);
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
    }
}

void func_0c077922(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c077944(struct Actor *a)
{
    table_0c241448[a->b6](a);
}

void func_0c077956(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141)
        return;
    a->b6++;
    a->f92 = ((struct C1d2 *)a)->b1d2 ? -20.0f : 20.0f;
    func_0c077992(a);
}

void func_0c077992(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c02a0c4(a, 2, 3);
    }
}
