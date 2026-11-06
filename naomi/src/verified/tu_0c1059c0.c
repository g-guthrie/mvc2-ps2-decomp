#include "objects.h"


extern unsigned char func_0c046e7e(struct Actor *, void *, void *);
extern void func_0c047aac(struct Actor *, void *);
extern void func_0c045248(struct Actor *, int);
extern int dat_0c24b3e8;
extern int dat_0c24b3f8;
extern int dat_0c24b408;

int func_0c1059c0(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c24b3e8, a->x36c) == 0)
        return 0;
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x36c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 21);
    return 1;
}

int func_0c105a26(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c24b3f8, a->x374) == 0)
        return 0;
    func_0c047aac(a, a->x374);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 12;
    func_0c045248(a, 21);
    return 1;
}

int func_0c105a6c(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c24b408, a->x37c) == 0)
        return 0;
    func_0c047aac(a, a->x37c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}
