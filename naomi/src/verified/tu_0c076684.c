#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char func_0c046dd0(struct Actor *, int);
extern void func_0c047aac(struct Actor *, unsigned char *);
extern void func_0c045248(struct Actor *, int);
extern unsigned char dat_0c241310[], dat_0c241334[];
int func_0c076684(struct Actor *a)
{
    char saved;
    struct ActorSub2a4Extended *sub;
    if (!func_0c046e7e(a, dat_0c241310, a->x38c)) return 0;
    if (a->b1f9 == 2) {
        if (a->b1d4) return 0;
        if (!a->b1fc) a->b1d4++;
    }
    func_0c047aac(a, a->x38c);
    a->b1a3 += a->b1fe * 2;
    saved = a->b1a3;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 4;
    sub = (struct ActorSub2a4Extended *)&a->sub2a4;
    sub->w42 = a->w1fa;
    func_0c045248(a, 29);
    a->b1a3 = saved;
    return 1;
}
int func_0c07671a(struct Actor *a)
{
    if (!func_0c046dd0(a, 5)) return 0;
    a->b1e9 = 5;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}
int func_0c076754(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c241334, a->x394)) goto fail;
    if (!*a->p40c) {
fail:
        return 0;
    }
    a->b1a3 = 1;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 6;
    func_0c045248(a, 29);
    return 1;
}
