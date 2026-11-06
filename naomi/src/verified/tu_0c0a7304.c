/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *, void *, void *);
extern void func_0c047aac(struct Actor *, void *);
extern void func_0c045248(struct Actor *, int);
extern int dat_0c24026c;
extern int dat_0c244336;
extern int dat_0c244346;

int func_0c0a7304(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c244336, a->x374) == 0)
        return 0;
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x374);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0a736a(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c244346, a->x37c) == 0)
        return 0;
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x37c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 3;
    func_0c045248(a, 21);
    return 1;
}
