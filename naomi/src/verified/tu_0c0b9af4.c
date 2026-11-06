#include "objects.h"


extern unsigned char func_0c046e7e(struct Actor *, void *, void *);
extern void func_0c045248(struct Actor *, int);
extern int dat_0c245424;
extern int dat_0c245434;
extern int dat_0c245444;
extern int dat_0c245454;
extern int dat_0c245464;

int func_0c0b9af4(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c245424, a->x394) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 6;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b9b30(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c245434, a->x39c) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 7;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b9b6c(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c245444, a->x3a4) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 8;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b9ba8(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c245454, a->x3ac) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 9;
    func_0c045248(a, 21);
    return 1;
}

int func_0c0b9be4(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c245464, a->x3b4) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 10;
    func_0c045248(a, 21);
    return 1;
}
