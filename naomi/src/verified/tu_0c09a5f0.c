#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern int func_0c146bfc(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c09a5f0(struct Actor *a, char *flag)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        flag[3] = 0;
        if (!func_0c146bfc(a, 0)) {
            func_0c0437b8(a);
            return;
        }
        a->b27b = 0;
        a->b27a = 16;
    }
}

void func_0c09a640(struct Actor *a, char *flag)
{
    func_0c02a026(a);
    if (flag[0] == 0) {
        func_0c0437b8(a);
        return;
    }
    if (flag[3]) {
        a->b6 += 2;
        a->f96 = 10.0f;
        a->f108 = -0.80357140303f;
        func_0c02a0c4(a, 21, 2);
    }
}

void func_0c09a69a(struct Actor *a)
{
    if (a->b141 == 0)
        func_0c02a026(a);
    if (--a->s28 == 0)
        a->b6++;
}
