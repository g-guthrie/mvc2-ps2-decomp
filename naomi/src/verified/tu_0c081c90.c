#include "objects.h"


extern unsigned char func_0c046e7e(struct Actor *, void *, void *);
extern void func_0c047aac(struct Actor *, void *);
extern void func_0c045248(struct Actor *, int);
extern int dat_0c241ec8;
extern int dat_0c241ed8;
extern int dat_0c241eec;

int func_0c081c90(struct Actor *a)
{
    {
        struct ActorSub2a4 *s;

        s = &a->sub2a4;
        if (func_0c046e7e(a, &dat_0c241ec8, a->x384) == 0)
            return 0;
        if (((unsigned char *)s)[14])
            return 0;
    }
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x384);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}

int func_0c081d0e(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c241ed8, a->x38c) == 0)
        return 0;
    func_0c047aac(a, a->x38c);
    a->b1f2 = 3;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 21);
    return 1;
}

int func_0c081d5a(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c241eec, a->x394) == 0)
        return 0;
    func_0c047aac(a, a->x394);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 3;
    func_0c045248(a, 21);
    return 1;
}
