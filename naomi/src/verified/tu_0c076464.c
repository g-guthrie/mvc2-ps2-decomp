#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c047aac(struct Actor *, unsigned char *);
extern unsigned char dat_0c2412d0[], dat_0c2412e0[];
int func_0c076464(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2412d0, a->x37c) || !*a->p40c) return 0;
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4) return 0;
        a->b1d4++;
    }
    a->b1a3 = 1;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 29);
    return 1;
}
int func_0c0764d0(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    if (!func_0c046e7e(a, dat_0c2412e0, a->x36c) || *(char *)&sub->s10) return 0;
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4) return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x36c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}
