#include "objects.h"

extern int func_0c04e78e(struct Actor *, int);
extern int func_0c04e82a(struct Actor *, void *);
extern void func_0c04e6b2(struct Actor *, void *, int);

int func_0c050bac(struct Actor *a, void *b)
{
    unsigned short m;

    if (!func_0c04e78e(a, 2))
        return 0;
    if (!func_0c04e82a(a, b))
        return 0;
    goto L1; L1: func_0c04e6b2(a, b, 0);
    func_0c04e6b2(a, b, 1);
    if (a->parameter4b4.integer)
        m = 0x100;
    else
        m = 0x200;
    if (a->w4ae & m)
        a->w4ae ^= m;
    else
        a->w4dc = m;
    return 0;
}

int func_0c050c10(struct Actor *a, void *b)
{
    unsigned short m;

    if (!func_0c04e78e(a, 2))
        return 0;
    if (!func_0c04e82a(a, b))
        return 0;
    goto L2; L2: func_0c04e6b2(a, b, 0);
    func_0c04e6b2(a, b, 1);
    if (a->parameter4b4.integer)
        m = 0x20;
    else
        m = 0x40;
    if (a->w4ae & m)
        a->w4ae = m;
    else
        a->w4dc = m;
    return 0;
}
