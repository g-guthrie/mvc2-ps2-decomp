#include "objects.h"
struct EntityMethods {
    void *pad[3];
    void (*slot3)(struct Actor *);
    void *pad4[3];
    void (*slot7)(struct Actor *);
    void (*slot8)(struct Actor *);
};

extern unsigned char func_0c0464c4(const struct Actor *);
extern unsigned char func_0c043a10(const struct Actor *);
extern signed char func_0c02a026(const struct Actor *);
extern void func_0c0453c4(struct Actor *, int);

void func_0c03b668(struct Actor *a)
{
    unsigned char direction;
    if (func_0c0464c4(a) != 0)
        return;
    if (a->b1f9 == 2 || (unsigned char)a->b1a3 == 1 || a->b19e == 0 || (a->b19e & 9) != 0)
        goto validate;
    a->b19e |= 8;
    direction = a->b1d2;
    if ((direction == 0 && a->f92 < 0.0f) ||
        (direction != 0 && a->f92 > 0.0f))
        a->f104 *= 4.0f;
validate:
    if (func_0c043a10(a) != 0)
        return;
    ((struct EntityMethods *)a->p428)->slot3(a);
    if (a->b200 == 0)
        return;
    if (a->b1d0 != 20)
        return;
    ((struct EntityMethods *)a->p428)->slot3(a);
}

void func_0c03b712(struct Actor *a)
{
    ((struct EntityMethods *)a->p428)->slot8(a);
}

void func_0c03b720(struct Actor *a)
{
    ((struct EntityMethods *)a->p428)->slot7(a);
}
