#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23fc30[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c05caf8(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b1f9 = 2;
        a->f92 = 5.41666651f;
        a->f104 = 0.0f;
        if (a->b1d2 == 0) {
            a->f92 = -5.41666651f;
            a->f104 = -0.0f;
        }
        a->f96 = 0.0f;
        a->f108 = 0.0f;
    }
}
void func_0c05cb50(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
}
void func_0c05cba4(struct Actor *a) { table_0c23fc30[a->b6](a); }
void func_0c05cbb6(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b1f9 = 0;
        a->f92 = 6.66666651f;
        a->f104 = 0.0f;
        if (a->b1d2 == 0) {
            a->f92 = -6.66666651f;
            a->f104 = -0.0f;
        }
        a->f96 = 6.428571224213f;
        a->f108 = -0.80357140303f;
    }
}
