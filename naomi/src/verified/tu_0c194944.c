#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c257cc4[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a18c(struct Actor *, int, int, int);
extern void func_0c037688(struct Actor *);

void func_0c194944(struct Actor *a)
{
    struct Actor *b = a->p20;
    float amount;
    float *src = &b->f136;
    float *dst = &a->f136;
    a->b12c = 0;
    if (b->b4 >= 2) {
        a->b4++;
        return;
    }
    amount = *src - *dst;
    if (amount > 0.0f) {
        amount = amount / 16.0f;
        if (amount < 0.0f)
            amount = 0.0f;
        if (amount > 3.0f) {
            a->b4++;
            return;
        }
        func_0c02a18c(a, 23, 0, (int)amount);
    }
    a->b12c = 1;
}

void func_0c1949aa(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b4++;
}

void func_0c1949ca(struct Actor *a)
{
    table_0c257cc4[a->b32](a);
}

void func_0c1949de(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c1949ec(struct Actor *a)
{
    func_0c037688(a);
}
