#include "objects.h"

extern int func_0c04e78e(struct Actor *, int);
extern int func_0c04e82a(struct Actor *, void *);
extern void func_0c04e6b2(struct Actor *, void *, int);

int func_0c050d80(struct Actor *a, void *b)
{
    unsigned int control_bits;

    if (!func_0c04e78e(a, 2))
        return 0;
    if (!func_0c04e82a(a, b))
        return 0;
    func_0c04e6b2(a, b, 0);
    func_0c04e6b2(a, b, 1);
    goto t0; t0:
    if (a->parameter4b4.integer)
        control_bits = 0x100;
    else
        control_bits = 0x200;
    func_0c04e6b2(a, b, 1);
    control_bits |= ((unsigned int)a->parameter4b4.integer << 8) & 0x3c00;
    if ((unsigned short)control_bits & 0x0c00)
        control_bits ^= a->b1d2 * 0xc00;
    a->w4dc = control_bits;
    return 0;
}

int func_0c050e06(struct Actor *a, void *b)
{
    unsigned int control_bits;

    if (!func_0c04e78e(a, 2))
        return 0;
    if (!func_0c04e82a(a, b))
        return 0;
    func_0c04e6b2(a, b, 0);
    func_0c04e6b2(a, b, 1);
    goto t1; t1:
    if (a->parameter4b4.integer)
        control_bits = 0x20;
    else
        control_bits = 0x40;
    func_0c04e6b2(a, b, 1);
    control_bits |= ((unsigned int)a->parameter4b4.integer << 8) & 0x3c00;
    if ((unsigned short)control_bits & 0x0c00)
        control_bits ^= a->b1d2 * 0xc00;
    a->w4dc = control_bits;
    return 0;
}
