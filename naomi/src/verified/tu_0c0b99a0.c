#include "objects.h"

extern unsigned char func_0c046e7e(struct Actor *, void *, void *);
extern void func_0c045248(struct Actor *, int);
extern int dat_0c2453d4;
extern int dat_0c2453e4;
extern int dat_0c2453f4;
extern int dat_0c245404;
extern int dat_0c245414;

int func_0c0b99a0(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c2453d4, a->x36c) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 1;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b99dc(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c2453e4, a->x374) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b9a18(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c2453f4, a->x37c) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 3;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b9a54(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c245404, a->x384) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 4;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b9a90(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c245414, a->x38c) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 5;
    func_0c045248(a, 21);
    return 1;
}
