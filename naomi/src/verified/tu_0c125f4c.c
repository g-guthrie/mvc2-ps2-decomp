/* Partner-object dispatchers and the two identical reset handlers that pick
 * b1e9 from the b4c9 variant before re-entering state 29. */
#include "objects.h"
extern void (*table_0c24d7bc[])(struct Actor *, struct ActorSub2a4 *);
extern void (*table_0c24d7cc[])(struct Actor *);
extern void func_0c03f004(struct Actor *, struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
void func_0c125f4c(struct Actor *a)
{
    struct Actor *p = a->p1c8;
    struct ActorSub2a4 *s = &p->sub2a4;
    table_0c24d7bc[a->b6](a, s);
}
void func_0c125f68(struct Actor *a)
{
    struct Actor *p = a->p1c8;
    func_0c03f004(p, a);
}
void func_0c125f76(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}
void func_0c125f84(struct Actor *a)
{
    table_0c24d7cc[a->b1f7 & 63](a);
}
void func_0c125f9c(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 4; break;
    case 1: a->b1e9 = 3; break;
    case 2: a->b1e9 = 3; break;
    }
    func_0c045248(a, 29);
}
void func_0c125fcc(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 4; break;
    case 1: a->b1e9 = 3; break;
    case 2: a->b1e9 = 3; break;
    }
    func_0c045248(a, 29);
}
