/* Three functions sharing the literal pool at 0x0c113448. */
#include "objects.h"

extern unsigned char dat_0c24c160[];
extern unsigned char dat_0c24c170[];
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char func_0c046dd0(struct Actor *, int);
extern void func_0c045248(struct Actor *, int);

int func_0c11334c(struct Actor *a)
{
    struct ActorSub2a4 *q = &a->sub2a4;

    if (!func_0c046e7e(a, dat_0c24c160, a->x37c))
        return 0;
    if (!*a->p40c)
        return 0;
    if (q->w4 != 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 29);
    return 1;
}

int func_0c1133a8(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24c170, a->x384))
        return 0;
    if (a->b1f9 != 2 || a->b1fc != 0) {
        /* Leave the scale counter unchanged in other states. */
    } else {
        if (a->b1d4 != 0) {
            return 0;
        } else {
            a->b1d4 = a->b1d4 + 1;
        }
    }
    if (!*a->p40c)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 3;
    func_0c045248(a, 29);
    return 1;
}

int func_0c11340e(struct Actor *a)
{
    if (!func_0c046dd0(a, 4))
        return 0;
    a->b1e9 = 4;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}
