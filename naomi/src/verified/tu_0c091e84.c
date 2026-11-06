#include "objects.h"


extern unsigned char func_0c046e7e(struct Actor *, void *, void *);
extern void func_0c047aac(struct Actor *, void *);
extern void func_0c045248(struct Actor *, int);
extern int dat_0c242cbc;
extern int dat_0c242ccc;
extern int dat_0c242ce0;

int func_0c091e84(struct Actor *a)
{
    int zero;

    if (func_0c046e7e(a, &dat_0c242cbc, a->x36c) == 0)
        return 0;
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x36c);
    zero = 0;
    a->b5 = zero;
    a->b7 = zero;
    a->b6 = zero;
    a->b1e9 = zero;
    func_0c045248(a, 21);
    return 1;
}

int func_0c091eec(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c242ccc, a->x374) == 0)
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
    a->b1e9 = 1;
    func_0c045248(a, 21);
    return 1;
}

int func_0c091f52(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c242ce0, a->x37c) == 0)
        return 0;
    func_0c047aac(a, a->x37c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 21);
    return 1;
}
